#include <stdio.h>

int main(){

    int n = 0, count = 0;

    printf("Digite um numero: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        if(!(n % i))
            count++;
    }

    if(count == 2)
        printf("O numero eh primo!");
    else
        printf("O numero nao eh primo!");

    return 0;

}
