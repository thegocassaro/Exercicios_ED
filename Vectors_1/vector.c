#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

// Aloca espaço para um elemento do tipo vector e inicializa os seus atributos.
Vector *vector_construct(){

    Vector* v = (Vector*)calloc(1, sizeof(Vector));

    v->allocated = 10;
    v->data = (data_type*)calloc(v->allocated, sizeof(data_type));

    return v;
}

// Libera o espaço reservado para o vector.
void vector_destroy(Vector *v){

    free(v->data);
    free(v);
    v = NULL;
}

// Adiciona o item dado ao final do vector e aumenta o tamanho. Aumenta a capacidade alocada se necessário.
void vector_push_back(Vector *v, data_type val){

    if(v->allocated == v->size){

        v->allocated *= 2;
        v->data = (data_type*)realloc(v->data, sizeof(data_type) * v->allocated);
    }

    v->data[v->size] = val;
    v->size++;
}

// Retorna o número de elementos atualmente no vector.
int vector_size(Vector *v){

    return v->size;
}

// Retorna o i-ésimo elemento do vector.
data_type vector_get(Vector *v, int i){

    if(i >= 0 && i < v->size){
        return v->data[i];
    }

    printf("Oh no\n");
    exit(1);
}

// Atualiza o i-ésimo elemento do vector  para que ele passe a ter o valor val.
void vector_set(Vector *v, int i, data_type val){

    if(i >= 0 && i < v->size){
        v->data[i] = val;
    }
}

// Retorna o índice da primeira ocorrência do item no Vector ou -1 se o elemento não for encontrado.
int vector_find(Vector *v, data_type val){

    for(int i=0; i<v->size; i++){

        if(v->data[i] == val){
            return i;
        }
    }

    return -1;
}

// Retorna o maior elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
data_type vector_max(Vector *v){

    data_type the_big = v->data[0], index = 0;

    for(int i=0; i<v->size; i++){

        if(v->data[i] > the_big){
            the_big = v->data[i];
            index = i;
        }
    }

    return v->data[index];
}

// Retorna o menor elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
data_type vector_min(Vector *v){

    data_type the_small = v->data[0], index = 0;

    for(int i=0; i<v->size; i++){

        if(v->data[i] < the_small){
            the_small = v->data[i];
            index = i;
        }
    }

    return v->data[index];
}

// Retorna o índice do maior elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
int vector_argmax(Vector *v){

    data_type the_big = v->data[0], index = 0;

    for(int i=0; i<v->size; i++){

        if(v->data[i] > the_big){
            the_big = v->data[i];
            index = i;
        }
    }

    return index;
}

// Retorna o índice do menor elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
int vector_argmin(Vector *v){

    data_type the_small = v->data[0], index = 0;

    for(int i=0; i<v->size; i++){

        if(v->data[i] < the_small){
            the_small = v->data[i];
            index = i;
        }
    }

    return index;
}
