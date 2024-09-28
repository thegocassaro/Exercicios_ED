#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "doc_freq.h"
#include "indexador.h"

#define MAX_DIRECTORY_NAME_SIZE 1000

int hash_fn(HashTable *table, void *key)
{
    char *str = key;

    int table_size = hash_table_size(table);

    unsigned long hash_val = 0, base = 27183;
    unsigned long random_val = 31415;

    int size = strlen(str);

    for (int i = 0; i < size; i++)
    {
        hash_val = (hash_val * random_val + str[i]) % table_size;
        random_val = (random_val * base) % (table_size - 1);
    }

    return hash_val;
}

int cmp_str(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{

    char directory_name[MAX_DIRECTORY_NAME_SIZE];
    
    scanf("%s", directory_name);
    FILE *file = fopen(directory_name, "r");

    int n_docs = 0;
    int n_words = 0;
    char doc_name[MAX_DOCUMENT_NAME_SIZE];

    fscanf(file, "%d\n", &n_docs);

    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    Indexador* idx = indexador_construct(919, hash_fn, cmp_str);

    for(int i=0; i<n_docs; i++){

        fscanf(file, "%[^:]: %d: ", doc_name, &n_words);

        for(int j=0; j<n_words; j++){

            char word[MAX_WORD_SIZE];
            fscanf(file, "%s", word);
    
            indexador_add(idx, word, doc_name);
        }
    }

    fclose(file);

    indexador_print(idx);
    
    indexador_destroy(idx);

    return 0;
}
