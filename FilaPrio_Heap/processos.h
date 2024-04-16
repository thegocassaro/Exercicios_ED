#ifndef PROCESS_H_
#define PROCESS_H_

typedef struct Process Process;

int cmp_prio(const void*, const void*);
Process* process_construct(char* nome, char* categoria, int identificador, int prioridade);
void process_destroy(void* process);
void process_print(void*);

#endif