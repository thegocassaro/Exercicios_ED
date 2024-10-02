#include <stdio.h>
#include <stdlib.h>

typedef struct{

    void* value;
    Node* next;
    Node* prev;
} Node;

typedef struct{

    Node* head;
    Node* last;
    int size;
}List;

typedef struct{

    Node* current;
} ListIterator;

Node* node_construct(void* val, Node* next, Node* prev){

    Node* node = calloc(1, sizeof(Node));

    node->value = val;
    node->next = next;
    node->prev = prev;

    return node;
}

void node_destroy(Node* node){

    free(node);
}

List* list_construct(){

    List* list = calloc(1, sizeof(List));
    list->head = NULL;
    list->last = NULL;

    return list;
}

ListIterator* list_iterator_construct(List* list){

    ListIterator* it = calloc(1, sizeof(ListIterator));

    it->current = list->head;

    return it;
}

void* list_iterator_next(ListIterator* it){

    void* aux = it->current->value;

    it->current = it->current->next;

    return aux;
}

void destroy_list_iterator(ListIterator* it){

    free(it);
}

int list_iterator_is_over(ListIterator* it){

    if(it->current == NULL) return 1;

    return 0;
}

void list_destroy(List* list){

    ListIterator* it = list_iterator_construct(list);

    while(!list_iterator_is_over(it)){

        void* item = list_iterator_next(it);
        destroy_item(item);
    }

    Node* node = list->head;

    for(int i=0; i<list->size; i++){

        Node* next = node->next;
        free(node);
        node = next;
    }

    free(list);
}

void list_push_front(List* list, void* val){

    if(list->head == NULL){

        list->head = node_construct(val, NULL, NULL);
        list->last = list->head;
    }

    Node* node = node_construct(val, list->head, NULL);
    list->head->prev = node;
    list->head = node;

    list->size++;
}

void list_push_back(List* list, void* val){

    if(list->last == NULL){

        list->last = node_construct(val, NULL, NULL);
        list->head = list->last;
    }

    Node* node = node_construct(val, NULL, list->last);
    list->last->next = node;
    list->last = node;

    list->size++;
}

void* list_pop_front(List* list){
    
    Node* removed_node = list->head;

    list->head = list->head->next;
    list->head->prev = NULL;

    void* removed_item = removed_node->value;
    
    node_destroy(removed_node);

    list->size--;
    if(list->size <= 1){
        list->head = list->last;
    }

    return removed_item;
}

void* list_pop_back(List* list){

    Node* removed_node = list->last;

    list->last = list->last->prev;
    list->last->next = NULL;

    void* removed_item = removed_node->value;
    
    node_destroy(removed_node);

    list->size--;
    if(list->size <= 1){
        list->head = list->last;
    }

    return removed_item;
}

void* list_remove(List* list, int idx){

    if(idx >= list->size) return NULL;

    Node* node = list->head;

    for(int i=0; i<idx; i++){

        node = node->next;
    }

    void* removed_item = node->value;
    node->prev->next = node->next;
    node->next->prev = node->prev;

    if(node == list->head || idx == 0){

        list->head = node->next;
    }

    if(node == list->last || idx == list->size - 1){

        list->last = node->prev;
    }

    destroy_node(node);

    list->size--;

    return removed_item;
}