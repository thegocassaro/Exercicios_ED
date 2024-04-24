#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10
#define START 5

int main(){

    printf("%d\n", (START + 6) % CAPACITY);

    return 0;
}