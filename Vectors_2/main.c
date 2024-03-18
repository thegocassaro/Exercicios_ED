#include <stdio.h>
#include "vector.h"

int main()
{
    Vector *v1, *v2;

    v1 = vector_construct();
    v2 = vector_construct();

    for(int i=0; i<10; i++)
        vector_push_back(v1, i);

    vector_set(v1, 0, 10);
    vector_set(v1, 6, -1024);
    vector_set(v2, 8, 34);
    
    //5
    // printf("%d\n", vector_size(v1));
    // printf("%d\n", (int)vector_get(v1, 6));
    // printf("%d\n", (int)vector_get(v1, 4));

    //6
    // printf("%d\n", vector_find(v1, 10));

    //7
    // printf("%d\n", (int)vector_max(v1));
    // printf("%d\n", (int)vector_min(v1));
    // printf("%d\n", (int)vector_argmax(v1));
    // printf("%d\n", (int)vector_argmin(v1));

    //8
    // printf("%d\n", (int)vector_remove(v1, 6));
    // printf("%d\n", (int)vector_pop_back(v1));
    // printf("%d\n", (int)vector_pop_front(v1));
    // printf("%d\n", vector_size(v1));

    //9
    // vector_insert(v1, 5, 80);
    // printf("%d\n", vector_size(v1));

    //10
    

    vector_destroy(v1);
    vector_destroy(v2);

    return 0;
}