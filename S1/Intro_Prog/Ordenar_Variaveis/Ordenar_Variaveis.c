#include <stdio.h>

int main(){

//Declaracao de variaveis n1, n2, n3 e aux.

    int n1 = 0, n2 = 0, n3 = 0, aux = 0;

//Leitura das variaveis

        printf("Digite o primeiro valor: ");
        scanf("%i", &n1);

        printf("Digite o segundo valor: ");
        scanf("%i", &n2);

        printf("Digite o terceiro valor: ");
        scanf("%i", &n3);

//Condicoes para a ordenacao das variaveis

        if (n1 <= n2 && n1 <= n3 && n2 <= n3){

            printf(" %i, %i, %i", n1, n2, n3);

        } else if(n1 <= n2 && n1 <= n3 && n3 <= n2){

            aux = n2;
            n2 = n3;
            n3 = aux;

            printf(" %i, %i, %i", n1, n2, n3);

        } else if(n2 <= n1 && n2 <= n3 && n1 <= n3){

            aux = n1;
            n1 = n2;
            n2 = aux;

            printf(" %i, %i, %i", n1, n2, n3);

        } else if(n2 >= n1 && n2 >= n3 && n3 <= n1){

            aux = n2;
            n2 = n1;
            n1 = n3;
            n3 = aux;

            printf(" %i, %i, %i", n1, n2, n3);

        } else if(n1 >= n2 && n1 >= n3 && n3 <= n2){

            aux = n1;
            n1 = n3;
            n3 = aux;

            printf(" %i, %i, %i", n1, n2, n3);

        } else if (n1 >= n2 && n1 >= n3 && n2 <= n3){

            aux = n1;
            n1 = n2;
            n2 = n3;
            n3 = aux;

            printf(" %i, %i, %i", n1, n2, n3);

        }

    return 0;

}
