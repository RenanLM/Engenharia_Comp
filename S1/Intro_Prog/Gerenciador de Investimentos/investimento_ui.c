#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "investidor.h"
#include "investimento.h"
#include "functions.h"

#define ERRO_FALTA_MEMORIA (-1)
#define FALHA_ALOCACAO (-2)
#define NAO_ENCONTRADO (-3)
#define SUCESSO_ACAO 1
#define TAM 50

void inserir_investimento_ui(){

    int codigo_investidor;
    printf("Informe o codigo do investidor associado ao novo investimento: ");
    scanf("%d", &codigo_investidor);
    getchar();

    while (1){
        if(check_investidor(codigo_investidor) >= 0)
            break;
        else {
            printf("Investidor nao encontrado. Tente novamente.\n");
            return;
        }
    }

    struct investimento novo_investimento;

    novo_investimento.codigo_investidor = codigo_investidor;

    int codigo = gerar_codigo_2((struct investimento *) investimentos, num_investimentos);
    printf("Seu codigo de investimento e: %d\n", codigo);
    novo_investimento.codigo = codigo;

    char tipo[2];
    while (1){

        ler("Informe o tipo de investimento (1-CDB, 2-CRI, 3-CRA, 4-LCA, 5-LCI, 6-ACAO): ", tipo);

        if(tipo[0] == '\0')
            printf("E necessario informar o tipo de investimento. Tente novamente.\n");
        else{
            int op = atoi(tipo);

            if (op >= 1 && op <= 6) {
                novo_investimento.tipo = op;
                break;
            } else
                printf("Tipo de investimento inválido. Tente novamente.\n");
        }
    }

    char valor[15];
    while (1){
        ler("Informe o valor do investimento: ", valor);
        if(valor[0] == '\0')
            printf("E necessario inserir um valor para prosseguir. Tente novamente.\n");
        else {
            char *ptr = strchr(valor, ',');
            if (ptr != NULL) {
                *ptr = '.';
            }
            novo_investimento.valor = atof(valor);
            break;
        }
    }

    char descricao[255];
    while (1) {
        ler("Insira uma descricao para o  investimento: ", descricao);

        if (descricao[0] == '\0')
            printf("E necessario inserir uma descricao para prosseguir. Tente novamente.\n");
        else {
            strcpy(novo_investimento.descricao, descricao);
            break;
        }
    }

    char prazo[6];
    while (1){

        ler("Insira o prazo do investimento (em dias): ", prazo);

        if(prazo[0] == '\0')
            printf("E necessario inserir um prazo para prosseguir. Tente novamente.\n");
        else{
            novo_investimento.prazo = atoi(prazo);
            break;
        }
    }

    char rentabilidade[7];
    while (1){

        ler("Insira a rentabilidade anual do investimento (365 dias): ", rentabilidade);

        if(rentabilidade[0] == '\0')
            printf("E necessario inserir uma rentabilidade para prosseguir. Tente novamente.\n");
        else{
            char *ptr = strchr(rentabilidade, ',');
            if (ptr != NULL) {
                *ptr = '.';
            }
            novo_investimento.rentabilidade = atof(rentabilidade);
            break;
        }
    }

    char data[11];
    while (1){
        ler("Insira a data de aplicacao do investimento (DD/MM/AAAA): ", data);
        for (int i = 0; i < 10; ++i) {
            if(data[i] == '\0')
                printf("Data formato incorreto. Tente novamente.\n");
        }
        int dia = (data[0] - '0') * 10 + (data[1] - '0');
        int mes = (data[3] - '0') * 10 + (data[4] - '0');
        int ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');

        if (dia < 1 || dia > 31) {
            printf("Insira um dia válido.\n");
        } else if (mes < 1 || mes > 12) {
            printf("Insira um mês válido.\n");
        } else if (ano < 1900 || ano > 2023) { // Considerando que o ano atual seja 2023
            printf("Insira um ano válido entre 1900 e 2023.\n");
        } else {
            novo_investimento.dia = dia;
            novo_investimento.mes = mes;
            novo_investimento.ano = ano;

            break;
        }
    }

    int resultado = inserir_investimento(&novo_investimento);
    if (resultado == SUCESSO_ACAO)
        printf("Investimento inserido com sucesso!\n");
    else if (resultado == ERRO_FALTA_MEMORIA)
        printf("Nao foi possivel inserir! Sem espaço em memoria.\n");
}

void alterar_investimento_ui(int opcao){

    int codigo;
    printf("Informe o codigo do investimento a ser alterado: ");
    scanf("%d", &codigo);
    getchar();

    while(1){
        if(check_investimento(codigo))
            break;
        else
            printf("Investimento nao encontrado. Tente novamente.\n");
    }

    struct investimento novo_investimento;
    char tipo[2];
    char valor[15];
    char descricao[255];
    char prazo[6];
    char rentabilidade[7];
    char data[11];

    int resultado;

    switch (opcao) {
        case 1: // Alterar todos os dados do investimento

            while (1){

                ler("Informe o tipo de investimento (1-CDB, 2-CRI, 3-CRA, 4-LCA, 5-LCI, 6-ACAO): ", tipo);

                if(tipo[0] == '\0')
                    printf("E necessario informar o tipo de investimento. Tente novamente.\n");
                else{
                    int op = atoi(tipo);

                    if (op >= 1 && op <= 6) {
                        novo_investimento.tipo = op;
                        break;
                    } else
                        printf("Tipo de investimento inválido. Tente novamente.\n");
                }
            }

            while (1){
                ler("Informe o valor do investimento: ", valor);
                if(valor[0] != '\0')
                    printf("E necessario inserir um valor para prosseguir. Tente novamente.\n");
                else {
                    char *ptr = strchr(valor, ',');
                    if (ptr != NULL) {
                        *ptr = '.';
                    }
                    novo_investimento.valor = atof(valor);
                    break;
                }
            }

            while (1) {
                ler("Insira uma descricao para o  investimento: ", descricao);

                if (descricao[0] == '\0')
                    printf("E necessario inserir uma descricao para prosseguir. Tente novamente.\n");
                else {
                    strcpy(novo_investimento.descricao, descricao);
                    break;
                }
            }

            while (1){

                ler("Insira o prazo do investimento (em dias): ", prazo);

                if(prazo[0] == '\0')
                    printf("E necessario inserir um prazo para prosseguir. Tente novamente.\n");
                else{
                    novo_investimento.prazo = atoi(prazo);
                    break;
                }
            }

            while (1){

                ler("Insira a rentabilidade anual do investimento (365 dias): ", rentabilidade);

                if(rentabilidade[0] == '\0')
                    printf("E necessario inserir uma rentabilidade para prosseguir. Tente novamente.\n");
                else{
                    novo_investimento.rentabilidade = atof(rentabilidade);
                    break;
                }
            }

            while (1){
                ler("Insira a data de aplicacao do investimento (DD/MM/AAAA): ", data);
                for (int i = 0; i < 10; ++i) {
                    if(data[i] == '\0')
                        printf("Data formato incorreto. Tente novamente.\n");
                }
                int dia = (data[0] - '0') * 10 + (data[1] - '0');
                int mes = (data[3] - '0') * 10 + (data[4] - '0');
                int ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');

                if (dia < 1 || dia > 31) {
                    printf("Insira um dia válido.\n");
                } else if (mes < 1 || mes > 12) {
                    printf("Insira um mês válido.\n");
                } else if (ano < 1900 || ano > 2023) { // Considerando que o ano atual seja 2023
                    printf("Insira um ano válido entre 1900 e 2023.\n");
                } else {
                    novo_investimento.dia = dia;
                    novo_investimento.mes = mes;
                    novo_investimento.ano = ano;

                    break;
                }
            }

            resultado = alterar_investimento(&novo_investimento, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investimento nao encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investimento alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investimento.\n");
            }

            break;

        case 2: // Alterar somente o tipo
            while (1) {
                ler("Informe o tipo de investimento (1-CDB, 2-CRI, 3-CRA, 4-LCA, 5-LCI, 6-ACAO): ", tipo);

                if(tipo[0] == '\0')
                    printf("E necessario informar o tipo de investimento. Tente novamente.\n");
                else{
                    int op = atoi(tipo);

                    if (op >= 1 && op <= 6) {
                        novo_investimento.tipo = op;
                        break;
                    } else
                        printf("Tipo de investimento invalido. Tente novamente.\n");
                }
            }

            resultado = alterar_investimento(&novo_investimento, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investimento nao encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investimento alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investimento.\n");
            }

            break;

        case 3: // Alterar somente o valor

            while (1){
                ler("Informe o valor do investimento: ", valor);
                if(valor[0] != '\0')
                    printf("E necessario inserir um valor para prosseguir. Tente novamente.\n");
                else {
                    char *ptr = strchr(valor, ',');
                    if (ptr != NULL) {
                        *ptr = '.';
                    }
                    novo_investimento.valor = atof(valor);
                    break;
                }
            }

            resultado = alterar_investimento(&novo_investimento, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investimento nao encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investimento alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investimento.\n");
            }

            break;

        case 4: // Alterar somente a descricao
            while (1) {
                ler("Insira uma descricao para o  investimento: ", descricao);

                if (descricao[0] == '\0')
                    printf("E necessario inserir uma descricao para prosseguir. Tente novamente.\n");
                else {
                    strcpy(novo_investimento.descricao, descricao);
                    break;
                }
            }
            break;

        case 5: // Alterara somente o prazo

            while (1){

                ler("Insira o prazo do investimento (em dias): ", prazo);

                if(prazo[0] == '\0')
                    printf("E necessario inserir um prazo para prosseguir. Tente novamente.\n");
                else{
                    novo_investimento.prazo = atoi(prazo);
                    break;
                }
            }

            resultado = alterar_investimento(&novo_investimento, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investimento nao encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investimento alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investimento.\n");
            }

            break;

        case 6: // Alterar somente a rentabilidade

            while (1){

                ler("Insira a rentabilidade anual do investimento (365 dias): ", rentabilidade);

                if(rentabilidade[0] == '\0')
                    printf("E necessario inserir uma rentabilidade para prosseguir. Tente novamente.\n");
                else{
                    novo_investimento.rentabilidade = atof(rentabilidade);
                    break;
                }
            }

            resultado = alterar_investimento(&novo_investimento, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investimento nao encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investimento alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investimento.\n");
            }

            break;

        case 7:

            while (1){
                ler("Insira a data de aplicacao do investimento (DD/MM/AAAA): ", data);
                for (int i = 0; i < 10; ++i) {
                    if(data[i] == '\0')
                        printf("Data formato incorreto. Tente novamente.\n");
                }
                int dia = (data[0] - '0') * 10 + (data[1] - '0');
                int mes = (data[3] - '0') * 10 + (data[4] - '0');
                int ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');

                if (dia < 1 || dia > 31) {
                    printf("Insira um dia válido.\n");
                } else if (mes < 1 || mes > 12) {
                    printf("Insira um mês válido.\n");
                } else if (ano < 1900 || ano > 2023) { // Considerando que o ano atual seja 2023
                    printf("Insira um ano válido entre 1900 e 2023.\n");
                } else {
                    novo_investimento.dia = dia;
                    novo_investimento.mes = mes;
                    novo_investimento.ano = ano;

                    break;
                }
            }

            resultado = alterar_investimento(&novo_investimento, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investimento nao encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investimento alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investimento.\n");
            }

            break;

        case 0:
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }

}

void mostrar_investimentos_ui(int opcao){

    int resultado;
    int codigo;
    struct investimento* investimentos_ordenados[num_investimentos];

    switch (opcao) {
        case 1: // Mostrar investimento com base no codigo do investimento

            while (1){
                printf("Informe o codigo do investimento a ser impresso: ");
                scanf("%d", &codigo);
                getchar();

                resultado = check_investimento(codigo);
                if(resultado >= 0)
                    caixaInvestimento(*investimentos[resultado]);
                else{
                    printf("Investimento nao encontrado. Tente novamente.\n");
                }
                break;
            }

            break;

        case 2: // Mostrar investimentos com base no codigo do investidor
            while (1) {
                printf("Informe o codigo do investidor a ser impresso: ");
                scanf("%d", &codigo);
                getchar();

                int resultados[TAM]; // Vetor para armazenar os índices dos investimentos relacionados
                int num_resultados = 0; // Contador para o número de investimentos relacionados encontrados

                for (int i = 0; i < num_investimentos; ++i) {
                    if (investimentos[i] != NULL && investimentos[i]->codigo_investidor == codigo) {
                        resultados[num_resultados] = i; // Armazena o índice do investimento relacionado
                        num_resultados++; // Incrementa o contador de resultados
                    }
                }

                if (num_resultados > 0) {
                    for (int i = 0; i < num_resultados; ++i) {
                        caixaInvestimento(*investimentos[resultados[i]]); // Mostra as informações de cada investimento relacionado
                    }
                } else {
                    printf("Investimentos nao encontrados. Tente novamente.\n");
                }
                break;
            }

            break;

        case 3: // Mostrar/imprimir todos os investimentos em ordem alfabética pelo tipo de investimento

            memcpy(investimentos_ordenados, investimentos, num_investimentos * sizeof(struct investimento*));

                // Ordene o vetor investimentos_ordenados pelo tipo de investimento
            qsort(investimentos_ordenados, num_investimentos, sizeof(struct investimento*), comparar_tipo);

                // Mostrar os investimentos ordenados pelo tipo de investimento
            for (int i = 0; i < num_investimentos; ++i) {
                caixaInvestimento(*investimentos_ordenados[i]);
            }

            break;

        case 4: // Mostrar todos os investimentos
            printf("#==================================#\n");
            printf("|            Investimentos         |\n");
            printf("|            Cadastrados           |\n");
            printf("#==================================#\n");

            for (int i = 0; i < num_investimentos; ++i) {
                caixaInvestimento(*investimentos[i]);
                printf("\n");
            }
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;

    }
}

void excluir_investimento_ui(){

    int op;
    int codigo;
    printf("Insira o codigo do investimento a ser excluido: ");
    scanf("%d", &codigo);
    getchar();

    while (1){
        if(check_investimento(codigo))
            break;
        else
            printf("Investimento nao encontrado");

    }

    printf("O seguinte investimento sera excluido:\n");
    caixaInvestimento(*investimentos[codigo]);
    printf("\n");
    printf("Deseja continuar? 1-Sim / 2-Nao");
    scanf("%d", &op);

    switch (op) {

        int resultado;

        case 1:
            resultado = excluir_investimento(codigo);
            if(resultado == SUCESSO_ACAO)
                printf("Investimento excluido com sucesso.\n");

        case 2:
            break;

        default:
            printf("Opcao invalida. Tente novamente");
            break;
    }
}