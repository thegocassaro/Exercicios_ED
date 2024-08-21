#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node *node_construct(data_type value, Node *next){

    Node* node = (Node*)calloc(1, sizeof(Node));
    node->value = value;
    node->next = next;

    return node;
}

data_type node_value(Node *node){

    return node->value;
}

Node *node_next(Node *node){

    return node->next;
}

void node_destroy(Node *n){

    free(n);
    n = NULL;
}
