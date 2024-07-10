#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILA 20

typedef struct{

    int id;
    float timestamp;

}Video;

int main(){

    char comando[10], http[50];
    int id;
    float timestamp;

    Video fila[MAX_FILA];
    int inicio = 0, fim = 0, tamanho = 0;

    int n = 0 ;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf(" %s", comando);
        if(!strcmp(comando, "ADICIONAR")){
            scanf(" %s %d %f", http, &id, &timestamp);

            if(tamanho < MAX_FILA){

                //insercao fim do array circ
                fila[fim].id = id;
                fila[fim].timestamp = timestamp;

                fim = (fim + 1) % MAX_FILA;
                tamanho++;
            }

            else printf("FILA CHEIA\n");
        }

        else if(!strcmp(comando, "PLAY")){

            if(tamanho > 5){

                //remocao comeco do array circ
                
                for(int j=0; j<tamanho; j++){

                    printf("ID: %d, Timestamp: %.2f\n", fila[inicio].id, fila[inicio].timestamp);
                    inicio = (inicio + 1) % MAX_FILA;
                }

                    tamanho = 0;
            }

            else printf("AGUARDE\n");
        }
    }


    return 0;
}