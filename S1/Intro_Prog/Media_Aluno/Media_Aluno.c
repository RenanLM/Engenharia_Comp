#include <stdio.h>

//Declaração da função main e variaveis

int main(){

    float p1 , p2 = 0, p3 = 0, p4 = 0, media = 0;

//Leitura das notas

    printf("================================\n");

    printf("Digite a nota da prova 1: ");
    scanf("%f", &p1);
    printf("\n");

    printf("================================\n");

    printf("Digite a nota da prova 2: ");
    scanf("%f", &p2);
    printf("\n");

    printf("================================\n");

    printf("Digite a nota da prova 3: ");
    scanf("%f", &p3);
    printf("\n");

    printf("================================\n");

    printf("Digite a nota da prova 4: ");
    scanf("%f", &p4);
    printf("\n");

//Condições do cálculo da media

    media = ((2*((p1 + p2)/2)) + (3*((p3 + p4)/2)))/5;
    printf("================================================================\n");
    printf("O aluno esta %s", (media < 3 ? "reprovado" : (media < 7 ? "de prova final" : "aprovado")))
		    && printf(" e a sua media final foi %.2f\n", media);
    printf("================================================================");
}
