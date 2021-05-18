#include <stdio.h>
#include <string.h>

int main() {
    // gravacao
    FILE *arq = fopen("teste2.aul", "w");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }

    char c[30] = "Ciencia da Computacao\n";
    char d[30] = "UFFS\n";
    fputs(c, arq);
    fputs(d, arq);

    fclose(arq);

    // leitura
    FILE *arq2 = fopen("teste2.aul", "r");
    if(arq2 == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }

    char c2[30];
    while(fgets(c2, 30, arq2)){
        printf("%s", c2);
    }
    fclose(arq2);
    return 0;
}