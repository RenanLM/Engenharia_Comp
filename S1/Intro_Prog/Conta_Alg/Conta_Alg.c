#include <stdio.h>

int main(){
    //Declaracao de variaveis "n", "pares" e "impares"
    int n = 0;
    int pares = 0;
    int impares = 0;

    //Leitura do valor de "n"
    printf("Digite um numero: ");
    scanf("%d", &n);

    /*Laco "for" de condicao n > 0, dividindo o n por 10
     e para testar o numero da direita. Testando, fazer-se-á até
     o numero chegar a 0
     */
    for(;n > 0;){

        if(n % 2 == 0){
            pares++;
        }
        else{
            impares++;
        }

        n = n / 10;
    }

    //Impressao dos valores de "pares" e "impares"

    printf("Pares: %d e Impares: %d\n", pares, impares);

    return 0;

}
