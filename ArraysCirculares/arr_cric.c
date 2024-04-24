#include "arr_circ.h"

const int MAX_SIZE = 10;

struct Fila {
    int *arr;
    int start;
    int end;
    int size;
};

void fila_push(Fila *f, int item) {
    f->arr[f->end] = item;
    f->end = (f->end + 1) % MAX_SIZE;
    f->size++;
}

int fila_pop(Fila *f) {
    int val = f->arr[f->start];
    f->start = (f->start + 1) % MAX_SIZE;
    f->size--;
    return val;
}

Fila *fila_constroi() {
    Fila *f = (Fila *)calloc(1, sizeof(Fila));
    f->arr = (int *)calloc(MAX_SIZE, sizeof(int));
    f->start = 0;
    f->end = 0;
    f->size = 0;
    return f;
}

void fila_destroy(Fila *f) {
    free(f->arr);
    free(f);
}