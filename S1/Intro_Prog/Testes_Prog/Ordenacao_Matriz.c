#include <stdio.h>

void buble_sort(int vet[], int tam){

    for(int k = 1; k < tam; k++){
        int aux;
        for (int j = 0; j < tam - k; j++) {
            if(vet[j] > vet[j+1]) {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }

    }
}

int main(){

    int vetor[10] = {5,4,32,55,12,0,4,3,21,96};

    buble_sort(vetor,10);

    for(int i = 0; i < 10; i++){
        printf("%d", *vetor);
    }

    return 0;

}
