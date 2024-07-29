#include <stdio.h>
#include <stdlib.h>
#include "city.h"
#include "path.h"
#include "vector.h"

int main(){

    char algorithm[5];
    int origin_idx = 0, destiny_idx = 0, m = 0;

    scanf(" %s", algorithm);
    scanf(" %d %d", &origin_idx, &destiny_idx);
    scanf(" %d", &m);

    int search_type = choose_search_type(algorithm);
    Vector* cities = vector_construct(city_destroy, m);

    city_read_all(cities, m);

    

    vector_destroy(cities);

    return 0;
}