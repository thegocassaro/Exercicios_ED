#include "processos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process
{
    char nome[32], categoria[32]; 
    int identificador, prioridade;
};

int cmp_prio(const void* cmp1, const void* cmp2){

    Process* a = (Process*)cmp1;
    Process* b = (Process*)cmp2;

    if(a->prioridade > b->prioridade) return 1;
    else if(a->prioridade < b->prioridade) return -1;
    return 0;
}

Process* process_construct(char* nome, char* categoria, int identificador, int prioridade){

    Process* p = (Process*)calloc(1, sizeof(Process));

    strcpy(p->nome, nome);
    strcpy(p->categoria, categoria);
    p->identificador = identificador;
    p->prioridade = prioridade;

    return p;
}

void process_destroy(void* process){

    Process* p = (Process*)process;
    free(p);
    p = NULL;
}

void process_print(void* process){

    Process* p = (Process*)process;

    printf("%s %s %d %d\n", p->nome, p->categoria, p->identificador, p->prioridade);
}