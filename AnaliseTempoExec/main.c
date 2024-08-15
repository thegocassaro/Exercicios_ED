#include <time.h>
#include <stdlib.h>

#define N_SAMPLES 10
#define SAMPLE_SIZE 200
#define REPETITIONS 1000
#define N_CASES 3

// ./main > tempo_execucao
// N menor maior media

double get_timestamp()
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return now.tv_sec + (((double)now.tv_nsec) / 1e9);
}

int main(){

    // inicia a semente do sistema de geração
    // de números aleatórios com o instante atual.
    srand(time(NULL));

    int x = rand();

    //serao realizados 10 testes com tamanhos de vetor diferentes
    for(int i=0; i<N_SAMPLES; i++){

        //serao feitas 1000 repeticoes para cada teste
        for(int j=0; j<REPETITIONS; j++){

            //serao feitos teste para 3 casos(melhor, pior e medio)
            for(int k=0; k<N_CASES; k++){

                double start = get_timestamp();





                double end = get_timestamp();
                
                // tempo passado entre os dois pontos do código
                double dt = (end - start);

                printf("%d %f %f %f", );
            }

        }

    }

    

    

}

