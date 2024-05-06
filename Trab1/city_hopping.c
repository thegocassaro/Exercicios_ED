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

void do_the_hopping(Path* path, int search_type){

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