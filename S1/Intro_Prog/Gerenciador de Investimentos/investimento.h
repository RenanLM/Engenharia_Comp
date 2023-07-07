
struct investimento{
    int codigo;
    int codigo_investidor;
    int tipo;
    float valor;
    char descricao[512];
    int prazo;
    float rentabilidade;
    int dia, mes, ano;
    float valorizacao;
};

extern struct investimento* investimentos[];
extern int num_investimentos;

void carregar_investimentos();
void salvar_investimentos();
int inserir_investimento(struct investimento* investimento);
int alterar_investimento(struct investimento* novo_investimento, int codigo);
int excluir_investimento(int codigo);
void liberar_investimentos();