#include <stdio.h>
#include <stdlib.h>

typedef struct{

    void* data;
    void* priority;
} HeapNode;

typedef struct{

    HeapNode** nodes;
    int(*cmp_fn)(void*, void*);
    void(*free_fn)(void*);
    int capacity, size;
} Heap;

Heap* heap_construct(int capacity, void(*cmp_fn)(void*, void*), void(*free_fn)(void*)){

    Heap* heap = calloc(1, sizeof(Heap));

    heap->capacity = capacity;
    heap->free_fn = free_fn;
    heap->cmp_fn = cmp_fn;

    heap->nodes = calloc(capacity, sizeof(HeapNode*));

    return heap;
}

HeapNode* heap_node_construct(void* data, void* priority){

    HeapNode* hn = calloc(1, sizeof(HeapNode));

    hn->data = data;
    hn->priority = priority;

    return hn;
}

void destroy_heap(Heap* h){

    for(int i=0; i<h->size; i++){

        h->free_fn(h->nodes[i]);
    }

    free(h->nodes);
    free(h);
}

void heap_push(Heap* h, HeapNode* new_hn){

    if(h->size >= h->capacity){

        h->capacity *= 10;
        h->nodes = realloc(h->nodes, h->capacity * sizeof(HeapNode*));
    }

    h->nodes[h->size] = new_hn;

    max_heapify(h, 0);
    
    h->size++;
}

void* heap_pop(Heap* h){

    void* aux = h->nodes[0];

    heap_swap_nodes(h, h->nodes[0], h->nodes[h->size - 1]);
    min_heapify(h, h->size - 1);

    h->size--;

    return aux;
}

void max_heapify(Heap* h, int idx_father){

    int idx_left = idx_father * 2 + 1;
    int idx_right = idx_father * 2 + 2;
    int largest = idx_father;

    if(idx_left < h->size && h->cmp_fn(h->nodes[idx_left], h->nodes[largest]) > 0){

        largest = idx_left;
    }

    if(idx_right < h->size && h->cmp_fn(h->nodes[idx_right], h->nodes[largest]) > 0){

        largest = idx_right;
    }

    if(largest != idx_father){

        heap_swap_nodes(h, idx_father, largest);
        max_heapify(h, largest);
    }
}

void min_heapify(Heap* h, int idx_son){

    int idx_father = (idx_son - 1) / 2;
    int largest = idx_father;

    if(idx_father >= 0 && h->cmp_fn(h->nodes[idx_son], h->nodes[idx_father]) > 0){

        largest = idx_son;
    }

    if(largest != idx_father){

        heap_swap_nodes(h, idx_father, largest);
        max_heapify(h, idx_father);
    }
}

void heap_swap_nodes(Heap* heap, int idx_1, int idx_2){

    void* aux = heap->nodes[idx_1];
    heap->nodes[idx_1] = heap->nodes[idx_2];
    heap->nodes[idx_2] = aux;
}