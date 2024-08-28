#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"
#include "list.h"
#include "node.h"

void print_data(data_type data)
{
    char* aux = (char*)data;
    printf("%s", aux);
}

int main()
{
    int num_instructions;
    scanf("%d", &num_instructions);

    List *list = list_construct();

    for (int i = 0; i < num_instructions; i++)
    {
        char command[20];

        scanf("\n%s", command);

        if (strcmp(command, "PUSH_FRONT") == 0)
        {
            int value;
            scanf("%d\n", &value);
            list_push_front(list, value);
        }

        else if (strcmp(command, "PUSH_BACK") == 0)
        {
            int value;
            scanf("%d\n", &value);
            list_push_back(list, value);
        }

        else if (strcmp(command, "POP_FRONT") == 0)
        {
            int val = list_pop_front(list);
            printf("%d\n", val);
        }

        else if (strcmp(command, "POP_BACK") == 0)
        {
            int val = list_pop_back(list);
            printf("%d\n", val);
        }
    }

    list_destroy(list);

    return 0;
}