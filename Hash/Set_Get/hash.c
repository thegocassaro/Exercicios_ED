#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HashTable{

    int table_size;
    int n_elements;
    HashFunction hash_fn;
    CmpFunction cmp_fn;

    HashTableItem** item_list;
};

// struct HashTableIterator{
    
// };

HashTable *hash_table_construct(int table_size, HashFunction hash_fn, CmpFunction cmp_fn){

    HashTable* ht = (HashTable*)calloc(1, sizeof(HashTable));

    ht->table_size = table_size;
    ht->hash_fn = hash_fn;
    ht->cmp_fn = cmp_fn;

    ht->item_list = (HashTableItem*)calloc(table_size, sizeof(HashTableItem));

    for(int i=0; i<table_size; i++){

        ht->item_list[i].key = NULL;
        ht->item_list[i].val = NULL;
    }

    return ht;
}

void hash_table_destroy(HashTable *h){

    for(int i=0; i<h->table_size; i++){

        if(h->item_list[i].key != NULL){

            printf("%s %d\n", (char*)h->item_list[i].key, *(int*)h->item_list[i].val);

            free(h->item_list[i].key);
            free(h->item_list[i].val);

            h->item_list[i].key = NULL;
            h->item_list[i].val = NULL;
        }

    }

    free(h->item_list);
    h->item_list = NULL;

    free(h);
    h = NULL;
}

void *hash_table_get(HashTable *h, void *key){

    int bucket = h->hash_fn(h, key);

    if(h->item_list[bucket].key == NULL)
        return NULL;

    char* k1 = (char*)h->item_list[bucket].key;
    char* k2 = (char*)key;

    if(!strcmp(k1, k2))
        return h->item_list[bucket].val;

    return NULL;
}

void *hash_table_set(HashTable *h, void *key, void *val){

    int bucket = h->hash_fn(h, key);
    int* v = NULL;

    if(h->item_list[bucket].key != NULL)
        v = (int*)h->item_list[bucket].val;
    
    else
        h->n_elements++;

    h->item_list[bucket].key = key;
    h->item_list[bucket].val = val;

    return v;
}

void *hash_table_pop(HashTable *h, void *key){

    int bucket = h->hash_fn(h, key);
    int* v = NULL;
    
    if(h->item_list[bucket].key != NULL){

        v = (int*)h->item_list[bucket].val;
        free(h->item_list[bucket].key);
        free(h->item_list[bucket].val);

        h->item_list[bucket].key = NULL;
        h->item_list[bucket].val = NULL;
    }

    return v;
}

int hash_table_size(HashTable *h){
    return h->table_size;
}

int hash_table_num_elems(HashTable *h){
    return h->n_elements;
}