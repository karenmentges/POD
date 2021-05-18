#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    int idade;
    float altura;
} Pessoa;

int main() {

  // {"Maria"c, 59, 1.67}, {"Pedro", 40, 1.78}, {"Joaozinho", 5, 1.10}, {"Luiz", 30, 1.90}, {"Ana", 15, 1.57}};

    // leitura
    FILE *arq = fopen("teste5.aul", "r+b");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    Pessoa pes;

    // ultimo
    fseek(arq, -(sizeof(Pessoa)), SEEK_END);
    fread(&pes, sizeof(Pessoa), 1, arq);
    printf("Ultimo: %s\n", pes.nome);

    // primeiro
    fseek(arq, 0, SEEK_SET);
    fread(&pes, sizeof(Pessoa), 1, arq);
    printf("Primeiro: %s\n", pes.nome);

    // pulou 2
    fseek(arq, 2*sizeof(Pessoa), SEEK_CUR);
    fread(&pes, sizeof(Pessoa), 1, arq);
    printf("Pulou 2: %s\n", pes.nome);

    // alterar o nome do segundo registro
    fseek(arq, sizeof(Pessoa), SEEK_SET);
    fread(&pes, sizeof(Pessoa), 1, arq);
    strcpy(pes.nome, "Pedro Henrique");
    //printf("Mudou: %s", pes.nome);
    fseek(arq, sizeof(Pessoa), SEEK_SET); // volta para inicio do segundo
    fwrite(&pes, sizeof(Pessoa), 1, arq);

    // exibe
    // imprime todos os nomes
    printf("\nNova lista:\n");
    fseek(arq, 0, SEEK_SET); // volta para o inicio
    while(fread(&pes, sizeof(Pessoa), 1, arq)){
         printf("\nNome: %s", pes.nome);
    }

    fclose(arq);
    return 0;
}