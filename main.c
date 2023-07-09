#include <stdio.h>
#include <stdlib.h>
#include "./include/hashTable.h"

int main(){
    
    Hash *ha;
    int op;

    do{
        printf("============== TABELA HASH =============\n\n");
        printf("Menu:\n");
        printf("1 -> Criar tabela hash\n");
        printf("2 -> Liberar lista");
        printf("2 -> Inserir registro\n");
        printf("3 -> Excluir registro\n");
        printf("4 -> Pesquisar aluno\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);
        printf("\n");

        switch (op){
            case 1:
                ha = criaHash(1427);
                printf("Tabela criada!\n\n");
                break;
            case 2:
                liberaHash(ha);
                break;
            default:
                break;
        }

    } while (op != 0);
    
    return 0;
}
