#include <stdio.h>

    //Declaracao de funcao main e variaveis

int main(){

    float n1 = 0, n2 = 0, n3 = 0;

    //Primeiro caso: o menor numero

    printf("Digite o primeiro valor: ");
    scanf("%f", &n1);
    printf("Digite o segundo valor: ");
    scanf("%f", &n2);
    printf("Digite o terceiro valor: ");
    scanf("%f", &n3);

    //Condicoes para o menor numero e impressao do mesmo

    /*if(n1 <= n2 && n1 <= n3){
        printf("%.2f e o menor numero!", n1);
    }
    else if(n2 < n3){
        printf("%.2f e o menor numero!", n2);
    }
    else{
        printf("%.2f e o menor numero!", n3);
    }

    return 0;*/

    //Segundo caso: o segundo menor numero

    if((n1 <= n2 && n1 >= n3) || (n1 <= n3 && n1 >= n2)){
        printf("%.2f e o segundo menor numero!", n1);
    }
    else if((n2 <= n1 && n2 >= n3) || (n2 <= n3 && n2 >= n1)){
        printf("%.2f e o segundo menor numero!", n2);
    }
    else if((n3 <= n1 && n3 >= n2) || (n3 <= n2 && n3 >= n1)){
        printf("%.2f e o segundo menor numero!", n3);
    }

    return 0;


}
