#include "search_alg.h"
#include <stdio.h>
#include <stdlib.h>
#include "city_hopping.h"
#include "vector.h"

int choose_search_type(char* algorithm){

    if(!strcmp(algorithm, "DFS")) return DFS;
    if(!strcmp(algorithm, "BFS")) return BFS;
    if(!strcmp(algorithm, "UCS")) return UCS;
    if(!strcmp(algorithm, "A*")) return A_STAR;

    return -1;
}

//PASSAR PRO OUTRO .H 
void DFS_fn(Path* path, Vector* cities){

    int f_amount = get_path_info(path, F_AMOUNT, NULL);
    int v_amount = get_path_info(path, V_AMOUNT, NULL);

    /*
    pegando a ultima cidade da fronteira, passando ela como visitada (se ja nao foi previamente),
    e adicionando os vizinhos dessa cidade como fronteira para serem avaliadas nas proximas iteracoes
    */

    set_path_visited(path, get_path_info(path, FRONTIER, f_amount - 1), v_amount);
    set_path_v_amount(path, v_amount + 1);


}

void BFS_fn(){

}

void UCS_fn(){

}

void A_STAR_fn(){

}
