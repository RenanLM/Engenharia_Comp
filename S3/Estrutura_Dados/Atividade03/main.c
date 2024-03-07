#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Coordenadas {

  float x;
  float y;
};

typedef struct Coordenadas TCoordenadas;

float distancia(TCoordenadas *p1, TCoordenadas *p2) {
  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  return sqrt((dx * dx) + (dy * dy));
}

int main(void) {
  
  int n;
  float somaDistancias = 0.0;
  
  printf("Quantas pontos XY você deseja calcular?\n");
  scanf("%d", &n);
  if(n < 1){
    printf("Entrada inválida\n");
    return -1;
  }
    
  TCoordenadas *vetPontos[n];

  for (int i = 0; i < n; i++) {
    vetPontos[i] = (TCoordenadas *)malloc(sizeof(TCoordenadas));
    printf("Digite as coordenadas (x y) para o ponto %d: ", i + 1);
    scanf("%f %f", &(vetPontos[i]->x), &(vetPontos[i]->y));
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      float d = distancia(vetPontos[i], vetPontos[j]);
      somaDistancias += d;
      printf("Distância entre ponto %d e ponto %d: %.2f\n", i + 1, j + 1, d);
    }
  }

  printf("Soma de todas as distâncias: %.2f\n", somaDistancias);

  for (int i = 0; i < n; i++) {
    free(vetPontos[i]);
  }

  return 0;
}