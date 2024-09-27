#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "binary_tree.h"

int hash_str(HashTable *h, void *data)
{
    char *str = (char *)data;

    long hash_val = 0;
    int base = 127;

    for (size_t i = 0; i < strlen(str); i++)
        hash_val = (base * hash_val + str[i]) % hash_table_size(h);

    return hash_val;
}

int cmp_str(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

void key_destroy_fn(void *key)
{
    free(key);
}

void val_destroy_fn(void *val)
{
    free(val);
}

int main()
{

    BinaryTree* bt = binary_tree_construct(cmp_str, key_destroy_fn, val_destroy_fn);

    binary_tree_add(bt, strdup("e"), strdup("5"));
    binary_tree_add(bt, strdup("c"), strdup("3"));
    binary_tree_add(bt, strdup("a"), strdup("1"));
    binary_tree_add(bt, strdup("b"), strdup("2"));
    binary_tree_add(bt, strdup("f"), strdup("6"));
    binary_tree_add(bt, strdup("d"), strdup("4"));
    binary_tree_add(bt, strdup("i"), strdup("9"));
    binary_tree_add(bt, strdup("g"), strdup("7"));
    binary_tree_add(bt, strdup("h"), strdup("8"));

    binary_tree_print(bt->root);


    binary_tree_remove(bt, "e");
    binary_tree_remove(bt, "c");
    binary_tree_remove(bt, "a");
    binary_tree_remove(bt, "b");
    binary_tree_remove(bt, "f");
    binary_tree_remove(bt, "d");
    binary_tree_remove(bt, "i");
    binary_tree_remove(bt, "g");
    binary_tree_remove(bt, "h");


    binary_tree_destroy(bt);

    return 0;
}
