
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void destroy_string(void* str){

    char* s = (char*)str;
    free(s);
    s = NULL;
}

int main()
{
    int n;

    Vector* v = vector_construct(destroy_string);    

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char command[10];
        char word[50];

        scanf(" %s", command);

        if(!strcmp(command, "ENQUEUE")){
            scanf(" %s", word);
            char* data = strdup(word);
            vector_push_back(v, data);
        }

        if(!strcmp(command, "DEQUEUE")){
            char* removed = (char*)vector_pop_front(v);
            printf("%s\n", removed);
            free(removed);
        }
    }

    vector_destroy(v);

    return 0;
}
