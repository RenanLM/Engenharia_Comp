#include <stdio.h>
#include "investidor.h"
#include "investimento.h"
#include "investidor_ui.h"
#include "investimento_ui.h"
#include "functions.h"

void exibir_menu_investidor() {
    printf("===== Menu Investidor =====\n");
    printf("1. Cadastrar novo investidor\n");
    printf("2. Excluir investidor\n");
    printf("3. Mostrar investidores\n");
    printf("4. Alterar investidores\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void menu_alterar_investidor() {
    printf("===== Alterar Investidor =====\n");
    printf("1. Alterar todos os dados do investidor\n");
    printf("2. Alterar somente o nome do investidor\n");
    printf("3. Alterar somente o CPF do investidor\n");
    printf("4. Alterar somente o endereco do investidor\n");
    printf("5. Alterar somente a data de nascimento do investidor\n");
    printf("7. Alterar somente o salario do investidor\n");
    printf("0. Sair deste menu\n");
}

void menu_mostrar_investidor() {
    printf("===== Mostrar Investidor =====\n");
    printf("1. Mostrar os dados do investidor com base no codigo\n");
    printf("2. Mostrar os dados do investidor em ordem crescente de patrimonio\n");
    printf("3. Mostrar todos os investidores cadastrados\n");
    printf("4. Mostrar investidores que tenham um tipo de investimento\n");
    printf("0. Sair deste menu\n");
}

void exibir_menu_investimento() {
    printf("===== Menu Investimento =====\n");
    printf("1. Cadastrar novo investimento\n");
    printf("2. Excluir investimento\n");
    printf("3. Alterar investimentos\n");
    printf("4. Mostrar investimentos\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void menu_alterar_investimento(){
    printf("===== Alterar Investimento =====\n");
    printf("1. Alterar todos os dados do investimento\n");
    printf("2. Alterar somente o tipo do investimento\n");
    printf("3. Alterar somente o valor do investimento\n");
    printf("4. Alterar somente a descricao do investimento\n");
    printf("5. Alterar somente o prazo do investimento\n");
    printf("7. Alterar somente a rentabilidade do investimento\n");
    printf("6. Alterar somente a data de aplicacao do investimento\n");
    printf("0. Sair deste menu\n");

}

void menu_mostrar_investimento() {
    printf("===== Mostrar Investimentos =====\n");
    printf("1. Mostrar os dados do investimento com base no codigo\n");
    printf("2. Mostrar os dados do investimento com base no codigo do investidor\n");
    printf("3. Mostrar todos os investimentos em ordem alfabetica pelo tipo de investimento\n");
    printf("4. Mostrar todos os investimentos cadastrados\n");
    printf("0. Sair deste menu\n");
}

void menu_principal() {
    printf("===== MENU PRINCIPAL =====\n");
    printf("1. Menu Investidor\n");
    printf("2. Menu Investimento\n");
    printf("0. Sair\n");
    printf("Digite sua opcao: ");
}

int main() {
    carregar_investidores();
    carregar_investimentos();
    int opcao_investidor, opcao_investimento;
    int opcao;

    int op_menu_principal;
    do {
        menu_principal();
        scanf("%d", &op_menu_principal);
        getchar();

        switch (op_menu_principal) {
            case 1:
                while (1){
                    exibir_menu_investidor();
                    scanf("%d", &opcao_investidor);
                    getchar();

                    switch (opcao_investidor) {
                        case 1:
                            // Cadastrar novo investidor
                            inserir_investidor_ui();
                            break;
                        case 2:
                            // Excluir investidor
                            excluir_investidor_ui();
                            break;
                        case 3:
                            // Mostrar investidores
                            menu_mostrar_investidor();
                            scanf("%d", &opcao);
                            getchar();
                            switch (opcao) {
                                case 1:
                                    mostrar_investidores_ui(1);
                                    break;
                                case 2:
                                    mostrar_investidores_ui(2);
                                    break;
                                case 3:
                                    mostrar_investidores_ui(3);
                                    break;
                                    //case 4:
                                    //mostrar_investidores_ui(1);
                                default:
                                    printf("Opcao invalida. Tente novamente.\n");
                                    break;

                            }
                            break;
                        case 4:
                            //Alterar investidor
                            menu_alterar_investidor();
                            scanf("%d", &opcao);
                            getchar();
                            switch (opcao) {
                                case 1:
                                    alterar_investidor_ui(1);
                                    break;
                                case 2:
                                    alterar_investidor_ui(2);
                                    break;
                                case 3:
                                    alterar_investidor_ui(3);
                                    break;
                                case 4:
                                    alterar_investidor_ui(4);
                                    break;
                                case 5:
                                    alterar_investidor_ui(5);
                                    break;
                                case 6:
                                    alterar_investidor_ui(6);
                                    break;
                                default:
                                    printf("Opcao invalida. Tente novamente.\n");
                                    break;

                            }
                            break;
                        default:
                            printf("Opcao invalida. Tente novamente.\n");
                            break;
                    }

                    if(opcao_investidor == 0)
                        break;
                    printf("\n");
                }
                break;

            case 2:
                while (2) {
                    exibir_menu_investimento();
                    scanf("%d", &opcao_investimento);
                    getchar();

                    switch (opcao_investimento) {
                        case 1:
                            // Cadastrar novo investimento
                            inserir_investimento_ui();
                            break;
                        case 2:
                            excluir_investimento_ui();
                            // Excluir investimento
                            break;
                        case 3:
                            menu_alterar_investimento();
                            scanf("%d", &opcao);
                            getchar();
                            switch (opcao) {
                                case 1:
                                    alterar_investimento_ui(1);
                                    break;
                                case 2:
                                    alterar_investimento_ui(2);
                                    break;
                                case 3:
                                    alterar_investimento_ui(3);
                                    break;
                                case 4:
                                    alterar_investimento_ui(4);
                                    break;
                                case 5:
                                    alterar_investimento_ui(5);
                                    break;
                                case 6:
                                    alterar_investimento_ui(6);
                                    break;
                                case 7:
                                    alterar_investimento_ui(7);
                                    break;
                                default:
                                    printf("Opcao invalida. Tente novamente.\n");
                                    break;
                            }
                            break;
                        case 4:
                            menu_mostrar_investimento();
                            scanf("%d", &opcao);
                            getchar();
                            switch (opcao) {
                                case 1:
                                    mostrar_investimentos_ui(1);
                                    break;
                                case 2:
                                    mostrar_investimentos_ui(2);
                                    break;
                                case 3:
                                    mostrar_investimentos_ui(3);
                                    break;
                                case 4:
                                    mostrar_investimentos_ui(4);
                                    break;
                                default:
                                    printf("Opcao invalida. Tente novamente.\n");
                                    break;
                            }
                            break;
                        default:
                            printf("Opcao invalida. Tente novamente.\n");
                            break;
                    }
                    if(opcao_investimento == 0)
                        break;
                }
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Digite novamente.\n");
                break;
        }
        printf("\n");
    } while (op_menu_principal != 0);

    salvar_investimentos();
    salvar_investidores();
    liberar_investidores();
    liberar_investimentos();

    return 0;
}
