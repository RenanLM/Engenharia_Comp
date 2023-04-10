#include <stdio.h>

/*Definicao de funcao "next()"
 Fiz duas funcoes para o mesmo problema*/

/*Na "next_1()" formulei para somar 2.5 ao "num" = 50, 9 vezes, e mostrar
 em sequencia*/

int next(){
    static float n = 50;
    float aux = n;
    n += 2.50;
    return aux;
}


/* Na "next_2()" formulei para toda vez que o "i" fosse verdade(1), somasse 3
 e atribuisse "0" para o mesmo, e "i" sendo falso(0), somasse 2 e atribuisse novamente "1"
 para ele, fazendo isso em sequencia e retornando "aux", que recebe o valor anterior de "n".
 */

int next_2(){

    static int n = 50;
    static int i = 0;
    int aux = n;

    if(i == 1){
        n += 3;
        i = 0;
    }
    else{
        n += 2;
        i = 1;
    }

    return aux;

}

/* Em ambos os casos são usados "static" para manter o valor usado na funcao, realizando assim
 a sequencia numerica
 */

// Funcao main com laco "for" para executar "next_1()" ou "next_2()" quantas vezes precisar

int main(){

    for(int i = 0; i < 9; i++){
       printf("%d\n", next_2());
    }
}
