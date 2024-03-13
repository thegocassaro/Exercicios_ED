#include <stdio.h>
#include "vector.h"

int main()
{
    Vector *v = vector_construct();
    vector_destroy(v);

    printf("OK!\n");

    return 0;
}