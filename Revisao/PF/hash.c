#include "list_enc.c"

typedef struct{

    List** table;
    int size;
    int n_elements;
    int(*cmp_fn)(void*, void*);
    void(*free_fn)(void*);
} Hash;

typedef struct{

    void* key;
    void* val;
} HashTableItem;

typedef struct{

    Hash* ht;
    Node* current_node;
    int current_bucket;
    int n_elements;
} HashIterator;

int hash_fn(Hash *h, void *data)
{
    char *str = (char *)data;

    long hash_val = 0;
    int base = 127;

    for (size_t i = 0; i < strlen(str); i++)
        hash_val = (base * hash_val + str[i]) % hash_table_size(h);

    return hash_val;
}

void destroy_item(void* item){

    HashTableItem* hti = (HashTableItem*)item;

    free(hti->key);
    //inventando coisa supondo que dentro de val haja uma struct //char* data + coisas randoms que nao precise desalocar manualmente
    free(get_val_data(hti->val));
    free(hti->val);
}

int compare_item(void* item1, void* item2){

    HashTableItem* hti1 = (HashTableItem*)item1;
    HashTableItem* hti2 = (HashTableItem*)item2;

    return strcmp((char*)hti1->key, (char*)hti2->key);
}

Hash* hash_construct(int(*cmp_fn)(void*, void*), void(*free_fn)(void*)){

    Hash* ht = calloc(1, sizeof(Hash));

    ht->cmp_fn = cmp_fn;
    ht->free_fn = free_fn;
    ht->table = calloc(10, sizeof(List*));

    for(int i=0; i<10; i++){

        ht->table[i] = NULL;
    }

    return ht;
}

HashTableItem* hash_item_construct(void* key, void* val){

    HashTableItem* item = calloc(1, sizeof(HashTableItem));

    item->key = key;
    item->val = val;

    return item;
}

HashIterator* hash_iterator_construct(Hash* ht){

    HashIterator* it = calloc(1, sizeof(HashIterator));

    it->ht = ht;
    it->current_node = NULL;

    return it;
}

void hash_iterator_destroy(HashIterator* it){

    free(it);
}

int hash_iterator_is_over(HashIterator* it){

    if(it->n_elements >= it->ht->n_elements) return 1;

    return 0;
}

void* hash_iterator_next(HashIterator* it){

    if(it->n_elements == it->ht->n_elements) return NULL;

    void* aux = NULL; //grava o hashtableitem armazenado dentro do node

    //caso ainda possua elementos naquela chave, pega o proximo da lista encadeada
    if(it->current_node != NULL){
        aux = it->current_node->value;
    }
    
    else{

        while(it->current_bucket < it->ht->size){

            it->current_bucket++;

            if(it->ht->table[it->current_bucket] != NULL){

                it->current_node = list_get(it->ht->table[it->current_bucket], 0);
                aux = it->current_node->value;
                break;
            }
        }
    }

    it->current_node = it->current_node->next;
    it->n_elements++;

    return aux;
}

void hash_destroy(Hash* ht){

    // HashIterator* it = hash_iterator_construct(ht);

    // while(!hash_iterator_is_over(it)){
    //     ht->free_fn(hash_iterator_next(it));
    // }

    // hash_iterator_destroy(it);

    for(int i=0; i<ht->size; i++){

        if(ht->table[i] != NULL){
            list_destroy(ht->table[i]);
        }
    }

    free(ht->table);
    free(ht);
}

void hash_set(Hash* ht, void* key, void* val){

    HashTableItem* item = calloc(1, sizeof(HashTableItem));

    item->key = key;
    item->val = val;

    int bucket = hash_fn(ht, key);

    if(ht->table[bucket] == NULL){
        ht->table[bucket] = list_construct();
    }

    list_push_front(ht->table[bucket], item);
    
    ht->n_elements++;
}

void* hash_get(Hash* ht, void* key){

    HashIterator* it = hash_iterator_construct(ht);

    while(!hash_iterator_is_over(it)){

        HashTableItem* item = (HashTableItem*)hash_iterator_next(it);

        if(!ht->cmp_fn(item->key, key)){

            hash_iterator_destroy(it);
            return item;
        }
    }

    hash_iterator_destroy(it);

    return NULL;
}

void* hash_pop(Hash* ht, void* key){

    int bucket = hash_fn(ht, key);

    if(ht->table[bucket] == NULL) return NULL;

    ListIterator* it = list_iterator_construct(ht->table[bucket]);
    int idx_node = 0;

    while(!list_iterator_is_over(it)){

        HashTableItem* item = (HashTableItem*)list_iterator_next(it);

        if(ht->cmp_fn(item->key, key)){

            item = list_remove(ht->table[bucket], idx_node);
            destroy_list_iterator(it);
            ht->n_elements--;
            return item->val;
        }

        idx_node++;
    }

    destroy_list_iterator(it);

    return NULL;
}