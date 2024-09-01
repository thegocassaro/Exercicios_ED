#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"

struct stack{

    List* list;
};

Stack *stack_construct(){

    Stack* stack = (Stack*)calloc(1, sizeof(Stack));

    stack->list = list_construct();

    return stack;
}

void stack_push(Stack *f, data_type item){
    
    list_push_front(f->list, item);
}

data_type stack_pop(Stack *f){
    
    return list_pop_front(f->list);
}

int stack_num_elements(Stack *f){
    
    return list_size(f->list);
}

void stack_destroy(Stack *f){
    list_destroy(f->list);
    free(f);
}
