#include "heap.h"

struct Heap {
    void** nodes;
    int size;
    int capacity;
    fp_compare cmp_fn;
};

Heap *heap_constructor(int (*cmp_fn)(const void *, const void *)){

    Heap* heap = (Heap*)calloc(1, sizeof(Heap));

    heap->cmp_fn = cmp_fn;
    heap->capacity = 10;
    heap->nodes = (void**)calloc(heap->capacity, sizeof(void*));

    return heap;
}

void heap_destroy(Heap *heap){

    for(int i=0; i<heap->size; i++){
        free(heap->nodes[i]);
    }
    free(heap->nodes);
    free(heap);
    heap = NULL;
}

void heap_push(Heap *heap, void *data){

    if(heap->capacity <= heap->size){

        heap->capacity *= 2;
        heap->nodes = (void**)realloc(heap->nodes, sizeof(void*) * heap->capacity);
    }

    heap->nodes[heap->size] = data;

    //fazemos size/2 - 1 pois queremos comecar do ultimo elemento que seja pelo menos pai de alguem (pois o algoritmo do heapify
    //compara sempre pai e filho(s)), e isso ate chegar na raiz (indice 0), de modo a pegarmos todas as ramificacoes
    heap->size++;

    for(int i=((heap->size / 2) - 1); i>=0; i--)
        heapify(heap, i);
}

void heapify(Heap* heap, int idx){

    int max = idx;
    int left_child = 2 * idx + 1;
    int right_child = 2 * idx + 2;

    //1) temos que checar se os nodes estao dentro do vetor definido, alem de que podem haver pais sem filhos
    //2) se a prioridade do filho for maior q a do pai, trocamos, mas deve ser o filho de maior prioridade, por isso
    // as duas checagens, da direita e da esquerda
    if((left_child < heap->size) && (heap->cmp_fn(heap->nodes[left_child], heap->nodes[max])) == 1){
        max = left_child;
    }
    
    if((right_child < heap->size) && (heap->cmp_fn(heap->nodes[right_child], heap->nodes[max])) == 1){
        max = right_child;
    }
    
    //se houve necessidade de troca, realizamos e chamamos a heapify recursivamente para reajustar o resto da linhagem
    if(max != idx){
        heap_swap_nodes(heap, idx, max);
        heapify(heap, max);
    }

}

void heap_swap_nodes(Heap* heap, int idx_1, int idx_2){

    void* aux = heap->nodes[idx_1];
    heap->nodes[idx_1] = heap->nodes[idx_2];
    heap->nodes[idx_2] = aux;
}

int heap_size(Heap* heap){

    return heap->size;
}

void *heap_pop(Heap *heap){

    void* removed = heap->nodes[0];
    heap_swap_nodes(heap, 0, heap->size - 1);

    heap->size--;

    for(int i=((heap->size / 2) - 1); i>=0; i--)
        heapify(heap, i);

    return removed;
}