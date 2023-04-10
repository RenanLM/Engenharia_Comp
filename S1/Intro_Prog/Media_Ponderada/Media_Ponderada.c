#include <stdio.h>

//Declaracao de funcao principal e variaveis

int main(){

     int v1 = 0, v2 = 0, v3 = 0, v4 = 0;

//Leitura das variaveis
     printf("Insira abaixo os valores das notas:\n");

     printf("valor 1:");
     scanf("%d", &v1);
     printf("\n");

     printf("valor 2:");
     scanf("%d", &v2);
     printf("\n");

     printf("valor 3:");
     scanf("%d", &v3);
     printf("\n");

     printf("valor 4:");
     scanf("%d", &v4);
     printf("\n");

//Calculo da media

     float media = (v1 + (v2 * 2) + (v3 * 3) + (v4 * 4)) / 4.0;

//Impressao do resultado

     printf("A media calculada e: %.2f", media);

     return 0;

}
