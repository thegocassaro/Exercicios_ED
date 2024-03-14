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
    vector_set(v1, 2, -5);
    vector_set(v1, 6, -1024);
    vector_set(v2, 8, 34);
    vector_set(v2, 4, 70);

    vector_destroy(v1);
    vector_destroy(v2);

    return 0;
}