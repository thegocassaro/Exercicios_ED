#ifndef CITY_HOPPING_H_
#define CITY_HOPPING_H_

typedef struct city City;
typedef struct path Path;

enum{F_AMOUNT, V_AMOUNT, FRONTIER, VISITED};

City* city_construct();
void city_destroy(void* stuff);
int city_get_n_neighbors(City* city);
int city_get_idx_neighbors(City* city, int idx);
int city_get_dist_neighbors(City* city, int idx);
void city_read_all(Vector* cities, int m);

Path* path_construct(int n_neighbors);
void path_destroy(void* stuff);
int path_get_info(Path* path, int sel, int idx);
void path_set_f_amount(Path* path, int val);
void path_set_v_amount(Path* path, int val);
void path_set_frontier(Path* path, int val, int idx);
void path_set_visited(Path* path, int val, int idx);

Path* do_the_hopping(Vector* cities, int search_type);

#endif