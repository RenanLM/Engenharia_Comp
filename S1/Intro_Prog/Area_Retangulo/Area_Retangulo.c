#include <stdio.h>

int main(){

    //Declaração das variaveis

    float base = 0, altura = 0, area = 0;

    //Apresentação do programa

    printf("==============================\n");
    printf("=====Area do Retangulo========\n\n");

    //Leitura dos valores base e altura

    printf("Digite o valor da base do retangulo: ");
    scanf("%f", &base);

    printf("Agora, digite o valor da altura: ");
    scanf("%f", &altura);

    //Calculo e impressão do valor da area

    area = base * altura;

    printf("==============================\n");
    printf("A area do seu retangulo e: %.2f", area);

    return 0;

}
