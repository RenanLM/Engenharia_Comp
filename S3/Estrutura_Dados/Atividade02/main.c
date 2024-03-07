#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Coordenadas {

  float x;
  float y;
};

typedef struct Coordenadas TCoordenadas;

void distancia(TCoordenadas *p1, TCoordenadas *p2) {
  float dx = p2->x - p1->x;
  float dy = p2->y - p1->y;
  
  float distancia = sqrt((dx * dx) + (dy * dy));
  printf("A distancia entre os pontos é: %.2f\n", distancia);
}

float *pontoMedio(TCoordenadas *p1, TCoordenadas *p2) {

  float p1x = p1->x;
  float p1y = p1->y;

  float p2x = p2->x;
  float p2y = p2->y;

  float pontoMedioX = ((p1x + p2x) / 2);
  float pontoMedioY = ((p1y + p2y) / 2);

  float *pontoMedio = (float *)malloc(2 * sizeof(float));
  pontoMedio[0] = pontoMedioX;
  pontoMedio[1] = pontoMedioY;
  // printf("O ponto médio é: (%.2f, %.2f)\n", pontoMedioX, pontoMedioY);

  return pontoMedio;
}

int main(void) {

  TCoordenadas p1;
  TCoordenadas p2;
  float *resultado;

  p1.x = 4.0;
  p1.y = 3.0;
  p2.x = 2.0;
  p2.y = -3.0;

  resultado = pontoMedio(&p1, &p2);
  printf("O ponto médio é: (%.2f , %.2f)\n", resultado[0], resultado[1]);
  distancia(&p1, &p2);

  free(resultado);

  return 0;
}