
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

        scanf(" %s %s", command, word);

        char* data = strdup(word);

        if(!strcmp(command, "PUSH")){
            vector_insert(v, 0, data);
        }

        else if(!strcmp(command, "POP")){
            char* oi = (char*)vector_remove(v, vector_size(v) - 1);
            printf();
        }
    }

    vector_destroy(v);

    return 0;
}
