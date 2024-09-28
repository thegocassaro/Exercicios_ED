#ifndef INDEXADOR_H_
#define INDEXADOR_H_
#include "hash.h"
#include "doc_freq.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Indexador Indexador;

Indexador* indexador_construct(int table_size, HashFunction hash_fn, CmpFunction cmp_fn);
void indexador_add(Indexador* idx, char* key, char* val);
void indexador_print(Indexador* idx);
void indexador_destroy(Indexador* idx);

#endif