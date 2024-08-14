#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(){

    int n = 0;
    scanf("%d", &n);

    int a = 0;

    scanf(" %d", &a);

    Node** nodes = calloc(100, sizeof(Node*));
    nodes[0] = node_construct(a, NULL);

    for(int i=1; i<n; i++){

        scanf(" %d", &a);
        nodes[i] = node_construct(a, nodes[i-1]);
    }

    for(int j=n-1; j>=0; j--){

        printf("%d\n", nodes[j]->value);
        node_destroy(nodes[j]);
    }

    free(nodes);

    return 0;
}