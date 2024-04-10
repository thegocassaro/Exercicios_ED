#include "priority_queue_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct PriorityQueue{

    void** data_vector;
    int size;
    int allocated;
    fp_compare cmp_fn;
};

PriorityQueue *pq_constructor(int cmp_fn(const void *, const void *)){

    PriorityQueue* pq = (PriorityQueue*)calloc(1, sizeof(PriorityQueue));

    pq->allocated = 10;
    pq->data_vector = (void**)calloc(pq->allocated, sizeof(void*));
    pq->cmp_fn = cmp_fn;

    return pq;
}

void pq_push(PriorityQueue *pq, void *data){

    if(pq->size == pq->allocated){
        pq->allocated *= 2;
        pq->data_vector = (void**)realloc(pq->allocated, sizeof(void*));
    }

    //adiciona novo elemento
    pq->data_vector[pq->size] = data;

    //reordena vetor de dados até que o novo elemento esteja na ordem de prioridade certa
    for(int i=pq->size - 1; i>=0; i--){

        //caso o novo elemento seja de menor prio que seu vizinho anterior, troca
        //desse modo, o ele de maior prio ficará sempre no ultimo indice, facilitando na hora do pop
        if(pq->cmp_fn(data, pq->data_vector[pq->size - 1]) == -1){

            void* aux = pq->data_vector[pq->size - 1];
            pq->data_vector[pq->size - 1] = data;
            pq->data_vector[pq->size] = aux;
        }
    }

    pq->size++;
}

void *pq_pop(PriorityQueue *pq){

    if(pq->size <= 0){

        printf("Nao ha elementos na fila.\n");
        exit(1);
    }

    pq->size--;

    return pq->data_vector[pq->size];
}

int pq_size(PriorityQueue *pq){

    return pq->size;
}

void pq_destroy(PriorityQueue *pq){

    free(pq->data_vector);
    free(pq);
    pq = NULL;
}
