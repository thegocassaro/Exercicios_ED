#ifndef PATH_H_
#define PATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "city.h"

typedef struct path Path;

enum{BFS, DFS, UCS, A_STAR};



Path* do_the_hopping(Vector* cities, int search_type);

#endif