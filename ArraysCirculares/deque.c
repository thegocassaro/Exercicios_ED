#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

struct Deque{
    int *arr;
    int start;
    int end;
    int size;
    int capacity;
};

Deque *deque_construct(){

    Deque* f = (Deque*)calloc(1, sizeof(Deque));

    f->capacity = 10;
    f->arr = (int*)calloc(f->capacity, sizeof(int));

    return f;
}

void deque_push_back(Deque *f, int item){

    f->arr[f->end] = item;
    f->end = (f->end + 1) % f->capacity;
    f->size++;

    if(f->size == f->capacity)
        increase_capacity(f);
}

void deque_push_front(Deque *f, int item){

}

int deque_pop_back(Deque *f){

}

int deque_pop_front(Deque *f){

}

void deque_destroy(Deque *f){

    free(f->arr);
    free(f);
    f = NULL;
}

void increase_capacity(Deque *f){

    int* new_arr = (int*)calloc(f->capacity * 2, sizeof(int));

    //pra facilitar a copia do conteudo antigo pro novo array, passamos o start para o indice 0 do novo;
    // (f->start + i) % f->capacity // simplesmente da o indice "virtual" do array, considerando que ele
    // pode ultrapassar o tamanho da capacidade e voltar ao indice 0;
    for(int i=0; i<f->size; i++){

        int idx_origin = (f->start + i) % f->capacity;
        int idx_destiny = i;

        new_arr[idx_destiny] = f->arr[idx_origin];
    }

    free(f->arr);
    f->arr = new_arr;
    f->capacity *= 2;
}