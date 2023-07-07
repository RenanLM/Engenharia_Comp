#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "investidor.h"
#include "investimento.h"

#define ERRO_FALTA_MEMORIA (-1)
#define FALHA_ALOCACAO (-2)
#define NAO_ENCONTRADO (-3)
#define SUCESSO_ACAO 1
#define TAM 50

void ler(char msg[], char str[]){
    printf("%s\n", msg);
    fgets(str, 512, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int check_codigo(struct investidor* pinvestidores, int num, int novo_codigo) {
    for (int i = 0; i < num; ++i) {
        if (novo_codigo == pinvestidores[i].codigo) {
            return 1; // Código já existe
        }
    }
    return 0; // Código não existe
}

int gerar_codigo(struct investidor* pinvestidores, int num) {
    srand((unsigned)time(NULL));

    while (1) {
        int novo_codigo = rand() % 1000;

        if (!check_codigo(pinvestidores, num, novo_codigo)) {
            return novo_codigo; // Código único gerado
        }
    }
}

int check_codigo_2(struct investimento* pinvestimentos, int num, int novo_codigo) {
    for (int i = 0; i < num; ++i) {
        if (novo_codigo == pinvestimentos[i].codigo) {
            return 1; // Código já existe
        }
    }
    return 0; // Código não existe
}

int gerar_codigo_2(struct investimento* pinvestimentos, int num) {
    srand((unsigned)time(NULL));

    while (1) {
        int novo_codigo = rand() % 1000;

        if (!check_codigo_2(pinvestimentos, num, novo_codigo)) {
            return novo_codigo; // Código único gerado
        }
    }
}

int check_cpf(const char* cpf) {
    for (int i = 0; i < num_investidores; ++i) {
        if (investidores[i] != NULL && strcmp(investidores[i]->cpf, cpf) == 0) {
            return 1;
        }
    }
    return 0;
}

float calcular_valorizacao_total(int codigo_investidor) {
    float valorizacao_total = 0;

    for (int i = 0; i < num_investimentos; ++i) {
        if (investimentos[i] != NULL && investimentos[i]->codigo_investidor == codigo_investidor) {
            valorizacao_total += investimentos[i]->valorizacao;
        }
    }

    return valorizacao_total;
}


int calcular_dias_passados(struct investimento* investimento) {
    time_t data_atual;
    time(&data_atual);
    struct tm* data_aplicacao = malloc(sizeof(struct tm));

    data_aplicacao->tm_year = investimento->ano - 1900;
    data_aplicacao->tm_mon = investimento->mes - 1;
    data_aplicacao->tm_mday = investimento->dia;

    mktime(data_aplicacao);

    // Convertendo a data de aplicação para dias
    int dias_aplicacao = (data_aplicacao->tm_year * 365) + (data_aplicacao->tm_mon * 30) + data_aplicacao->tm_mday;

    // Convertendo a data atual para dias
    struct tm* data_atual_tm = localtime(&data_atual);
    int dias_atual = (data_atual_tm->tm_year * 365) + (data_atual_tm->tm_mon * 30) + data_atual_tm->tm_mday;

    // Verifica se o prazo já foi atingido
    int dias_prazo = dias_aplicacao + investimento->prazo;

    // Calcula o número de dias passados considerando o prazo ou a data atual
    int dias_passados = (dias_prazo < dias_atual) ? dias_prazo : dias_atual;

    free(data_aplicacao);

    return dias_passados - dias_aplicacao;
}

void caixaInvestidor(struct investidor dados){
    float taxa;
    dados.patrimonio = 0; // Inicializa o patrimônio como zero

    for (int i = 0; i < num_investimentos; ++i) {
        if (investimentos[i] != NULL && investimentos[i]->codigo_investidor == dados.codigo) {
            taxa = powf((1 + (investimentos[i]->rentabilidade / 100)), (float)1 / 365) - 1;
            float valorizacao = taxa * investimentos[i]->valor * (float)calcular_dias_passados(investimentos[i]);
            dados.patrimonio += valorizacao + investimentos[i]->valor;
        }
    }


    //dados.patrimonio = calcular_valorizacao_total(dados.codigo);
    printf("#============================================#\n");
    printf("|         Dados do Investidor\n");
    printf("#============================================#\n");
    printf("| Codigo: %d\n", dados.codigo);
    printf("| Nome: %s\n", dados.nome);
    printf("| CPF: %s\n", dados.cpf);
    printf("| Endereco: %s\n", dados.endereco);
    printf("| Data nascimento: %d/%d/%d\n", dados.dia, dados.mes, dados.ano);
    printf("| Salario: %.2f\n", dados.salario);
    printf("| Patrimonio: %.2f\n", dados.patrimonio);
    printf("#============================================#\n");

}
const char* obterNomeTipoInvestimento(int tipo) {
    switch (tipo) {
        case 1:
            return "CDB";
        case 2:
            return "CRI";
        case 3:
            return "CRA";
        case 4:
            return "LCA";
        case 5:
            return "LCI";
        case 6:
            return "ACAO";
        default:
            return "Desconhecido";
    }
}

void caixaInvestimento(struct investimento dados){
    float taxa = powf((1 + (dados.rentabilidade/100)),(float)1/365) - 1;

    printf("#============================================#\n");
    printf("|        Dados do Investimento\n");
    printf("#============================================#\n");
    printf("| Codigo: %d\n", dados.codigo);
    printf("| Codigo do Investidor: %d\n", dados.codigo_investidor);
    printf("| Tipo: %s\n", obterNomeTipoInvestimento(dados.tipo));
    printf("| Valor: %.2f\n", dados.valor);
    printf("| Descricao: %s\n", dados.descricao);
    printf("| Prazo (em dias corridos): %d\n", dados.prazo);
    printf("| Rentabilidade: %.2f\n", dados.rentabilidade);
    printf("| Data aplicacao: %d/%d/%d\n", dados.dia, dados.mes, dados.ano);
    dados.valorizacao = taxa * dados.valor * (float)calcular_dias_passados(&dados);
    printf("| Valorizacao: %.2f\n", dados.valorizacao + dados.valor);
    printf("#============================================#\n");

}

int check_investidor(int codigo){

    int aux = -1;

    for (int i = 0; i < num_investidores; ++i) {
        if (investidores[i] != NULL && investidores[i]->codigo == codigo) {
            aux = i;
            break;
        }
    }

    if (aux == -1)
        return NAO_ENCONTRADO;
    else
        return aux;
}

int check_investimento(int codigo){

    int aux = -1;

    for (int i = 0; i < num_investimentos; ++i) {
        if (investimentos[i] != NULL && investimentos[i]->codigo == codigo) {
            aux = i;
            break;
        }
    }

    if (aux == -1)
        return NAO_ENCONTRADO;
    else
        return aux;
}

int comparar_tipo(const void* a, const void* b) {
    struct investimento* investimentoA = *(struct investimento**)a;
    struct investimento* investimentoB = *(struct investimento**)b;

    // Comparar os tipos de investimento
    if (investimentoA->tipo < investimentoB->tipo)
        return -1;
    else if (investimentoA->tipo > investimentoB->tipo)
        return 1;
    else
        return 0;
}

int check_investimento_relacionado(int codigo_investidor) {
    for (int i = 0; i < num_investimentos; ++i) {
        if (investimentos[i] != NULL && investimentos[i]->codigo_investidor == codigo_investidor) {
            return 1; // Existem investimentos relacionados
        }
    }
    return 0; // Nao há investimentos relacionados
}







