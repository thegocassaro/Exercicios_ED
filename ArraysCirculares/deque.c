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

    printf("%d\n", f->end);

    f->arr[f->end] = item;
    f->end = (f->end + 1) % f->capacity;
    f->size++;

    if(f->end == f->start)
        increase_capacity(f);
}

void deque_push_front(Deque *f, int item){

    printf("%d\n", (f->start - 1) % f->capacity);

    f->arr[(f->start - 1) % f->capacity] = item;
    f->start = (f->start - 1) % f->capacity;
    f->size++;

    if(f->size == f->capacity)
        increase_capacity(f);
}

int deque_pop_back(Deque *f){

    printf("%d\n", (f->end - 1) % f->capacity);

    int removed = f->arr[(f->end - 1) % f->capacity];
    f->size--;
    f->end = (f->end - 1) % f->capacity;

    return removed;
}

int deque_pop_front(Deque *f){

    printf("%d\n", f->start);

    int removed = f->arr[f->start];
    f->size--;
    f->start = (f->start + 1) % f->capacity;

    return removed;
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