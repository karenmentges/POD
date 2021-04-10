#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int matricula;
    char nome[41];
    float IAA;
} Aluno;

int main() {

    int op, total;
    Aluno aluno;

    // Adicionando alunos
    FILE *arq = fopen("ListadeAlunos.bin", "wb+");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    for(int i=0; i<100; i++){
        printf("1 - Adicionar aluno\n0 - Sair\n");
        scanf("%d", &op);
        if(op==0){
            break;
        }
        else if(op==1){
            printf("Insira a matricula do aluno: ");
            scanf("%d", &aluno.matricula);
            printf("Insira o nome do aluno: ");
            scanf("%s", aluno.nome);
            printf("Insira o IAA do aluno: ");
            scanf("%f", &aluno.IAA);

            total = fwrite(&aluno, sizeof(Aluno), 1, arq);
            if(total != 1){
                printf("Erro na gravação");
            }
        }
    }

    fseek(arq, 0, SEEK_SET); // volta para o inicio
    while(fread(&aluno, sizeof(Aluno), 1, arq) > 0){
        printf("Matricula: %d\nNome: %s\nIAA: %.2f\n\n", aluno.matricula, aluno.nome, aluno.IAA);
    }

    fclose(arq);
}
