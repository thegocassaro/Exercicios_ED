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

data_type forward_list_get(ForwardList *l, int i){
    
    if(i<0 && i>=l->size){
        printf("mensagem de erro informativa");
        exit(0);
    }

    Node* n = l->head;

    for(int j=0; j<i; j++){

        n = node_next(n);
    }

    return node_value(n);
}

data_type forward_list_pop_front(ForwardList *l){
    
    if(l->head == NULL){
        printf("uma mensagem de erro\n");
        exit(0);
    }

    Node* aux = l->head;
    int aux_value = node_value(aux);

    l->head = node_next(aux);
    node_destroy(aux);

    l->size--;

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

        n = node_next(n);
        forward_list_pop_front(l);
    }
}

void forward_list_remove(ForwardList *l, data_type val){

    Node *n = l->head;
    Node *prev = NULL;

    while(n != NULL){

        if (node_value(n) == val){

            //caso em que head deve ser removida
            if(prev == NULL){
                l->head = node_next(n);
            }

            else{
                prev->next = n->next;
            }

            Node* aux = n;
            n = node_next(n);
            node_destroy(aux);
            l->size--;
            return; //mudei de continue pra return pois pro trab não haverá mais de um 
                    //item com a mesma chave, logo n temos que continuar buscando
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