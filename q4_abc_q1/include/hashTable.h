struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct aluno Aluno;
typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);

void liberaHash(Hash* ha);

int valorString(char *str);

int insereHash_EnderAberto(Hash* ha, struct aluno al, FILE *arq);

int buscaHash_EnderAberto(Hash* ha, int mat, struct aluno *al, FILE *arq);

int sondagemLinear(int pos, int i, int TABLE_SIZE);

int chaveDivisao(int chave, int TABLE_SIZE);

int cancelarMatricula(Hash *ha, int mat, struct aluno *al) ;