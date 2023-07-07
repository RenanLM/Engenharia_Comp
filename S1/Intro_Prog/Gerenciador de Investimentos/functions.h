
void ler(char msg[], char str[]);
int check_codigo(struct investidor* pinvestidores, int num, int novo_codigo);
int gerar_codigo(struct investidor* pinvestidores, int num);
int check_codigo_2(struct investimento* pinvestimentos, int num, int novo_codigo);
int gerar_codigo_2(struct investimento* pinvestimentos, int num);
int check_cpf(const char* cpf);
int check_investidor(int codigo);
int check_investimento(int codigo);
int check_investimento_relacionado(int codigo_investidor);
int comparar_tipo(const void* a, const void* b);
void caixaInvestidor(struct investidor dados);
void caixaInvestimento(struct investimento dados);
int calcular_dias_passados(struct investimento* investimento);
float calcular_valorizacao_total(int codigo_investidor);
const char* obterNomeTipoInvestimento(int tipo);