#ifndef CITY_HOPPING_H_
#define CITY_HOPPING_H_

typedef struct city City;
typedef struct path Path;

City* city_construct();
void city_destroy(void* stuff);

#endif