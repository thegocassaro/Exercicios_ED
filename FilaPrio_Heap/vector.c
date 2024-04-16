#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector
{
    data_type *data;
    int size;
    int allocated;
    fp_destroy free_data;
};

// Aloca espaço para um elemento do tipo vector e inicializa os seus atributos.
Vector *vector_construct(fp_destroy free_data){

    Vector* v = (Vector*)calloc(1, sizeof(Vector));

    v->allocated = 10;
    v->data = (data_type*)calloc(v->allocated, sizeof(data_type));
    v->free_data = free_data;

    return v;
}

// Libera o espaço reservado para o vector.
void vector_destroy(Vector *v){

    for(int i=0; i<v->size; i++){
        v->free_data(v->data[i]);
    }

    free(v->data);
    free(v);
    v = NULL;
}

// Adiciona o item dado ao final do vector e aumenta o tamanho. Aumenta a capacidade alocada se necessário.
void vector_push_back(Vector *v, data_type val){

    if(v->allocated <= v->size){

        v->allocated *= 2;
        v->data = (data_type*)realloc(v->data, sizeof(data_type) * v->allocated);
    }

    v->data[v->size] = val;
    v->size++;
}

// Retorna o número de elementos atualmente no vector.
int vector_size(Vector *v){

    return v->size;
}

// Retorna o i-ésimo elemento do vector.
data_type vector_get(Vector *v, int i){

    if(i >= 0 && i < v->size){
        return v->data[i];
    }

    printf("Oh no\n");
    exit(1);
}

// Atualiza o i-ésimo elemento do vector  para que ele passe a ter o valor val.
void vector_set(Vector *v, int i, data_type val){

    if(i >= 0 && i < v->size){
        v->data[i] = val;
    }
}

// Retorna o índice da primeira ocorrência do item no Vector ou -1 se o elemento não for encontrado.
int vector_find(Vector *v, data_type val){

    for(int i=0; i<v->size; i++){

        if(v->data[i] == val){
            return i;
        }
    }

    return -1;
}

// Retorna o maior elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
data_type vector_max(Vector *v){

    data_type the_big = v->data[0];
    int index = 0;

    for(int i=0; i<v->size; i++){

        if(v->data[i] > the_big){
            the_big = v->data[i];
            index = i;
        }
    }

    return v->data[index];
}

// Retorna o menor elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
data_type vector_min(Vector *v){

    data_type the_small = v->data[0];
    int index = 0;

    for(int i=0; i<v->size; i++){

        if(v->data[i] < the_small){
            the_small = v->data[i];
            index = i;
        }
    }

    return v->data[index];
}

// Retorna o índice do maior elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
int vector_argmax(Vector *v){

    data_type the_big = v->data[0];
    int index = 0;

    for(int i=0; i<v->size; i++){

        if(v->data[i] > the_big){
            the_big = v->data[i];
            index = i;
        }
    }

    return index;
}

// Retorna o índice do menor elemento do vector (assumindo que podemos comparar elementos usando o operador "<")
int vector_argmin(Vector *v){

    data_type the_small = v->data[0];
    int index = 0;

    for(int i=0; i<v->size; i++){

        if(v->data[i] < the_small){
            the_small = v->data[i];
            index = i;
        }
    }

    return index;
}

// Remove o i-ésimo elemento do vetor.
data_type vector_remove(Vector *v, int i){

    if(!(i >= 0 && i < v->size)){
        printf("indice invalido\n");
        exit(1);
    }

    data_type save_removed = v->data[i];

    //loop rodando do indice dado até o fim do vetor - 1, considerando o indice a ser removido
    for(i = i; i<(v->size - 1); i++){
        v->data[i] = v->data[i + 1];
    }

    v->size -= 1;

    return save_removed;
}

// Remove o primeiro elemento
data_type vector_pop_front(Vector *v){

    return vector_remove(v, 0);
}

// Remove o ultimo elemento
data_type vector_pop_back(Vector *v){

    return vector_remove(v, (v->size - 1));
}

// Insere o elemento na i-esima posicao
void vector_insert(Vector *v, int i, data_type val){

    //realoca o tam do vetor se necessario
    if(v->allocated <= v->size){

        v->allocated *= 2;
        v->data = (data_type*)realloc(v->data, sizeof(data_type) * v->allocated);
    }

    //rearranja todos os valores a frente do prestes a ser inserido
    int j=0;

    for(j = (v->size - 1); j>=i; j--){
        v->data[j + 1] = v->data[j];
    }

    v->data[j+1] = val;
    v->size++;
}

// Troca os elementos das posições i e j (i vira j e j vira i)
void vector_swap(Vector *v, int i, int j){

    data_type save_i = v->data[i];

    v->data[i] = v->data[j];
    v->data[j] = save_i;
}

// Ordena o vetor in-place (sem criar um novo vetor)
void vector_sort_ascending(Vector *v, fp_compare fn){

    int flag_swap = 0;

    for(int j=0; j<v->size; j++){

        flag_swap = 0;

        //delimito o tamanho considerando que as comparacoes sao feitas com o indice atual e o da frente, logo nao 
        //podendo passar de size - 1, alem do j, que impede uma rechecagem desnecessaria do ultimo indice de cada passagem
        for(int i=0; i<(v->size - 1 - j); i++){

            if(fn(v->data[i], v->data[i + 1]) == 1){
                vector_swap(v, i, (i+1));
                flag_swap = 1;
            }

        }

        //sai do loop caso nao haja troca na passagem atual, indicando que o vetor esta ordenado
        if(flag_swap == 0) break;

    }
}

void vector_sort_descending(Vector *v, fp_compare fn){

    int flag_swap = 0;

    for(int j=0; j<v->size; j++){

        flag_swap = 0;

        //delimito o tamanho considerando que as comparacoes sao feitas com o indice atual e o da frente, logo nao 
        //podendo passar de size - 1, alem do j, que impede uma rechecagem desnecessaria do ultimo indice de cada passagem
        for(int i=0; i<(v->size - 1 - j); i++){

            if(fn(v->data[i], v->data[i + 1]) == -1){
                vector_swap(v, i, (i+1));
                flag_swap = 1;
            }

        }

        //sai do loop caso nao haja troca na passagem atual, indicando que o vetor esta ordenado
        if(flag_swap == 0) break;

    }
}

// Retorna o indice de val usando busca binaria. Retorna -1 se nao encontrado.
int vector_binary_search(Vector *v, data_type val){

    int mid = 0;
    int first = 0, last = (v->size - 1);

    while(first <= last){

        mid = first + (last - first) / 2;

        //dividindo os intervalos de busca do vetor ao longo do loop
        if(v->data[mid] == val){
            return mid;
        }

        //testando se o valor procurado eh maior ou menor que mid e ajustando de acordo
        else if(v->data[mid] > val){
            last = mid - 1;
        }

        else{
            first = mid + 1;
        }

    }

    return -1;
}

// Inverte o vetor in-place (sem criar um novo vetor)
void vector_reverse(Vector *v){

    for(int i=0; i<(v->size/2); i++){

        vector_swap(v, i, (v->size - i - 1));
    }
}

// Cria uma cópia do vector e dos valores de seus atributos.
Vector *vector_copy(Vector *v){

    Vector* new_vector = (Vector*)calloc(1, sizeof(Vector));;

    new_vector->allocated = v->allocated;
    new_vector->size = v->size;
    memcpy(new_vector->data, v->data, sizeof(data_type) * v->allocated);

    return new_vector;
}

// Remove todos os elementos de v
void vector_clear(Vector *v){

    free(v->data);

    v->size = 0;
    v->allocated = 10;
    v->data = (data_type*)calloc(v->allocated, sizeof(data_type));
}
