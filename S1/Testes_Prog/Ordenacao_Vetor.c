#include <stdio.h>

int vetor[10], aux;

int main(){

    for(int i = 0; i < 15; ++i) {
        printf("Digite o numero %i do vetor: ", i);
        scanf("%i", &vetor[i]);
    }


    for(int x = 0; x < 15; ++x){
        for(int y = x; y < 15; y++){
            if(vetor[x] > vetor[y]){
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
            }
        }
    }

    for(int i = 0; i < 15; ++i){
        printf("Numero %i e: %i \n", i, vetor[i]);
    }
}
