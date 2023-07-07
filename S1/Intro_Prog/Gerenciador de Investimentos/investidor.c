#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "investidor.h"

#define ERRO_FALTA_MEMORIA (-1)
#define FALHA_ALOCACAO (-2)
#define NAO_ENCONTRADO (-3)
#define SUCESSO_ACAO 1
#define TAM 50

struct investidor* investidores[TAM];
int num_investidores = 0;

void carregar_investidores() {
    FILE* arquivo = fopen("investidores.bin", "rb+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo investidores.bin\n");
        return;
    }

    struct investidor temp;

    while (fread(&temp, sizeof(struct investidor), 1, arquivo) == 1) {
        struct investidor* novo_investidor = malloc(sizeof(struct investidor));
        memcpy(novo_investidor, &temp, sizeof(struct investidor));
        investidores[num_investidores++] = novo_investidor;
    }

    fclose(arquivo);
}

void salvar_investidores() {
    FILE* arquivo = fopen("investidores.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo investidores.bin\n");
        return;
    }

    for (int i = 0; i < num_investidores; i++) {
        fwrite(investidores[i], sizeof(struct investidor), 1, arquivo);
    }

    fclose(arquivo);
}

int inserir_investidor(struct investidor* investidor){

    int index = -1;

    for (int i = 0; i < TAM; ++i) {
        if (investidores[i] == NULL) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return ERRO_FALTA_MEMORIA;

    investidores[index] = malloc(sizeof(struct investidor));

    if (investidores[index] == NULL)
        return FALHA_ALOCACAO;

    investidores[index]->codigo = investidor->codigo;
    strcpy(investidores[index]->nome, investidor->nome);
    strcpy(investidores[index]->cpf, investidor->cpf);
    strcpy(investidores[index]->endereco, investidor->endereco);
    investidores[index]->dia = investidor->dia;
    investidores[index]->mes = investidor->mes;
    investidores[index]->ano = investidor->ano;
    investidores[index]->salario = investidor->salario;
    investidores[index]->patrimonio = investidor->patrimonio;

    num_investidores++;

    return SUCESSO_ACAO;

}

int alterar_investidor(struct investidor *novo_investidor, int codigo){

    int aux = -1;

    for (int i = 0; i < num_investidores; ++i) {
        if (investidores[i] != NULL && investidores[i]->codigo == codigo) {
            aux = i;
            break;
        }
    }

    if (aux == -1) {
        printf("Investidor nao encontrado.\n");
        return NAO_ENCONTRADO;
    }

    strcpy(investidores[aux]->nome, novo_investidor->nome);
    strcpy(investidores[aux]->cpf, novo_investidor->cpf);
    strcpy(investidores[aux]->endereco, novo_investidor->endereco);
    investidores[aux]->dia = novo_investidor->dia;
    investidores[aux]->mes = novo_investidor->mes;
    investidores[aux]->ano = novo_investidor->ano;
    investidores[aux]->salario = novo_investidor->salario;

    printf("Investidor alterado com sucesso!\n");
    return SUCESSO_ACAO;

}

int excluir_investidor(int codigo_investidor) {
    int indice = -1;

    // Procurar o investidor pelo código
    for (int i = 0; i < num_investidores; ++i) {
        if (investidores[i] != NULL && investidores[i]->codigo == codigo_investidor) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        // Liberar a memória do investidor encontrado
        free(investidores[indice]);

        // Remover o investidor da lista
        investidores[indice] = NULL;

        return SUCESSO_ACAO;
    } else
        return NAO_ENCONTRADO;

}

void liberar_investidores() {
    for (int i = 0; i < TAM; ++i) {
        free(investidores[i]);
        investidores[i] = NULL;
    }
}