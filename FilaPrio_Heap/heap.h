#ifndef HEAP_H_
#define HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// typedef unsigned char bool;
typedef struct Heap Heap;

Heap *heap_constructor(int (*cmp_fn)(const void *, const void *));
void heap_destroy(Heap *heap); // O(1)
int heap_size(Heap* heap);
void heap_push(Heap *heap, void *data); // O(log N)
void heapify(Heap* heap, int idx);
void heap_swap_nodes(Heap* heap, int idx_1, int idx_2);

void *heap_pop(Heap *heap); // O(log N)
void *heap_max(Heap *heap); // O(1)
double heap_max_priority(Heap *heap); // O(1)
void heap_sort(void *array, int array_size, int item_size,double (*key_fn)(void *)); // O(N log N)
// bool heap_empty(Heap *heap); // O(1)

#endif