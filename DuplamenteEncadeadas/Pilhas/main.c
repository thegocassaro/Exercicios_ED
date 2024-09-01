#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "node.h"

typedef char* data_type;

void print_data(data_type data)
{
    printf("%s", data);
}

int main()
{
    int num_instructions;
    scanf("%d", &num_instructions);

    Stack *stack = stack_construct();

    for (int i = 0; i < num_instructions; i++)
    {
        char command[20];

        scanf("\n%s", command);

        if (strcmp(command, "PUSH") == 0)
        {
            char aux[50];
            scanf(" %s", aux);

            char* value = strdup(aux);
            stack_push(stack, value);
        }

        else if (strcmp(command, "POP") == 0)
        {
            char* val = stack_pop(stack);
            printf("%s\n", val);
            free(val);
        }
    }

    stack_destroy(stack);

    return 0;
}