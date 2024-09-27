#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forward_list.h"

struct HashTable{

    int table_size;
    int n_elements;
    HashFunction hash_fn;
    CmpFunction cmp_fn;

    ForwardList** item_list;
};

struct HashTableIterator{
    
    HashTable* ht;
    Node* cur_node;
    int cur_bucket;
    int cur_element;
};

HashTableItem* hash_table_item_construct(HashTable* h, void* key, void* val){

    HashTableItem* item = (HashTableItem*)calloc(1, sizeof(HashTableItem));

    item->key = key;
    item->val = val;

    return item;
}

void hash_table_item_destroy(HashTableItem* item){

    free(item->key);
    free(item->val);
    free(item);
    item = NULL;
}

HashTable *hash_table_construct(int table_size, HashFunction hash_fn, CmpFunction cmp_fn){

    HashTable* ht = (HashTable*)calloc(1, sizeof(HashTable));

    ht->table_size = table_size;
    ht->hash_fn = hash_fn;
    ht->cmp_fn = cmp_fn;

    ht->item_list = (ForwardList**)calloc(table_size, sizeof(ForwardList*));

    for(int i=0; i<ht->table_size; i++){
        ht->item_list[i] = NULL;
    }

    return ht;
}

void hash_table_destroy(HashTable *h){

    HashTableIterator* it = hash_table_iterator(h);
    
    while(!hash_table_iterator_is_over(it)){
        hash_table_item_destroy(hash_table_iterator_next(it));
    }

    hash_table_iterator_destroy(it);

    for(int i=0; i<h->table_size; i++){
        if(h->item_list[i] != NULL){
            forward_list_destroy(h->item_list[i]); 
        }
    }

    free(h->item_list);
    h->item_list = NULL;

    free(h);
    h = NULL;
}

void *hash_table_get(HashTable *h, void *key){

    int bucket = h->hash_fn(h, key);

    if(h->item_list[bucket] == NULL)
        return NULL;

    ListIterator* it = list_iterator_construct(h->item_list[bucket]);
    HashTableItem* item;

    while(!list_iterator_is_over(it)){

        item = (HashTableItem*)list_iterator_next(it);
        if(!h->cmp_fn(item->key, key)){

            list_iterator_destroy(it);        
            return item->val;
        }
    }

    list_iterator_destroy(it);
    return NULL;
}

void hash_table_set(HashTable *h, void *key, void *val){

    int bucket = h->hash_fn(h, key);

    if(h->item_list[bucket] == NULL)
        h->item_list[bucket] = (ForwardList*)calloc(1, sizeof(ForwardList));

    forward_list_push_front(h->item_list[bucket], hash_table_item_construct(h, key, val));
    h->n_elements++;
}

void *hash_table_pop(HashTable *h, void *key){

    int bucket = h->hash_fn(h, key);
    void* value;

    if(h->item_list[bucket] == NULL)
        return NULL;

    ListIterator* it = list_iterator_construct(h->item_list[bucket]);
    HashTableItem* item;

    while(!list_iterator_is_over(it)){

        item = (HashTableItem*)list_iterator_next(it);
        if(!h->cmp_fn(item->key, key)){

            list_iterator_destroy(it);
            forward_list_remove(h->item_list[bucket], item);
            h->n_elements--;
            return item->val;

            //hash_table_item_destroy(item); -> o item ainda vai precisar ser liberado onde for popado
        }
    }

    list_iterator_destroy(it);
    return NULL;
}

int hash_table_size(HashTable *h){
    return h->table_size;
}

int hash_table_num_elems(HashTable *h){
    return h->n_elements;
}

HashTableIterator *hash_table_iterator(HashTable *h){
    
    HashTableIterator* it = calloc(1, sizeof(HashTableIterator));

    it->ht = h;

    for(int i=0; i<h->table_size; i++){

        if(h->item_list[i] != NULL){

            it->cur_bucket = i;
            it->cur_node = forward_list_get(h->item_list[i], 0);
            break;
        }
    }

    return it;
}

int hash_table_iterator_is_over(HashTableIterator *it){
    
    return (it->cur_element >= it->ht->n_elements);
}

HashTableItem *hash_table_iterator_next(HashTableIterator *it){
    
    HashTableItem* aux = node_value(it->cur_node);

    if(node_next(it->cur_node) != NULL){
        it->cur_node = node_next(it->cur_node);
    }

    else{

        it->cur_bucket++;

        while(it->cur_bucket < it->ht->table_size){

            if(it->ht->item_list[it->cur_bucket] != NULL){

                it->cur_node = forward_list_get(it->ht->item_list[it->cur_bucket], 0);
                break;
            }

            it->cur_bucket++;
        }
    }

    it->cur_element++;

    return aux;
}

void hash_table_iterator_destroy(HashTableIterator *it){
    
    free(it);
    it = NULL;
}
