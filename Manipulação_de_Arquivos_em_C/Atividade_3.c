#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int op, matricula[10], total;
    char nome[41];
    double *IAA;

    // Adicionando alunos
    FILE *arq = fopen("ListadeAlunos.bin", "wb");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    for(int i=0; i<100; i++){
        printf("1 - Adicionar aluno\n0 - Sair\n");
        scanf("%d", op);
        if(op==0){
            break;
        }
        else if(op==1){
            printf("Insira a matricula do aluno: ");
            scanf("%d", &matricula);
            printf("Insira o nome do aluno: ");
            scanf("%s", &nome);
            printf("Insira o nome do aluno: ");
            scanf("%f", &IAA);

            total = fwrite(matricula, sizeof(int), 10, arq);
            if(total != 10)
                printf("Erro na gravação");
            }
            total = fwrite(nome, sizeof(char), 41, arq);
            if(total != 41)
                printf("Erro na gravação");
            }
            total = fwrite(IAA, sizeof(double), 1, arq);
            if(total != 1)
                printf("Erro na gravação");
        }
    
    }

    
}