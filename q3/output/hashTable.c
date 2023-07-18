#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/hashTable.h"

struct hash
{
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

// Aloca espaço para o array de ponteiros e os inicializa com NULL
Hash *criaHash(int TABLE_SIZE)
{
    Hash *ha;
    ha = (Hash *)malloc(sizeof(Hash));

    if (ha != NULL)
    {
        int i;

        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno **)malloc(TABLE_SIZE * sizeof(struct aluno *));

        if (ha->itens == NULL)
        {
            free(ha);
            return NULL;
        }

        ha->qtd = 0;

        for (i = 0; i < ha->TABLE_SIZE; i++)
        {
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

// Percorre todo o array desalocando os elementos
void liberaHash(Hash *ha)
{
    if (ha != NULL)
    {
        int i;
        for (i = 0; i < ha->TABLE_SIZE; i++)
        {
            if (ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

int chaveDobra(int chave, int TABLE_SIZE){
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE-1);
    return (parte1 ^ parte2);
}

int valorString(char *str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return (valor & 0x7FFFFFFF);
}

int duploHash(int H1, int chave, int i, int TABLE_SIZE){
    int H2 = chaveDobra(chave,TABLE_SIZE-1) + 1;
    return ((H1 + i*H2) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_EnderAberto(Hash *ha, struct aluno al)
{
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = valorString(al.nome);

    int i, pos, newPos;

    pos = chaveDobra(chave, ha->TABLE_SIZE);

    for (i = 0; i < ha->TABLE_SIZE; i++)
    {
        newPos = duploHash(pos, chave, i, ha->TABLE_SIZE);
        if (ha->itens[newPos] == NULL)
        {
            struct aluno *novo;
            novo = (struct aluno *)malloc(sizeof(struct aluno));
            if (novo == NULL)
                return 0;
            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }

    return 0;
}

int buscaHash_EnderAberto(Hash *ha, char *nome, struct aluno *al){
    if (ha == NULL)
        return 0;
    int i, pos, newPos;

    int chave = valorString(nome);

    pos = chaveDobra(chave, ha->TABLE_SIZE);

    for (i = 0; i < ha->TABLE_SIZE; i++)
    {
        newPos = duploHash(pos, chave, i, ha->TABLE_SIZE);
        if (ha->itens[newPos] == NULL)
            return 0;
        if (strcmp(ha->itens[newPos]->nome, nome) == 0)
        {
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
    return 0;
}

int cancelarMatricula(Hash *ha, char *nome) {
  int chave = valorString(nome);
  int pos = chaveDobra(chave, ha->TABLE_SIZE);

  for (int i = 0; i < ha->TABLE_SIZE; i++) {
    int newPos = duploHash(pos, chave, i, ha->TABLE_SIZE);

    if (ha->itens[newPos] == NULL)
      return 0;

    if (ha->itens[newPos] != NULL && strcmp(ha->itens[newPos]->nome,nome) == 0) {
      free(ha->itens[newPos]);
      ha->itens[newPos] = NULL;
      ha->qtd--;
      return 1;
    }
  }
  return 0;
}