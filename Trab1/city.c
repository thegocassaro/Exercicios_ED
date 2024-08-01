#include "city.h"

struct city{

    char name[30];
    float pos_x, pos_y;

    int n_neighbors;
    Vector* idx_neighbors;
    Vector* dist_neighbors;

    int n_parents;
    Vector* idx_parents;
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

char* city_get_name(City* city){
    return city->name;
}

float city_get_pos_x(City* city){
    return city->pos_x;
}

float city_get_pos_y(City* city){
    return city->pos_y;
}

int city_get_n_neighbors(City* city){
    return city->n_neighbors;
}

int city_get_idx_neighbors(City* city, int idx){
    return *(int*)vector_get(city->idx_neighbors, idx);
}

float city_get_dist_neighbors(City* city, int idx){
    return *(float*)vector_get(city->dist_neighbors, idx);
}

int city_get_n_parents(City* city){
    return city->n_parents;
}

int city_get_idx_neighbors(City* city, int idx){
    return *(int*)vector_get(city->idx_parents, idx);
}

void city_read_all(Vector* cities, int m){

    for(int i=0; i<m; i++){

        City* new_city = city_construct();

        scanf(" %s %f %f %d", new_city->name, &new_city->pos_x, &new_city->pos_y, &new_city->n_neighbors);

        new_city->idx_neighbors = vector_construct(free, new_city->n_neighbors);
        new_city->dist_neighbors = vector_construct(free, new_city->n_neighbors);

        for(int j=0; j<new_city->n_neighbors; j++){

            //talvez de ruim pelo ponteiro nao estar inicializado, acho q o valor pode acabar sendo perdido
            int* idx_aux;
            float* dist_aux;

            scanf(" %d %f", idx_aux, dist_aux);

            vector_push_back(new_city->idx_neighbors, idx_aux);
            vector_push_back(new_city->dist_neighbors, dist_aux);
        }

        vector_push_back(cities, new_city);
    }
}

void city_find_parents(Vector* cities){

    //pra cada cidade, deve haver pelo menos um pai (um ou mais caminhos pra se chegar a ela)
}