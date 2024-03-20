
    // //11
    // vector_sort(v1);
    // for(int i=0; i<10; i++){
    //     printf("%d\n", (int)vector_get(v1, i));
    // }

    // //12
    // printf("%d\n", vector_binary_search(v1, 3));


#include <stdio.h>
#include <string.h>

#include "vector.h"

int main()
{
    int m, n, val;

    Vector *v;

    v = vector_construct();

    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &val);
        vector_push_back(v, val);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        printf("%d\n", vector_binary_search(v, val));
    }

    vector_destroy(v);

    return 0;
}