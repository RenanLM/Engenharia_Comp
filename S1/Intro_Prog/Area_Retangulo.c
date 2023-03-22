#include <stdio.h>

int main(){

    float base = 0, altura = 0, area = 0;

    printf("==============================\n");
    printf("=====Area do Retangulo========\n\n");

    printf("Digite o valor da base do retangulo: ");
    scanf("%f", &base);

    printf("Agora, digite o valor da altura: ");
    scanf("%f", &altura);

    area = base * altura;

    printf("==============================\n");
    printf("A area do seu retangulo e: %.2f", area);

    return 0;

}
