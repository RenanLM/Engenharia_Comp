#include <stdio.h>
#include <string.h>
#define MAX_VECTOR 100
#define MAX_LIN 10
#define MAX_COL 10

void memoryDump(void *data, int size, int typeSize) {
  char *pointer;
  int i;
  pointer = data;
  for (i = 0; i < size; i++) {
    if(!(i % typeSize))
      printf("------------------------------\n");
    printf("%x :: %x\n", pointer, (unsigned char)*pointer);
    pointer += (typeSize);
  }

  printf("\n");
}

int main(void) {

  int vector[MAX_VECTOR];
  int matriz[MAX_LIN][MAX_COL];
  int i;

  memset(vector, 0x0A, MAX_VECTOR * sizeof(vector[0]));
  memset(matriz, 0x00, MAX_LIN * MAX_COL * sizeof(vector[0]));
  
  printf("Vector com memset:\n");
  memoryDump(vector, MAX_VECTOR, sizeof(vector[0]));
  
  printf("Matriz com memset:\n");
  memoryDump(matriz, MAX_LIN * MAX_COL, sizeof(matriz[0][0]));

  memcpy(matriz, vector, MAX_VECTOR * sizeof(vector[0]));
  printf("Matriz com memcpy:\n");
  memoryDump(matriz, MAX_LIN * MAX_COL, sizeof(matriz[0][0]));

  
  return 0;
}