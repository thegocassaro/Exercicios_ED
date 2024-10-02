#include <stdio.h>
#include <stdlib.h>

enum{SMALLER, BIGGER};

typedef struct{

    void* value;
    Node* right;
    Node* left;
} Node;

typedef struct{

    Node* head;
    int(*cmp_fn)(void*, void*);
    void(*free_fn)(void*);
    int size;
} BinTree;

void bin_tree_remove(BinTree* bt, void* val){

    Node* current = bt->head;
    Node* parent = NULL;
    int bigger_or_smaller = -1;

    if(current == NULL) return; //aqui quer dizer que a arvore esta vazia

    while(bt->cmp_fn(val, current->value)){

        parent = current;

        if(bt->cmp_fn(val, current->value) > 1){
            current = current->right;
            bigger_or_smaller = BIGGER;
        }

        else{
            current = current->left;
            bigger_or_smaller = SMALLER;
        }

        if(current == NULL) return; //aqui quer dizer que o item nao esta na arvore
    }

    //caso em que nao tenha filhos
    if(current->left == NULL && current->right == NULL){

        if(parent == NULL){
            bt->head = NULL;
        }

        else if(bigger_or_smaller == BIGGER){
            parent->right = NULL;
        }

        else{
            parent->left = NULL;
        }
    }

    //caso em que tenha um filho
    else if(current->left == NULL){

        if(parent == NULL){
            bt->head = current->right;
        }

        else if(bigger_or_smaller == BIGGER){
            parent->right = current->right;
        }

        else{
            parent->left = current->right;
        }
    }

    else if(current->right == NULL){

        if(parent == NULL){
            bt->head = current->left;
        }

        else if(bigger_or_smaller == BIGGER){
            parent->right = current->left;
        }

        else{
            parent->left = current->left;
        }
    }

    //caso em que tenha dois filhos
    else{

        Node* sucessor = current->right;
        Node* sucessor_parent = current;

        while(sucessor->left != NULL){

            sucessor_parent = sucessor;
            sucessor = sucessor->left;
        }

        if(sucessor == current->right){
            sucessor_parent->right = sucessor->right;
        }

        else{
            sucessor_parent->left = sucessor->right;
        }

        node_swap(current, sucessor);
        bt->free_fn(sucessor->value);
        free(sucessor);
        return;
    }

    bt->free_fn(current->value);
    free(current);
}

void inorder_traversal(Node* node){

    if(node == NULL) return;

    inorder_traversal(node->left);
    print_fn(node->value);
    inorder_traversal(node->right);
}