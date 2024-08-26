#include "forward_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_data(data_type data)
{
    // implemente a funcao para mostrar um elemento da lista na tela.
    int aux = (int)data;
    printf("%d", aux);
}

int main()
{
    int num_instructions;
    scanf("%d", &num_instructions);

    ForwardList *list = forward_list_construct();

    for (int i = 0; i < num_instructions; i++)
    {
        int value;

        scanf("\n%d", &value);

        forward_list_push_front(list, value);
    }

    forward_list_sort(list);

    forward_list_print(list, print_data);

    forward_list_destroy(list);

    return 0;
}