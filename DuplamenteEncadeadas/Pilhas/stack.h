
#ifndef STACK_H_
#define STACK_H_

typedef char* data_type;

typedef struct stack Stack;

Stack *stack_construct();
void stack_push(Stack *f, data_type item);
data_type stack_pop(Stack *f);
int stack_num_elements(Stack *f);
void stack_destroy(Stack *f);

#endif