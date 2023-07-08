#include <stdlib.h>
#include <string.h>
#include "../include/hashTable.h"

struct hash {
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

Hash* criaHash(int TABLE_SIZE){
    Hash *ha;
    ha = (Hash*) malloc(sizeof(Hash));
    
    if (ha != NULL) {
        int i;

        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**)malloc(TABLE_SIZE * sizeof(struct aluno*));

        if (ha->itens == NULL) {
            free(ha);
            return NULL;
        }

        ha->qtd = 0;

        for (i=0; i < ha->TABLE_SIZE; i++){
            ha->itens[i] = NULL;
        }
    }
    return ha;
}