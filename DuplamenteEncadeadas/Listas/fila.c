#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "list.h"

struct fila{

    List* list;
};


Fila *fila_construct(){
    
    Fila* fila = (Fila*)calloc(1, sizeof(Fila));
    fila->list = list_construct();
    return fila;
}

int fila_size(Fila *f){
    return list_size(f->list);
}

void fila_enqueue(Fila *f, void* item){
    list_push_back(f->list, item);
}

data_type fila_dequeue(Fila *f){
    return list_pop_front(f->list);
}

void fila_destroy(Fila *f){

    list_destroy(f->list);
    free(f);
}