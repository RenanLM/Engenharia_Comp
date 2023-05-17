#include <stdio.h>

int main(){

    int n = 0, fat_ant = 1;
    float s = 0;

    printf("Digite um valor: ");
    scanf("%d", &n);

    /*for(int i = 1; i <= n; i++){
        p *= i;
    }
    print("%d", p);*/

    for(int i = 2; i <= n; i++){

        s += 2 * (float)i;

        s = s / (float)((fat_ant * i) * fat_ant);

        fat_ant *= i;

    }

    printf("%f", s);

    return 0;

}
