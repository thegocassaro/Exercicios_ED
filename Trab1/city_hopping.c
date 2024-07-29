#include "city_hopping.h"
#include <stdio.h>
#include <stdlib.h>
#include "search_alg.h"
#include "vector.h"

struct city{

    char name[30];
    float pos_x, pos_y;

    int n_neighbors;
    Vector* idx_neighbors;
    Vector* dist_neighbors;
};

struct path{

    Vector* frontier;
    Vector* visited;
    int f_amount, v_amount;
};

City* city_construct(){

    City* city = (City*)calloc(1, sizeof(City));

    return city;
}

void city_destroy(void* stuff){

    City* city = (City*)stuff;

    vector_destroy(city->idx_neighbors);
    vector_destroy(city->dist_neighbors);

    free(city);
}

int city_get_n_neighbors(City* city){
    return city->n_neighbors;
}

int city_get_idx_neighbors(City* city, int idx){
    return vector_get(city->idx_neighbors, idx);
}

int city_get_dist_neighbors(City* city, int idx){
    return vector_get(city->dist_neighbors, idx);
}

void city_read_all(Vector* cities, int m){

    for(int i=0; i<m; i++){

        City* new_city = city_construct();

        scanf(" %s %f %f %d", new_city->name, &new_city->pos_x, &new_city->pos_y, &new_city->n_neighbors);

        new_city->idx_neighbors = vector_construct(free, new_city->n_neighbors);
        new_city->dist_neighbors = vector_construct(free, new_city->n_neighbors);

        for(int j=0; j<new_city->n_neighbors; j++){

            int* idx_aux;
            float* dist_aux;

            scanf(" %d %f", idx_aux, dist_aux);

            vector_push_back(new_city->idx_neighbors, idx_aux);
            vector_push_back(new_city->dist_neighbors, dist_aux);
        }
    }
}

Path* path_construct(int n_neighbors){

    Path* path = (Path*)calloc(1, sizeof(Path));

    path->f_amount = 1;
    path->v_amount = 0;

    //inicializando com um valor qualquer
    path->frontier = vector_construct(city_destroy, 10);
    path->visited = vector_construct(city_destroy, 10);

    return path;
}

void path_destroy(void* stuff){

    Path* path = (Path*)stuff;

    vector_destroy(path->frontier);
    vector_destroy(path->visited);

    free(path);
}

int get_path_info(Path* path, int sel, int idx){

    switch(sel){
        case F_AMOUNT:
            return path->f_amount;
            break;
        case V_AMOUNT:
            return path->v_amount;
            break;
        case FRONTIER:
            return vector_get(path->frontier, idx);
            break;
        case VISITED:
            return vector_get(path->visited, idx);
            break;
        default:
            break;    
    }
}

void set_path_f_amount(Path* path, int val){
    path->f_amount = val;
}

void set_path_v_amount(Path* path, int val){
    path->v_amount = val;
}

void set_path_frontier(Path* path, int val, int idx){
    vector_set(path->frontier, idx, val);
}

void set_path_visited(Path* path, int val, int idx){
    vector_set(path->visited, idx, val);
}


Path* do_the_hopping(Vector* cities, int search_type){

    Path* path = path_construct(city_get_n_neighbors(vector_get(cities, 0)));

    //adicionando a cidade de origem nas fronteiras
    vector_push_back(path->frontier, vector_get(cities, 0));

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