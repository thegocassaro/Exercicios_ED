#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILA 10

typedef struct{

    char nome[50], cpf[50];

}Atendimento;

int main(){

    char comando[10], nome[50], cpf[50];

    Atendimento fila[MAX_FILA];
    int inicio = 0, fim = 0, tamanho = 0;

    int n = 0 ;

    scanf("%d", &n);
    for(int i=0; i<n; i++){

        scanf(" %s", comando);
        if(!strcmp(comando, "ADICIONAR")){
            scanf(" %s %s", nome, cpf);

            if(tamanho < MAX_FILA){

                //insercao fim do array circ
                strcpy(fila[fim].cpf, cpf);
                strcpy(fila[fim].nome, nome);

                fim = (fim + 1) % MAX_FILA;
                tamanho++;
            }

            else printf("FILA CHEIA\n");
        }

        else if(!strcmp(comando, "CHAMAR")){

            if(tamanho > 0){

                //remocao comeco do array circ
                printf("%s\n", fila[inicio].nome);
                inicio = (inicio + 1) % MAX_FILA;
                tamanho--;
            }

            else printf("FILA VAZIA\n");
        }
    }


    return 0;
}