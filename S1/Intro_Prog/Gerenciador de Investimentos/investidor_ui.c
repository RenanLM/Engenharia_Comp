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

void inserir_investidor_ui(){

    struct investidor novo_investidor;


    int codigo = gerar_codigo((struct investidor *) investidores, num_investidores);
    printf("Seu codigo de investidor e: %d\n", codigo);
    novo_investidor.codigo = codigo;

    char nome[255];
    while (1) {
        ler("Insira o nome do investidor: ", nome);

        if (nome[0] == '\0') {
            printf("E necessario inserir um nome para prosseguir. Tente novamente.\n");
        } else {
            strcpy(novo_investidor.nome, nome);
            break;
        }
    }

    char cpf[12];
    while (1){
        ler("Insira o CPF do investidor (somente numeros): ", cpf);
        if (cpf[0] == '\0')
            printf("E necessario inserir um CPF para prosseguir. Tente novamente.\n");
        else if (strlen(cpf) < 11 || strlen(cpf) > 12)
            printf("O CPF deve ter entre 11 e 12 numeros. Tente novamente.\n");
        else if(check_cpf(cpf))
            printf("CPF ja cadastrado. Por favor, informe outro CPF.\n");
        else{
            strcpy(novo_investidor.cpf, cpf);
            break;
        }
    }

    char endereco[255];
    ler("Insira o endereco do investidor: ", nome);
    strcpy(novo_investidor.endereco, endereco);

    char data[11];
    while (1){
        ler("Insira a data de nascimento do investidor (DD/MM/AAAA): ", data);
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
            novo_investidor.dia = dia;
            novo_investidor.mes = mes;
            novo_investidor.ano = ano;

            break;
        }
    }

    char salario[15];
    while (1){
        ler("Informe o salario do investidor: ", salario);
        if(salario[0] == '\0')
            printf("E necessario inserir um salario para prosseguir. Tente novamente.\n");
        else {
            char* ptr = strchr(salario, ',');
            if (ptr != NULL) {
                *ptr = '.';
            }
            novo_investidor.salario = atof(salario);
            break;
        }
    }

    int resultado = inserir_investidor(&novo_investidor);
    if (resultado == SUCESSO_ACAO)
        printf("Investidor inserido com sucesso!\n");
    else if (resultado == ERRO_FALTA_MEMORIA)
        printf("Não foi possivel inserir! Sem espaço em memoria.\n");
}

void alterar_investidor_ui(int opcao){

    int codigo;
    printf("Informe o codigo do investidor a ser alterado: ");
    scanf("%d", &codigo);
    getchar();

    while(1){
        if(check_investidor(codigo)>=0)
            break;
        else
            printf("Investidor nao encontrado. Tente novamente.\n");
    }

    struct investidor novo_investidor;
    char nome[255];
    char cpf[12];
    char endereco[255];
    char data[11];
    char salario[15];

    int resultado;

    switch (opcao) {
        case 1: // Alterar todos os dados do investidor

            while (1) {
                ler("Insira o nome do investidor: ", nome);

                if (nome[0] == '\0') {
                    printf("E necessario inserir um nome para prosseguir. Tente novamente.\n");
                } else {
                    strcpy(novo_investidor.nome, nome);
                    break;
                }
            }

            while (1){
                ler("Insira o CPF do investidor (somente numeros): ", cpf);
                if (cpf[0] == '\0')
                    printf("E necessario inserir um CPF para prosseguir. Tente novamente.\n");
                else if (strlen(cpf) < 11 || strlen(cpf) > 12)
                    printf("O CPF deve ter entre 11 e 12 numeros. Tente novamente.\n");
                else if(check_cpf(cpf))
                    printf("CPF ja cadastrado. Por favor, informe outro CPF.\n");
                else{
                    strcpy(novo_investidor.cpf, cpf);
                    break;
                }
            }

            ler("Insira o endereco do investidor: ", nome);
            strcpy(novo_investidor.endereco, endereco);

            while (1){
                ler("Insira a data de nascimento do investidor (DD/MM/AAAA): ", data);
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
                    novo_investidor.dia = dia;
                    novo_investidor.mes = mes;
                    novo_investidor.ano = ano;

                    break;
                }
            }

            while (1){
                ler("Informe o salario do investidor(R$): ", salario);
                if(salario[0] != '\0')
                    printf("E necessario inserir um salario para prosseguir. Tente novamente.\n");
                else {
                    char *ptr = strchr(salario, ',');
                    if (ptr != NULL) {
                        *ptr = '.';
                    }
                    novo_investidor.salario = atof(salario);
                    break;
                }
            }

            resultado = alterar_investidor(&novo_investidor, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investidor não encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investidor alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investidor.\n");
            }

            break;
        case 2: // Alterar somente o nome
            while (1) {
                ler("Insira o nome do investidor: ", nome);

                if (nome[0] == '\0') {
                    printf("E necessario inserir um nome para prosseguir. Tente novamente.\n");
                } else {
                    strcpy(novo_investidor.nome, nome);
                    break;
                }
            }

            resultado = alterar_investidor(&novo_investidor, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investidor não encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investidor alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investidor.\n");
            }

            break;

        case 3: // Alterar somente o CPF

            while (1){
                ler("Insira o CPF do investidor (somente numeros): ", cpf);
                if (cpf[0] == '\0')
                    printf("E necessario inserir um CPF para prosseguir. Tente novamente.\n");
                else if (strlen(cpf) < 11 || strlen(cpf) > 12)
                    printf("O CPF deve ter entre 11 e 12 numeros. Tente novamente.\n");
                else if(check_cpf(cpf))
                    printf("CPF ja cadastrado. Por favor, informe outro CPF.\n");
                else{
                    strcpy(novo_investidor.cpf, cpf);
                    break;
                }
            }

            resultado = alterar_investidor(&novo_investidor, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investidor não encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investidor alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investidor.\n");
            }

            break;

        case 4: // Alterar somente o endereço
            ler("Insira o endereco do investidor: ", nome);
            strcpy(novo_investidor.endereco, endereco);

            resultado = alterar_investidor(&novo_investidor, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investidor não encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investidor alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investidor.\n");
            }

            break;

        case 5: // Alterara somente a data de nascimento

            while (1){
                ler("Insira a data de nascimento do investidor (DD/MM/AAAA): ", data);
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
                    novo_investidor.dia = dia;
                    novo_investidor.mes = mes;
                    novo_investidor.ano = ano;

                    break;
                }
            }

            resultado = alterar_investidor(&novo_investidor, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investidor não encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investidor alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investidor.\n");
            }

            break;
        case 6: // Alterar somente o salario

            while (1){
                ler("Informe o salario do investidor (R$): ", salario);
                if(salario[0] != '\0')
                    printf("E necessario inserir um salario para prosseguir. Tente novamente.\n");
                else {
                    char *ptr = strchr(salario, ',');
                    if (ptr != NULL) {
                        *ptr = '.';
                    }
                    novo_investidor.salario = atof(salario);
                    break;
                }
            }

            resultado = alterar_investidor(&novo_investidor, codigo);

            if (resultado == NAO_ENCONTRADO) {
                printf("Investidor não encontrado.\n");
            } else if (resultado == SUCESSO_ACAO) {
                printf("Investidor alterado com sucesso.\n");
            } else {
                printf("Erro ao alterar o investidor.\n");
            }

            break;
        case 0:
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }

}

void excluir_investidor_ui(){

    int resultado;
    int codigo;
    printf("Informe o codigo do investidor a ser excluido: ");
    scanf("%d", &codigo);
    getchar();

    resultado = check_investidor(codigo);

    while(1){
        if(resultado >= 0)
            break;
        else
            printf("Investidor nao encontrado. Tente novamente.\n");
    }

    if (check_investimento_relacionado(investidores[resultado]->codigo)) {
        int op;
        printf("Existem investimentos relacionados ao investidor.\n");
        printf("Deseja excluir os investimentos junto com o investidor? (1-Sim / 2 - Nao): ");
        scanf("%d", &op);

        if (op == 1) {
            for (int i = 0; i < num_investimentos; ++i) {
                if (investimentos[i] != NULL && investimentos[i]->codigo_investidor == investidores[codigo]->codigo) {
                    excluir_investimento(investimentos[i]->codigo);
                }
            }
        } else {
            printf("Exclusao do investidor cancelada.\n");
            return;
        }
    }

    if(excluir_investidor(codigo) == SUCESSO_ACAO)
        printf("Investidor excluido com sucesso.\n");
    else
        printf("Erro ao excluir o investidor.\n");

}

void mostrar_investidores_ui(int opcao){

    int resultado;
    int codigo;
    struct investidor* investidores_ordenados[num_investidores];

    switch (opcao) {
        case 1: // Mostrar investidor com base no codigo fornecido

            while (1){
                printf("Informe o codigo do investidor a ser impresso: ");
                scanf("%d", &codigo);
                getchar();

                resultado = check_investidor(codigo);
                if(resultado >= 0)
                    caixaInvestidor(*investidores[resultado]);
                else
                    printf("Investidor nao encontrado. Tente novamente.\n");
                break;
            }
            break;

        case 2: // Mostrar investidores em ordem crescente de patrimônio

            // Copiar os ponteiros do vetor original para o vetor auxiliar
            for (int i = 0; i < num_investidores; ++i) {
                investidores_ordenados[i] = investidores[i];
            }

            // Ordenando por ordem de patrimonio

            for (int i = 0; i < num_investidores - 1; ++i) {
                for (int j = 0; j < num_investidores - i - 1; ++j) {
                    if (investidores_ordenados[j]->patrimonio > investidores_ordenados[j + 1]->patrimonio) {
                        // Trocar os ponteiros de posição
                        struct investidor* temp = investidores_ordenados[j];
                        investidores_ordenados[j] = investidores_ordenados[j + 1];
                        investidores_ordenados[j + 1] = temp;
                    }
                }
            }

            // Imprimir os investidores em ordem crescente de patrimônio
            printf("#================================================#\n");
            printf("| Investidores em ordem crescente de patrimonio  |\n");
            printf("#================================================#\n");

            for (int i = 0; i < num_investidores; ++i) {
                caixaInvestidor(*investidores_ordenados[i]);
                printf("\n");
            }

            break;
        case 3: // Mostrar todos os investidores
            printf("#==================================#\n");
            printf("|            Investidores          |\n");
            printf("|            Cadastrados           |\n");
            printf("#==================================#\n");

            for (int i = 0; i < num_investidores; ++i) {
                caixaInvestidor(*investidores[i]);
                printf("\n");
            }

            break;

        case 4: // Mostrar investidores com base no tipo de investimento
            while (1) {
                printf("1 - CDB; 2 - CRI; 3 - CRA; 4 - LCA; 5 - LCI; 6 - ACAO.\n");
                printf("Informe o tipo de investimento (numero): ");
                scanf("%d", &codigo);
                getchar();

                if (codigo < 1 || codigo > 6) {
                    printf("Tipo de investimento invalido. Tente novamente.\n");
                } else {
                    printf("Investidores com o tipo de investimento '%s':\n", obterNomeTipoInvestimento(codigo));
                    int investidoresEncontrados = 0; // Variável para controlar se foram encontrados investidores

                    for (int i = 0; i < num_investidores; i++) {
                        int investidorEncontrado = 0; // Variável para controlar se o investidor possui o tipo de investimento

                        for (int j = 0; j < num_investimentos; j++) {
                            if (investimentos[j] != NULL && investimentos[j]->codigo_investidor == investidores[i]->codigo &&
                                investimentos[j]->tipo == codigo) {
                                investidorEncontrado = 1;
                                break;
                            }
                        }

                        if (investidorEncontrado) {
                            caixaInvestidor(*investidores[i]);
                            printf("\n");
                            investidoresEncontrados = 1;
                        }
                    }

                    if (investidoresEncontrados == 0) {
                        printf("Nenhum investidor encontrado com o tipo de investimento '%s'.\n", obterNomeTipoInvestimento(codigo));
                    }

                }
                break;
            }
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }

}