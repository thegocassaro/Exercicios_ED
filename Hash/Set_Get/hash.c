#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

struct HashTable{


};

HashTable *hash_table_construct(int table_size, HashFunction hash_fn, CmpFunction cmp_fn){

    HashTable* ht = (HashTable*)calloc(1, sizeof(HashTable));



    return ht;
}