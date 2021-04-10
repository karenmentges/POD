#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int matricula;
    char nome[41];
    double IAA;
} Aluno;

int main() {

    int op, total;
    Aluno aluno, alunoLido;

    // Adicionando alunos
    FILE *arq = fopen("ListadeAlunos.bin", "wb");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    for(int i=0; i<100; i++){
        printf("1 - Adicionar aluno\n0 - Sair\n");
        scanf("%d", &op);
        if(op==0){
            fseek(arq, 0, SEEK_SET); // volta para o inicio
            while(fread(&alunoLido, sizeof(Aluno), 1, arq)){
                printf("Matricula: %d\nNome: %s\nIAA: %f", alunoLido.matricula, alunoLido.nome, alunoLido.IAA);
            }
            break;
        }
        else if(op==1){
            printf("Insira a matricula do aluno: ");
            scanf("%d", &aluno.matricula);
            printf("Insira o nome do aluno: ");
            scanf("%s", aluno.nome);
            printf("Insira o IAA do aluno: ");
            scanf("%lf", &aluno.IAA);

            total = fwrite(&aluno, sizeof(Aluno), 1, arq);
            if(total != 1){
                printf("Erro na gravação");
            }
        }
    }
    fclose(arq);
}