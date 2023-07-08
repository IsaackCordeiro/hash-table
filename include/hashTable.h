struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);