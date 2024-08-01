#ifndef CITY_HOPPING_H_
#define CITY_HOPPING_H_

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef struct city City;

City* city_construct();
void city_destroy(void* stuff);
void city_read_all(Vector* cities, int m);

char* city_get_name(City* city);
float city_get_pos_x(City* city);
float city_get_pos_y(City* city);
int city_get_n_neighbors(City* city);
int city_get_idx_neighbors(City* city, int idx);
float city_get_dist_neighbors(City* city, int idx);
int city_get_n_parents(City* city);
int city_get_idx_neighbors(City* city, int idx);

#endif