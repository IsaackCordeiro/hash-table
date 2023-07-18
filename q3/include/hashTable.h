struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct aluno Aluno;
typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);

void liberaHash(Hash* ha);

int insereHash_EnderAberto(Hash* ha, struct aluno al);

int buscaHash_EnderAberto(Hash* ha, char *nome, struct aluno *al);

int chaveDobra(int chave, int TABLE_SIZE);

int duploHash(int H1, int chave, int i, int TABLE_SIZE);

int valorString(char *str);

int cancelarMatricula(Hash *ha, char *nome);