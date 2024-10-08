#include "priority_queue_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "processos.h"

struct PriorityQueue{

    Vector* data_vector;
    fp_compare cmp_fn;
};

PriorityQueue *pq_constructor(fp_compare cmp_fn, fp_destroy destroy_fn){

    PriorityQueue* pq = (PriorityQueue*)calloc(1, sizeof(PriorityQueue));

    pq->data_vector = vector_construct(destroy_fn);
    pq->cmp_fn = cmp_fn;

    return pq;
}

void pq_push(PriorityQueue *pq, void *data){

    //adiciona novo elemento
    vector_push_back(pq->data_vector, data);
}

void *pq_pop(PriorityQueue *pq){

    if(vector_size(pq->data_vector) <= 0){

        printf("Nao ha elementos na fila.\n");
        exit(1);
    }

    //reordena vetor de dados até que o elemento de maior prio esteja no ultimo indice, facilitando na hora do pop
    vector_sort_ascending(pq->data_vector, cmp_prio);
    return vector_remove(pq->data_vector, vector_size(pq->data_vector) - 1);    
}

int pq_size(PriorityQueue *pq){

    return vector_size(pq->data_vector);
}

void pq_destroy(PriorityQueue *pq){

    vector_destroy(pq->data_vector);
    free(pq);
    pq = NULL;
}
