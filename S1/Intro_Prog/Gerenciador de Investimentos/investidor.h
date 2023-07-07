
struct investidor{
    int codigo;
    char nome[255];
    char cpf[12];
    char endereco[255];
    int dia, mes, ano;
    float salario;
    float patrimonio;
};

extern struct investidor *investidores[];
extern int num_investidores;

void carregar_investidores();
void salvar_investidores();
int inserir_investidor(struct investidor* investidor);
int alterar_investidor(struct investidor *novo_investidor, int codigo);
int excluir_investidor(int codigo);
void liberar_investidores();