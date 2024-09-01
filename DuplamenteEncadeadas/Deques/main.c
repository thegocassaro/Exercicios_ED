#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

typedef int data_type;

void print_data(data_type data)
{
    printf("%d", data);
}

int main()
{
    int num_instructions;
    scanf("%d", &num_instructions);

    Deque *deque = deque_construct();

    for (int i = 0; i < num_instructions; i++)
    {
        char command[20];

        scanf("\n%s", command);

        if (strcmp(command, "PUSH_FRONT") == 0)
        {
            int value;
            scanf("%d\n", &value);
            deque_push_front(deque, value);
        }

        else if (strcmp(command, "PUSH_BACK") == 0)
        {
            int value;
            scanf("%d\n", &value);
            deque_push_back(deque, value);
        }

        else if (strcmp(command, "POP_FRONT") == 0)
        {
            int val = deque_pop_front(deque);
            printf("%d\n", val);
        }

        else if (strcmp(command, "POP_BACK") == 0)
        {
            int val = deque_pop_back(deque);
            printf("%d\n", val);
        }
    }

    deque_destroy(deque);

    return 0;
}