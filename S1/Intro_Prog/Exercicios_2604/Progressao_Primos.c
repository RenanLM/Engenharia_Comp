#include <stdio.h>

int main(){

    int n = 100, count = 0, j = 1, c = 0;

    //printf("Digite a quantidade de numeros primos desejada: ");
    //scanf("%d", &n);

    while(c < n){

        count = 0;

        for(int i = 1; i <= j; i++){
            if(!(j % i))
                count++;
            }

        if(count == 2){
            c++;
            if(c > 10)
                printf("%d\t", j);
        }

        j++;

    }

    return 0;

}
