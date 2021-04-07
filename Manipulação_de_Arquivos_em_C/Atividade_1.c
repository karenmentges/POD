#include <stdio.h>
#include <string.h>

int main() {

    // Leitura do texto
    FILE *arq = fopen("Poem.aul", "r+");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }

    char c;
    char espaco;
    while(!feof(arq)){
        c = fgetc(arq);
        if(c==' '){
            putc(espaco, arq);
        }
        else if(c > 96){
            c = c - 32;
        }
        putc(c, arq);
    }

    fclose(arq);


    return 0;
}