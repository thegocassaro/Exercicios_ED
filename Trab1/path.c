#include "path.h"

#define INIT_VALUE 20

struct path{

    int origin_city;
    int destiny_city;
    float distance;
};

int choose_search_type(char* algorithm){

    if(!strcmp(algorithm, "DFS")) return DFS;
    if(!strcmp(algorithm, "BFS")) return BFS;
    if(!strcmp(algorithm, "UCS")) return UCS;
    if(!strcmp(algorithm, "A*")) return A_STAR;

    return -1;
}

void DFS_fn(Vector* frontiers, Vector* visited, int* n_frontiers, int* n_visited){

    /*
    pegando a ultima cidade da fronteira, passando ela como visitada (se ja nao foi previamente),
    e adicionando os vizinhos dessa cidade como fronteira para serem avaliadas nas proximas iteracoes
    */

    
   *n_frontiers += 

}

void BFS_fn(){

}

void UCS_fn(){

}

void A_STAR_fn(){

}

//-------------------------------------------------------------------------------------------//

Path* do_the_hopping(Vector* cities, int search_type, int n_cities){

    Vector* path = vector_construct(free, INIT_VALUE);

    Vector* frontiers = vector_construct(free, INIT_VALUE);
    Vector* visited = vector_construct(free, INIT_VALUE);
    int n_frontiers = 1, n_visited = 0;
    
    //adicionando a cidade de origem nas fronteiras
    vector_push_back(frontiers, vector_get(cities, 0)); //criar e inic vetor fronteira e visitados fora das fn de busca/ passar vetores como parametro

    while(n_frontiers > 0){

        switch(search_type){

            case DFS:
                DFS_fn(frontiers, visited, &n_frontiers, &n_visited);
                break;

            case BFS:

                break;

            case UCS:

                break;

            case A_STAR:

                break;

            default:
                printf("Invalid search algorithm. Terminate program.\n\n");
                return;
        }

    }

    printf("Unable to reach target. Terminate program.\n\n");
}