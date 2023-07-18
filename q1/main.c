#include <stdio.h>
#include <stdlib.h>
#include "./include/hashTable.h"

int main()
{
    Hash *ha;
    Aluno al;
    int op, retorno, matBusca, matCancel;

    ha = criaHash(1427);

    do
    {
        printf("\n============== TABELA HASH - Q1 =============\n\n");
        printf("Menu:\n");
        printf("1 -> Cadastrar aluno\n");
        printf("2 -> Buscar aluno\n");
        printf("3 -> Excluir aluno\n");
        printf("0 -> Sair do Menu\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &op);
        printf("\n");

        switch (op)
        {
        case 1:
            printf("Digite a matricula do aluno: ");
            scanf("%d", &al.matricula);

            printf("Digite o nome do aluno: ");
            scanf("%s", &al.nome);

            printf("Digite a primeira nota: ");
            scanf("%f", &al.n1);

            printf("Digite a segunda nota: ");
            scanf("%f", &al.n2);
            
            printf("Digite a terceira nota: ");
            scanf("%f", &al.n3);

            retorno = insereHash_EnderAberto(ha, al);

            if(retorno == 1){
                printf("\nAluno inserido! \n");
            }else{
                printf("\nERROR! Insercao nao realizada!");
            }
            break;
        case 2:
            printf("Digite a matricula do aluno: ");
            scanf("%d", &matBusca);
            
            int retorno = buscaHash_EnderAberto(ha, matBusca, &al);

            if(retorno == 1){
                printf("Aluno encontrado!\n");
                printf("Nome: %s\n", al.nome);
                printf("Nota 1: %.2f\tNota 2: %.2f\tNota 3: %.2f\n", al.n1, al.n2, al.n3);
            }else{
                printf("\nAluno nao encontrado!\n");
            }

            break;
        case 3:
            printf("Digite a matricula a ser cancelada: ");
            scanf("%d", &matCancel);

            retorno = cancelarMatricula(ha, matCancel, &al);

            if(retorno == 1){
                printf("\nAluno removido: %s", al.nome);
            }

            printf("\n");

            break;
        case 0:
            liberaHash(ha);
            break;
        }

    } while (op != 0);

    return 0;
}
