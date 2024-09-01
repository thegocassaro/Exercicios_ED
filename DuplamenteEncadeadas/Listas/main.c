#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "node.h"

typedef void* data_type;

void print_data(data_type data)
{
    char* val = (char*)data;
    printf("%s", val);
}

int main()
{
    int num_instructions;
    scanf("%d", &num_instructions);

    Fila *fila = fila_construct();

    for (int i = 0; i < num_instructions; i++)
    {
        char command[20];

        scanf("\n%s", command);

        if (strcmp(command, "ENQUEUE") == 0)
        {
            char aux[50];
            scanf(" %s", aux);

            char* value = strdup(aux);
            fila_enqueue(fila, value);
        }

        else if (strcmp(command, "DEQUEUE") == 0)
        {
            char* val = (char*)fila_dequeue(fila);
            printf("%s\n", val);
            free(val);
        }
    }

    fila_destroy(fila);

    return 0;
}