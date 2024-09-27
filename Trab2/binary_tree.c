#include "binary_tree.h"

KeyValPair *key_val_pair_construct(void *key, void *val){
    
    KeyValPair* kvp = calloc(1, sizeof(KeyValPair));

    kvp->key = key;
    kvp->value = val;

    return kvp;
}

void key_val_pair_destroy(KeyValPair *kvp){
    
    free(kvp->key);
    free(kvp->value);
    free(kvp);
    kvp = NULL;
}


Node *bt_node_construct(void *key, void *value, Node *left, Node *right){
    
    Node* new_node = calloc(1, sizeof(Node));

    new_node->key = key;
    new_node->value = value;
    new_node->left = left;
    new_node->right = right;

    return new_node;
}

void bt_node_destroy(Node *node){
    
    printf("destroying node\nkey: %s\nvalue: %s\n", (char*)node->key, (char*)node->value);
    free(node->key);
    free(node->value);
    free(node);
    node = NULL;
}


BinaryTree *binary_tree_construct(CmpFn cmp_fn, KeyDestroyFn key_destroy_fn, ValDestroyFn val_destroy_fn){
    
    BinaryTree* bt = calloc(1, sizeof(BinaryTree));

    bt->cmp_fn = cmp_fn;
    bt->key_destroy_fn = key_destroy_fn;
    bt->val_destroy_fn = val_destroy_fn;
    bt->root = NULL;

    return bt;
}

void binary_tree_add(BinaryTree *bt, void *key, void *value){
    
    Node* new_node = bt_node_construct(key, value, NULL, NULL);

    if(bt->root == NULL){
        bt->root = new_node;
    }
    
    else{

        Node* current = bt->root;
        Node* parent = NULL;

        while(1){

            parent = current;

            if(bt->cmp_fn(key, current->key) > 0){
                current = current->right;

                if(current == NULL){
                    parent->right = new_node;
                    return;
                }
            }

            else{
                current = current->left;

                if(current == NULL){
                    parent->left = new_node;
                    return;
                }
            }
        }
    }

}

void binary_tree_add_recursive(BinaryTree *bt, void *key, void *value){
    
}

int binary_tree_empty(BinaryTree *bt){
    
}

static void node_swap(Node* n1, Node* n2){

    void* aux_key = n1->key;
    void* aux_value = n1->value;

    n1->key = n2->key;
    n1->value = n2->value;

    n2->key = aux_key;
    n2->value = aux_value;
}

void binary_tree_remove(BinaryTree *bt, void *key){
    
    Node* current = bt->root;
    Node* parent = NULL;
    int bigger_or_smaller = -1;

    if(current == NULL){
        return;
    }  

    //acha o filho pela chave e guarda a posicao em relacao ao pai
    while(bt->cmp_fn(key, current->key)){

        parent = current;

        if(bt->cmp_fn(key, current->key) > 0){
            current = current->right;
            bigger_or_smaller = 1;
        }

        else{
            current = current->left;
            bigger_or_smaller = 0;
        }

        if(current == NULL){
            return;
        }
    }

    //caso nao tenha filhos
    if(current->left == NULL && current->right == NULL){

        bt_node_destroy(current);

        if(parent == NULL){
            bt->root = NULL;
            return;
        }

        if(bigger_or_smaller){
            parent->right = NULL;
        }

        else{
            parent->left = NULL;
        }
    }

    //caso tenha filhos na esquerda
    else if(current->right == NULL){
        
        if(parent == NULL){
            bt->root = current->left;
            return;
        }

        else if(bigger_or_smaller){
            parent->right = current->left;
        }

        else{
            parent->left = current->left;
        }

        bt_node_destroy(current);
    }

    //caso tenha filhos na direita
    else if(current->left == NULL){
        
        if(parent == NULL){
            bt->root = current->right;
            return;
        }

        else if(bigger_or_smaller){
            parent->right = current->right;
        }

        else{
            parent->left = current->right;
        }

        bt_node_destroy(current);
    }

    //caso tenha filhos na direita e esquerda
    else{

        Node* successor = current->right;
        Node* successor_parent = current;
        Node* aux = NULL;

        while(successor->left != NULL){
            successor_parent = successor;
            successor = successor->left;
        }

        //caso em que o sucessor eh o imediatamente a direita do current
        if(successor == current->right){
            current->right = successor->right;
        }

        else{
            aux = successor->right;
            successor_parent->left = aux;
        }

        //troco apenas os conteudos do sucessor que agora está solto da árvore, com o current que quero remover
        //pra nao ter q me preocupar com redirecionar os filhos dos pais de todo mundo e etc.
        node_swap(current, successor);
        bt_node_destroy(successor);
    }
}

KeyValPair *binary_tree_min(BinaryTree *bt){
    
    Node* current = bt->root;

    if(current == NULL){
        return NULL;
    }

    while(current->left != NULL){
        current = current->left;
    }

    return key_val_pair_construct(current->key, current->value);
}

KeyValPair *binary_tree_max(BinaryTree *bt){
    
    Node* current = bt->root;

    if(current == NULL){
        return NULL;
    }

    while(current->right != NULL){
        current = current->right;
    }

    return key_val_pair_construct(current->key, current->value);
}

KeyValPair *binary_tree_pop_min(BinaryTree *bt){
    

}

KeyValPair *binary_tree_pop_max(BinaryTree *bt){
    
}

void *binary_tree_get(BinaryTree *bt, void *key){
    
}

void binary_tree_print(Node* root){

    Node* current = root;

    printf("(");
    printf("%s %s\n", (char*)current->key, (char*)current->value);
    
    if(current->left != NULL) binary_tree_print(current->left);
    if(current->right != NULL) binary_tree_print(current->right);

    printf(")");
}

void binary_tree_destroy(BinaryTree *bt){
    
    Node* current = bt->root;


    free(bt);
    bt = NULL;
}
