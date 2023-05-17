#include <stdio.h>

int main(){

    int n = 0;
    int c = 1;

    printf("Digite o numero de linhas: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        for(int aux = 0; aux < i; aux++){
            printf("%d\t", c++);
        }
        printf("\n");
    }

    return 0;

}
