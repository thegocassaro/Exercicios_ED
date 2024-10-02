#include <stdio.h>
#include <stdlib.h>

typedef struct{

    void** data;
    int capacity, start, end, size;
    void(*destroy_fn)(void*);
} Deque;

void destroy_data(void* data){

    int* content = (int*)data;
    free(content);
}

Deque* deque_construct(int capacity, void(*destroy_fn)(void*)){

    Deque* d = calloc(1, sizeof(Deque));
    d->destroy_fn = destroy_fn;
    d->capacity = capacity;
    d->data = (void**)calloc(capacity, sizeof(void*));

    return d;
}

void deque_destroy(Deque* d){

    for(int i=0; i<d->size; i++){
        d->destroy_fn(d->data[i]);
    }

    free(d->data);
    free(d);
}

void increase_capacity(Deque* d){

    void** new_data = calloc(d->capacity * 2, sizeof(void*));
    int virtual_idx = d->start;
    
    for(int i=0; i<d->size; i++){

        virtual_idx = (d->start + i) % d->capacity;

        new_data[i] = d->data[virtual_idx];
        d->destroy_fn(d->data[virtual_idx]);
    }

    free(d->data);
    d->data = new_data;
    d->capacity *= 2;
}

void deque_push_back(Deque* d, void* data){
    
    d->data[d->end] = data;
    d->end = (d->end + 1) % d->capacity;
    d->size++;

    if(d->size == d->capacity || d->size == d->end){
        increase_capacity(d);
    }
}

void deque_push_front(Deque* d, void* data){

    d->start = (d->start + d->capacity - 1) % d->capacity;
    d->data[d->start];
    d->size++;

    if(d->size == d->capacity || d->size == d->end){
        increase_capacity(d);
    }
}

void* deque_pop_back(Deque* d){

    int new_end = (d->end + d->capacity - 1) % d->capacity;
    void* aux = d->data[new_end];

    d->end = new_end;
    d->size--;
    
    return aux;
}

void* deque_pop_front(Deque* d){

    void* aux = d->data[d->start];

    d->start = (d->start + 1) % d->capacity;
    d->size--;
    
    return aux;
}