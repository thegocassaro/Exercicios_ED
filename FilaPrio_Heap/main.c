#include <stdio.h>
#include "priority_queue_vector.h"
#include "vector.h"
#include "processos.h"

int main(){

    int n=0;
    char nome[32], categoria[32]; 
    int identificador, prioridade;

    PriorityQueue* pq = pq_constructor(cmp_prio);

    scanf(" %d", &n);

    for(int i=0; i<n; i++){

        scanf(" %s %s %d %d", nome, categoria, &identificador, &prioridade);
        pq_push(pq, process_construct(nome, categoria, identificador, prioridade));
    }

    for(int i=0; i<n; i++){

        void* removed_item = pq_pop(pq);
        process_print(removed_item);
        process_destroy(removed_item);
    }

    pq_destroy(pq);

    return 0;
}