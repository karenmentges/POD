#include <stdio.h>
#include <string.h>

int main() {
    // gravacao
    FILE *arq = fopen("teste.aul", "w");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }

    char c;
    for(int i=0; i < 26; i++){
        c = 65 + i;
        putc(c, arq);
        putc('\n', arq);
    }
    fclose(arq);

    // leitura
    FILE *arq2 = fopen("teste.aul", "r");
    if(arq2 == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }

    char c2;
    while(!feof(arq2)){
        c2 = fgetc(arq2);
        if(c2 != '\n')
            printf("%c ", c2);
    }
    fclose(arq2);
    return 0;
}