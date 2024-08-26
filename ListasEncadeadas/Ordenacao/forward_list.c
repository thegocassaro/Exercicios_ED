#include "forward_list.h"
#include <stdio.h>
#include <stdlib.h>


ForwardList *forward_list_construct(){
    
    ForwardList* l = (ForwardList*)calloc(1, sizeof(ForwardList));
    l->size = 0;
    l->head = NULL;
    // l->last = NULL;

    return l;
}

int forward_list_size(ForwardList *l){
    
    return l->size;
}

void forward_list_push_front(ForwardList *l, data_type data){
    
    Node* node = node_construct(data, l->head);
    l->head = node;

    // if(l->size == 0) l->last = l->head;
    l->size++;
}

// void forward_list_push_back(ForwardList *l, data_type data){

//     Node* node = node_construct(data, NULL);
    
//     if(l->size == 0){
//         l->head = l->last = node;
//     }

//     else{
//         l->last->next = node;
//         l->last = node;    
//     }

//     l->size++;
// }

void forward_list_print(ForwardList *l, void (*print_fn)(data_type)){

    Node* n = l->head;
    // printf("[");

    while(n != NULL){
        
        print_fn(n->value);
        n = n->next;

        if(n != NULL){
            // printf(", ");
            printf("\n");
        }
    }
    
    // printf("]");
}

data_type forward_list_get(ForwardList *l, int i){
    
    if(i<0 || i>=l->size){
        printf("mensagem de erro informativa");
        exit(0);
    }

    Node* n = l->head;

    for(int j=0; j<i; j++){

        n = n->next;
    }

    return n->value;
}

data_type forward_list_pop_front(ForwardList *l){
    
    if(l->head == NULL){
        printf("uma mensagem de erro\n");
        exit(0);
    }

    Node* aux = l->head;
    data_type aux_value = aux->value;

    l->head = aux->next;
    node_destroy(aux);

    l->size--;
    // if(l->size <= 1) l->last = l->head; //(NULL)

    return aux_value;
}

ForwardList *forward_list_reverse(ForwardList *l){
    
    ForwardList* reversed_l = forward_list_construct();

    for(int i=0; i<forward_list_size(l); i++){

        forward_list_push_front(reversed_l, forward_list_get(l, i));
    }

    return reversed_l;
}

void forward_list_clear(ForwardList *l){
    
    Node* n = l->head;

    while(n != NULL){

        n = n->next;
        forward_list_pop_front(l);
    }
}

void forward_list_remove(ForwardList *l, data_type val){

    Node *n = l->head;
    Node *prev = NULL;

    while(n != NULL){

        if (n->value == val){

            //caso em que head deve ser removida
            if(prev == NULL){
                l->head = n->next;
            }

            else{
                prev->next = n->next;
            }

            Node* aux = n;
            n = n->next;
            node_destroy(aux);
            l->size--;
            continue;
        }

        prev = n;
        n = n->next;
    }

}

void forward_list_unique(ForwardList *l){
    
}

void forward_list_cat(ForwardList *l, ForwardList *m){
    
    for(int i=0; i<forward_list_size(m); i++){
        forward_list_push_front(l, forward_list_get(m, i));
    }

}

void forward_list_sort(ForwardList *l){

    for(int i=l->size - 1; i>=0; i--){
    
    Node* n = l->head;

        for(int j=0; j<i; j++){

            if(n->value> n->next->value){

                data_type aux = n->value;
                n->value = n->next->value;
                n->next->value = aux;
            }

            n = n->next;
        }
    }
}

void forward_list_destroy(ForwardList *l){
    
    Node* n = l->head;

    while(n != NULL){
        
        Node* next = n->next;
        node_destroy(n);
        n = next;
    }

    free(l);
}

ListIterator *list_iterator_construct(ForwardList *l){
    
    ListIterator *it = (ListIterator *)calloc(1, sizeof(ListIterator));
    it->current = l->head;

    return it;
}

void list_iterator_destroy(ListIterator *it){
    
    free(it);
}

data_type* list_iterator_next(ListIterator *it){
    
    data_type *n = &(it->current->value);
    it->current = it->current->next;

    return n;
}

bool list_iterator_is_over(ListIterator *it){
    
    return (it->current == NULL);
}

data_type forward_list_pop_index(ForwardList *l, int index){

    if(index<0 || index>=l->size){
        printf("INVALID INDEX\n");
        // return NULL;
        return -1;
    }

    Node *n = l->head;

    if(index == 0){
        l->head = l->head->next;
        data_type aux_data = n->value;
        node_destroy(n);
        l->size--;
        return aux_data;
    }

    for(int i=1; i<index; i++){
        n = n->next;
    }

    Node* aux = n->next;
    data_type aux_data = aux->value;

    if(index == l->size - 1)    n->next = NULL;
    else                        n->next = n->next->next;

    node_destroy(aux);
    l->size--;

    return aux_data;
}