#include "search_alg.h"

int choose_search_type(char* algorithm){

    if(!strcmp(algorithm, "DFS")) return DFS;
    if(!strcmp(algorithm, "BFS")) return BFS;
    if(!strcmp(algorithm, "UCS")) return UCS;
    if(!strcmp(algorithm, "A*")) return A_STAR;

    return -1;
}

void DFS_fn(){

}

void BFS_fn(){

}

void UCS_fn(){

}

void A_STAR_fn(){

}
