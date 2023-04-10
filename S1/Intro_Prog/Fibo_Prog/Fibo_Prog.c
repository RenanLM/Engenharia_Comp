#include <stdio.h>

/*Declaracao de funcao int fibo() e suas variaveis
variaveis "a" e "b" sao static, para manter o conteudo anterior
da ultima chamada da funcao, retornando assim os valores antepassados*/

int fibo(){
    static int a = 0;

    static int b = 1;

    int c = 0;
/*Nesta linha, é declarada "aux" para sempre receber o valor de "a",
visando mostrar o valor anterior que estava em "a"*/

    int aux = a;

//Formula fibo

    c = a + b;
    a = b;
    b = c;

//Mostra o valor anterior de "a", que está em "aux"

    return aux;

}

//Funcao main

int main(){

//Laco "for" para imprimir os 9 numeros pedidos

    for(int i = 0; i < 9; i++){
        printf("%d\n", fibo());
    }

}
