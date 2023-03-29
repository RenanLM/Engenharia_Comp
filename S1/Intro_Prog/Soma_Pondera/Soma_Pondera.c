#include <stdio.h>

//Função Principal

int main(){

    //Declaração de variáveis

    int num1 = 0, num2 = 0, soma = 0;

    //Leitura das variáveis

    printf("========================\n");
    printf("Digite um numero: ");
    scanf("%d", &num1);
    printf("========================\n");
    printf("Digite outro numero: ");
    scanf("%d", &num2);

    //Condições para o calculo da soma

    num1 = !(num1 % 2) ? num1 * 2 : num1 * 3;
    num2 = !(num2 % 2) ? num2 * 2 : num2 * 3;

    //Calculo da soma e impressao do valor soma

    soma = num1 + num2;

    printf("A soma ponderada dos numeros digitados resultou em: %d", soma);

}
