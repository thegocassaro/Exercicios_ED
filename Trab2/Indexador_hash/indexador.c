#include "indexador.h"

struct Indexador{

    HashTable* ht;
};

Indexador* indexador_construct(int table_size, HashFunction hash_fn, CmpFunction cmp_fn){

    Indexador* idx = (Indexador*)calloc(1, sizeof(Indexador));

    idx->ht = hash_table_construct(table_size, hash_fn, cmp_fn);

    return idx;
}

void indexador_add(Indexador* idx, char* key, char* val){

    ForwardList* lista_doc_freq = (ForwardList*)hash_table_get(idx->ht, key);

    if(lista_doc_freq == NULL){
        lista_doc_freq = forward_list_construct();
        char* word = strdup(key);
        hash_table_set(idx->ht, word, lista_doc_freq);
    }

    else{

        DocFreq* df;
        ListIterator* it = list_iterator_construct(lista_doc_freq);

        while(!list_iterator_is_over(it)){

            df = (DocFreq*)list_iterator_next(it);
            if(!strcmp(df_get_name(df), val)){
                df_add_frequency(df);
                return;
            }
        }

        list_iterator_destroy(it);
    }

    DocFreq* df = df_construct(val);
    forward_list_push_front(lista_doc_freq, df);
}

void indexador_print(Indexador* idx){

    HashTableIterator* it = hash_table_iterator(idx->ht);
    HashTableItem* item;

    printf("%d\n", hash_table_num_elems(idx->ht));

    while(!hash_table_iterator_is_over(it)){

        item = hash_table_iterator_next(it);
        char* word = (char*)item->key;
        ForwardList* fl = (ForwardList*)item->val;

        printf("%s", word);

        ListIterator* it2 = list_iterator_construct(fl);

        while(!list_iterator_is_over(it2)){

            DocFreq* df = (DocFreq*)list_iterator_next(it2);
            printf(" %d %s", df_get_frequency(df), df_get_name(df));
        }

        printf("\n");

        list_iterator_destroy(it2);
    }

    hash_table_iterator_destroy(it);
}

void indexador_destroy(Indexador* idx){

    HashTableIterator* it = hash_table_iterator(idx->ht);
    
    while(!hash_table_iterator_is_over(it)){

        HashTableItem* item = hash_table_iterator_next(it);
        free(item->key);

        ForwardList* fl = item->val;
        ListIterator* it2 = list_iterator_construct(fl);
        
        while(!list_iterator_is_over(it2)){
            df_destroy((DocFreq*)list_iterator_next(it2));
        }

        list_iterator_destroy(it2);
        forward_list_destroy(fl);

        free(item->val);
        free(item);
    }

    hash_table_iterator_destroy(it);

    hash_table_destroy(idx->ht);
    free(idx);
    idx = NULL;
}