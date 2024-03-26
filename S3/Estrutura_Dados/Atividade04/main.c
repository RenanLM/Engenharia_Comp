#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    void *data;
    struct Item *next;
} Item;

typedef struct Lista {
    int count;
    int itemSize;
    Item *first;
    Item *current;
} Lista;

Lista *CriarLista(int itemSize) {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    if (lista == NULL) {
        printf("Erro ao alocar memória para a lista\n");
        exit(EXIT_FAILURE);
    }
    lista->count = 0;
    lista->itemSize = itemSize;
    lista->first = NULL;
    lista->current = NULL;
    return lista;
}

void DestruirLista(Lista *lista) {
    Item *current = lista->first;
    while (current != NULL) {
        Item *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(lista);
}

void InserirItem(Lista *lista, void *data) {
    Item *item = (Item*)malloc(sizeof(Item));
    if (item == NULL) {
        printf("Erro ao alocar memória para o item\n");
        exit(EXIT_FAILURE);
    }
    item->data = malloc(lista->itemSize);
    if (item->data == NULL) {
        printf("Erro ao alocar memória para os dados do item\n");
        exit(EXIT_FAILURE);
    }
    memcpy(item->data, data, lista->itemSize);
    item->next = NULL;

    if (lista->first == NULL) {
        lista->first = item;
    } else {
        Item *current = lista->first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = item;
    }
    lista->count++;
}

void DeletarUltimoItem(Lista *lista) {
    if (lista->first == NULL) {
        return;
    }
    Item *prev = NULL;
    Item *current = lista->first;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        lista->first = NULL;
    }
    free(current->data);
    free(current);
    lista->count--;
}

Item *FirstItem(Lista *lista) {
    lista->current = lista->first;
    return lista->current;
}

Item *NextItem(Lista *lista) {
    if (lista->current != NULL) {
        lista->current = lista->current->next;
    }
    return lista->current;
}

int main() {
  Lista *lista = CriarLista(sizeof(char*));
  char *strings[] = {"apple", "banana", "orange", "grape", "watermelon"};
  int i;
  for (i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
      InserirItem(lista, &strings[i]);
  }

  printf("Elementos da lista:\n");
  Item *item = FirstItem(lista);
  while (item != NULL) {
      char *data = *(char**)item->data;
      printf("%s ", data);
      item = NextItem(lista);
  }
  printf("\n");

  DeletarUltimoItem(lista);

  printf("Elementos da lista após deletar o último item:\n");
  item = FirstItem(lista);
  while (item != NULL) {
      char *data = *(char**)item->data;
      printf("%s ", data);
      item = NextItem(lista);
  }
  printf("\n");

  DestruirLista(lista);

  return 0;
}
