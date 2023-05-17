#include <stdio.h>

int main(){

    int n = 0;
    int a = 1;
    int b = 1;
    int c = 0;

    printf("Digite o numero de elementos da sequencia: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("%d\t", a);
        c = a + b;
        a = b;
        b = c;

    }

    return 0;
}
