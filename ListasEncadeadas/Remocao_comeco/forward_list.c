#include "forward_list.h"
#include <stdio.h>
#include <stdlib.h>


ForwardList *forward_list_construct(){
    
    ForwardList* l = (ForwardList*)calloc(1, sizeof(ForwardList));
    l->size = 0;
    l->head = NULL;

    return l;
}

int forward_list_size(ForwardList *l){
    
    return l->size;
}

void forward_list_push_front(ForwardList *l, data_type data){
    
    Node* node = node_construct(data, l->head);
    l->head = node;
    l->size++;
}

void forward_list_print(ForwardList *l, void (*print_fn)(data_type)){

    Node* n = l->head;
    printf("[");

    while(n != NULL){
        
        print_fn(node_value(n));
        n = node_next(n);

        if(n != NULL){
            printf(", ");
        }
    }
    
    printf("]");
}

// data_type forward_list_get(ForwardList *l, int i){
    
// }

data_type forward_list_pop_front(ForwardList *l){
    
    if(l->head == NULL){
        
        printf("uma mensagem de erro\n");
        exit(0);
    }

    Node* aux = l->head;
    int aux_value = node_value(aux);

    l->head = node_next(aux);
    node_destroy(aux);

    return aux_value;
}

// ForwardList *forward_list_reverse(ForwardList *l){
    
// }

void forward_list_clear(ForwardList *l){
    
}

void forward_list_remove(ForwardList *l, data_type val){
    
}

void forward_list_unique(ForwardList *l){
    
}

void forward_list_cat(ForwardList *l, ForwardList *m){
    
}

void forward_list_sort(ForwardList *l){
    
}

void forward_list_destroy(ForwardList *l){
    
    Node* n = l->head;

    while(n != NULL){
        
        Node* next = node_next(n);
        node_destroy(n);
        n = next;
    }

    free(l);
}
