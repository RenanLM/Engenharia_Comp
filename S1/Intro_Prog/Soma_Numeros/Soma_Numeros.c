#include <stdio.h>

int main(){

    /*Declaracao de variaveis "n", para armazenar o valor
     digitado pelo user, e "soma", para receber o valor da sequencia de soma
     */

    int n = 0;
    int soma = 0;

    //Leitura de "n"

    printf("Digite o valor: ");
    scanf("%d", &n);

    /* Laco "for" com iterator para sequenciar a adicao e incrementar
     os valores em "soma"
     */

    for(int i = 0; i < n; i++){
        soma += (i + 1);
    }

    //Impressao dos resultados

    printf("A soma resulta em: %d", soma);

}
