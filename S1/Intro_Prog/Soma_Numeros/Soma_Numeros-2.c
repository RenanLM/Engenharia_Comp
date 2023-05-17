#include <stdio.h>

int main(){

    int soma = 0;

    for(int i = 1; i < 4; i++){
        int aux = 0;
        for(int j = 3; j < 8; j++){
            int num = 10 * i + j;
            aux += num;
        }
        soma += aux;
        printf("Soma das colunas: %d\n", aux);
    }

    printf("Soma = %d", soma);

    return 0;

}
