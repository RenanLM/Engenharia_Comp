#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "investimento.h"
#include "investidor.h"
#include "functions.h"

#define ERRO_FALTA_MEMORIA (-1)
#define FALHA_ALOCACAO (-2)
#define NAO_ENCONTRADO (-3)
#define SUCESSO_ACAO 1
#define TAM 50

struct investimento* investimentos[TAM];
int num_investimentos = 0;

void carregar_investimentos(){

    FILE* arquivo = fopen("investimentos.bin","rb+");

    if(arquivo == NULL){
        printf("Erro ao tentar abrir o arquivo investimentos.bin\n");
        return;
    }

    struct investimento temp;

    while (fread(&temp, sizeof (struct investimento), 1, arquivo) == 1){
        struct investimento* novo_investimento = malloc(sizeof (struct investimento));
        memcpy(novo_investimento, &temp, sizeof(struct investimento));
        investimentos[num_investimentos++] = novo_investimento;
    }

    fclose(arquivo);
}

void salvar_investimentos() {
    FILE* arquivo = fopen("investimentos.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo investimentos.bin\n");
        return;
    }

    for (int i = 0; i < num_investimentos; i++) {
        fwrite(investimentos[i], sizeof(struct investimento), 1, arquivo);
    }

    fclose(arquivo);
}

int inserir_investimento(struct investimento* investimento){

    int index = -1;

    for (int i = 0; i < TAM; ++i) {
        if(investimentos[i] == NULL){
            index = i;
            break;
        }
    }

    if(index == -1)
        return ERRO_FALTA_MEMORIA;

    investimentos[index] = malloc(sizeof(struct investimento));

    if(investidores[index] == NULL)
        return FALHA_ALOCACAO;

    investimentos[index]->codigo = investimento->codigo;
    investimentos[index]->codigo_investidor = investimento->codigo_investidor;
    investimentos[index]->tipo = investimento->tipo;
    investimentos[index]->valor = investimento->valor;
    strcpy(investimentos[index]->descricao, investimento->descricao);
    investimentos[index]->prazo = investimento->prazo;
    investimentos[index]->rentabilidade = investimento->rentabilidade;
    investimentos[index]->dia = investimento->dia;
    investimentos[index]->mes = investimento->mes;
    investimentos[index]->ano = investimento->ano;
    investimentos[index]->valorizacao = investimento->valorizacao;

    num_investimentos++;

    return SUCESSO_ACAO;


}

int alterar_investimento(struct investimento *novo_investimento, int codigo){

    int aux = -1;

    for (int i = 0; i < num_investimentos; ++i) {
        if (investimentos[i] != NULL && investimentos[i]->codigo == codigo) {
            aux = i;
            break;
        }
    }

    if (aux == -1) {
        printf("Investimento nao encontrado.\n");
        return NAO_ENCONTRADO;
    }

    investimentos[aux]->codigo_investidor = novo_investimento->codigo_investidor;
    investimentos[aux]->tipo = novo_investimento->tipo;
    investimentos[aux]->valor = novo_investimento->valor;
    strcpy(investimentos[aux]->descricao, novo_investimento->descricao);
    investimentos[aux]->prazo = novo_investimento->prazo;
    investimentos[aux]->rentabilidade = novo_investimento->rentabilidade;
    investimentos[aux]->dia = novo_investimento->dia;
    investimentos[aux]->mes = novo_investimento->mes;
    investimentos[aux]->ano = novo_investimento->ano;

    printf("Investidor alterado com sucesso!\n");
    return SUCESSO_ACAO;

}

int excluir_investimento(int codigo){

    int indice = -1;

    // Procurar o investimento pelo código
    for (int i = 0; i < num_investimentos; ++i) {
        if (investimentos[i] != NULL && investimentos[i]->codigo == codigo) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        // Liberar a memória do investimento encontrado
        free(investimentos[indice]);

        // Remover o investimento da lista
        investimentos[indice] = NULL;

        return SUCESSO_ACAO;
    } else
        return NAO_ENCONTRADO;

}

void liberar_investimentos() {
    for (int i = 0; i < TAM; ++i) {
        free(investimentos[i]);
        investimentos[i] = NULL;
    }
}