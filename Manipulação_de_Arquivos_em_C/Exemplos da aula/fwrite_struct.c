#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    int idade;
    float altura;
} Pessoa;

int main() {

    Pessoa pes = {"Maria", 59, 1.67};

    // gravacao
    FILE *arq = fopen("teste4.aul", "wb");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    fwrite(&pes, sizeof(Pessoa), 1, arq);
    fclose(arq);

    arq = fopen("teste4.aul", "rb");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }

    Pessoa pessoaLida;
    fread(&pessoaLida, sizeof(Pessoa), 1, arq);
    printf("Nome: %s\nIdade: %d\nAltura %.2f", pessoaLida.nome, pessoaLida.idade, pessoaLida.altura);

    return 0;
}