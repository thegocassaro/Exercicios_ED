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

//LIFO //retorna 1 ao chegar na cidade de destino
int DFS_fn(Vector* cities, Vector* frontiers, Vector* visited){

    //pegando a ultima cidade da fronteira, passando ela como visitada e adicionando os
    //vizinhos dessa cidade como fronteira para serem avaliadas nas proximas iteracoes
    City* visited_city = vector_remove(frontiers, vector_get(frontiers, vector_size(frontiers) - 1));

    //ignorando processo caso a cidade ja tenha sido visitada
    for(int i=0; i<vector_size(visited); i++){

        if(!strcmp(city_get_name(visited_city), city_get_name(vector_get(visited, i))))
            return 0;
    }

    vector_push_back(visited, visited_city);

    //verificando se chegamos na cidade alvo
    if(!strcmp(city_get_name(visited_city), city_get_name(vector_get(cities, vector_size(cities)))))
        return 1;

    for(int i=0; i<city_get_n_neighbors(visited_city); i++){

        vector_push_back(frontiers, vector_get(cities, city_get_idx_neighbors(visited_city, i)));
    }

    return 0;
}

//FIFO
int BFS_fn(Vector* cities, Vector* frontiers, Vector* visited){

    //pegando a primeira cidade da fronteira, passando ela como visitada e adicionando os
    //vizinhos dessa cidade como fronteira para serem avaliadas nas proximas iteracoes
    City* visited_city = vector_remove(frontiers, vector_get(frontiers, 0));

    //ignorando processo caso a cidade ja tenha sido visitada
    for(int i=0; i<vector_size(visited); i++){

        if(!strcmp(city_get_name(visited_city), city_get_name(vector_get(visited, i))))
            return 0;
    }

    vector_push_back(visited, visited_city);

    //verificando se chegamos na cidade alvo
    if(!strcmp(city_get_name(visited_city), city_get_name(vector_get(cities, vector_size(cities)))))
        return 1;

    for(int i=0; i<city_get_n_neighbors(visited_city); i++){

        vector_push_back(frontiers, vector_get(cities, city_get_idx_neighbors(visited_city, i)));
    }

    return 0;
}

int UCS_fn(){

}

int A_STAR_fn(){

}

//-------------------------------------------------------------------------------------------//

Path* do_the_hopping(Vector* cities, int search_type){

    Vector* path = vector_construct(free, INIT_VALUE);

    Vector* frontiers = vector_construct(city_destroy, INIT_VALUE);
    Vector* visited = vector_construct(city_destroy, INIT_VALUE);

    int made_it = 0;
    
    //adicionando a cidade de origem nas fronteiras
    vector_push_back(frontiers, vector_get(cities, 0));

    while(vector_size(frontiers) > 0){

        switch(search_type){

            case DFS:
                made_it = DFS_fn(cities, frontiers, visited);

                if(made_it) build_path(path);

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

void build_path(){

    /*
    construir o caminho precorrido a partir do vetor das cidades visitadas(ulima cidade visitada eh a cidade alvo), 
    verificando seus pais. na dfs e bfs nao vai dar problema ter mais de um pai, pois o primeiro caminho possivel 
    percorrido a chegar no destino vai ser sempre a resposta correta e ponto, ja na ucs e a*, vai ser preciso escolher
    o melhor pai de acordo com a distancia e tal
    */
}