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

void DFS_fn(){

    /*
    pegando a ultima cidade da fronteira, passando ela como visitada (se ja nao foi previamente),
    e adicionando os vizinhos dessa cidade como fronteira para serem avaliadas nas proximas iteracoes
    */

    


}

void BFS_fn(){

}

void UCS_fn(){

}

void A_STAR_fn(){

}

//-------------------------------------------------------------------------------------------//

Path* do_the_hopping(Vector* cities, int search_type, int n_cities){

    Vector* path = vector_construct(free, n_cities);

    // Vector* frontiers = vector_construct(free, INIT_VALUE);
    
    //adicionando a cidade de origem nas fronteiras
    vector_push_back(frontier, vector_get(cities, 0)); //criar e inic vetor fronteira e visitados fora das fn de busca/ passar vetores como parametro

    while(path->f_amount > 0){

        switch(search_type){

            case DFS:

                break;

            case BFS:

                break;

            case UCS:

                break;

            case A_STAR:

                break;

            deafult:
                printf("Invalid search algorithm. Terminate program.\n\n");
                return;
        }

    }

    printf("Unable to reach target. Terminate program.\n\n");
}