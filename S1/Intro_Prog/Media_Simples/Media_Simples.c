#include <stdio.h>

//Declaracao de funcao principal e variaveis

int main(){

     int num1 = 0, num2 = 0, num3 = 0, num4 = 0;

//Leitura das variaveis
     printf("Insira abaixo os valores numéricos:\n");

     printf("num1:");
     scanf("%d", &num1);
     printf("\n");

     printf("num2:");
     scanf("%d", &num2);
     printf("\n");

     printf("num3:");
     scanf("%d", &num3);
     printf("\n");

     printf("num4:");
     scanf("%d", &num4);
     printf("\n");

//Calculo da media

     float media = (num1 + num2 + num3 + num4) / 4.0;

//Impressao do resultado

     printf("A media calculada e: %.2f", media);

     return 0;

}
