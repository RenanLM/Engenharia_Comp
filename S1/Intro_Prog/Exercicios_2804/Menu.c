#include <stdio.h>

int main(){

    char op = '\0';

    do {

        printf("BLUEN PEN CALC\n\n1 - Soma de dois numeros\n2 - Produto de dois numeros\n3 - Fatorial de um numero\n4 - Sair\n");

        printf("Select: ");
        scanf("%c", &op);

        if(!(op >= '1' && op <= '4')){
            printf("Op. Invalido!");
            continue;
        }

        switch (op) {
            case '1':
                int a, b;
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                getchar();
                printf("Resultado: %d\n", a + b);
                break;

            case '2':
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                getchar();
                printf("Resultado: %d\n", a * b);
                break;

            case '3':
                int n, f = 1;
                printf("Digite o numero: ");
                scanf("%d", &n);
                getchar();
                for(int i = 1; i <= n; f = f * i++);
                printf("Resultado: %d\n", f);
                break;
        }

    } while (op != '4');

}
