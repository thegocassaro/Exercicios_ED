#include "vector.h"
#include <stdlib.h>

// Aloca espaço para um elemento do tipo vector e inicializa os seus atributos.
Vector *vector_construct(){

    Vector* v = (Vector*)calloc(v, sizeof(Vector));

    v->allocated = 10;
    v->data = (data_type)calloc(v->data, sizeof(data_type) * v->allocated);

    return v;
}

// Libera o espaço reservado para o vector.
void vector_destroy(Vector *v){

    free(v->data);
    free(v);
    v = NULL;
}

// Adiciona o item dado ao final do vector e aumenta o tamanho. Aumenta a capacidade alocada se necessário.
void vector_push_back(Vector *v, data_type val);

// Retorna o número de elementos atualmente no vector.
int vector_size(Vector *v);

// Retorna o i-ésimo elemento do vector.
data_type vector_get(Vector *v, int i);

// Atualiza o i-ésimo elemento do vector  para que ele passe a ter o valor val.
void vector_set(Vector *v, int i, data_type val);

// Retorna o índice da primeira ocorrência do item no Vector ou -1 se o elemento não for encontrado.
int vector_find(Vector *v, data_type val);

// Retorna o maior elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
data_type vector_max(Vector *v);

// Retorna o menor elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
data_type vector_min(Vector *v);

// Retorna o índice do maior elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
int vector_argmax(Vector *v);

// Retorna o índice do menor elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
int vector_argmin(Vector *v);