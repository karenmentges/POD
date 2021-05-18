#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    int idade;
    float altura;
} Pessoa;

int main() {

    Pessoa pes[5] = {{"Maria", 59, 1.67}, {"Pedro", 40, 1.78}, {"Joaozinho", 5, 1.10}, {"Luiz", 30, 1.90}, {"Ana", 15, 1.57}};

    // gravacao
    FILE *arq = fopen("teste5.aul", "wb");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    fwrite(pes, sizeof(Pessoa), 5, arq);
    fclose(arq);

    arq = fopen("teste5.aul", "rb");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }

    Pessoa pessoaLida[5];
    fread(pessoaLida, sizeof(Pessoa), 5, arq); // na aula estava dentro do for, mas nao precisa, pois já lê os 5
    for (int i = 0; i < 5; i++){
        printf("Nome: %s\nIdade: %d\nAltura %.2f\n\n", pessoaLida[i].nome, pessoaLida[i].idade, pessoaLida[i].altura);
    }    
    fclose(arq);
    return 0;
}