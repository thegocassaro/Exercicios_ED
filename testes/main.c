#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10
#define START 5

void calcula_erro_porcentagem(){

    float medido, nominal;

    for(int i=0; i<12; i++){

        scanf(" %f %f", &medido, &nominal);
        printf("%.2f\n", (medido - nominal) / nominal * 100);

    }
}

int main(){

    printf("%d", 1%10);

    return 0;
}