#include <stdio.h>
#include <stdlib.h>
#include "./include/hashTable.h"

int main()
{

    Hash *ha;
    int op;

    do
    {
        printf("============== TABELA HASH =============\n\n");
        printf("Menu:\n");
        printf("1 -> Criar tabela hash.\n");
        printf("2 -> Liberar tabela hash.\n");
        printf("3 -> Iserir aluno sem tratamento de colisao.\n");
        printf("4 -> Buscar aluno sem tratamento de colisao.\n");
        printf("5 -> Iserir aluno com tratamento de colisao.\n");
        printf("6 -> Buscar aluno com tratamento de colisao.\n");
        printf("7 -> Excluir aluno\n");
        printf("0 -> Sair do Menu\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);
        printf("\n");

        switch (op)
        {
        case 1:
            ha = criaHash(1427);
            printf("Tabela criada!\n\n");
            break;
        case 2:
            liberaHash(ha);
            printf("Tabela criada!\n\n");
            break;
        case 3:
            
            int x = insereHash_SemColisao(ha, al);
            break;
        case 4:
            int x = buscaHash_SemColisao(ha, mat, &al);
            break;
        case 5:
            int x = insereHash_EnderAberto(ha, al);
            break;
        case 6:
            int x = buscaHash_EnderAberto(ha, mat, &al);
            break;
        case 7:
            liberaHash(ha);
            break;
        }

    } while (op != 0);

    return 0;
}
