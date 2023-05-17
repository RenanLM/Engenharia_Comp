#include <stdio.h>

int main(){

    int maior = 0;
    int menor = 0;
    int somaPar = 0;
    int somaImpar = 0;
    int n = 0;

    for(int i = 0; i < 10; i++){

        printf("Digite um numero: ");
        scanf("%d", &n);

        if(i == 0 || n > maior)
            maior = n;
        if(i == 0 || n < menor)
            menor = n;
        if(!(n % 2))
            somaPar += n;
        if(n % 2)
            somaImpar += n;

    }

    printf("O maior numero e: %d\n", maior);
    printf("O menor numero e: %d\n", menor);
    printf("A soma dos numeros pares e: %d\n", somaPar);
    printf("A soma dos numeros impares e: %d\n", somaImpar);

}
