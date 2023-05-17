#include <stdio.h>

int main(){

    int n = 0;

    printf("Digite um numero: ");
    scanf("%d", &n);

    int bit1 = 0;
    int bit0 = 0;
    int aux = 0;

    for(int i = 0; i < sizeof(int); i++){

        aux = (n >> i) & 1;

        if(aux == 1)
            bit1++;

        else
            bit0++;

    }

    printf("O numero de bits 1 no numero e: %d\n e o numero de bits 0 e: %d", bit1, bit0);

    return 0;
}
