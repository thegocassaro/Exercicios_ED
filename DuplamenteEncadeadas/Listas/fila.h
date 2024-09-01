
#ifndef FILA_H_
#define FILA_H_

typedef void* data_type;
typedef struct fila Fila;

Fila *fila_construct();
int fila_size(Fila *f);
void fila_enqueue(Fila *f, void* item);
data_type fila_dequeue(Fila *f);
void fila_destroy(Fila *f);

#endif