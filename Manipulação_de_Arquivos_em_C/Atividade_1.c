#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char texto[229];

    // Leitura do texto
    FILE *arq = fopen("Poem.txt", "r");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    
    fgets(texto, 229, arq);

    fclose(arq);
    

    FILE *arq2 = fopen("Poem2.txt", "w");
    if(arq2 == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }

    fputs(texto, arq2);
    
    fclose(arq2);


    return 0;
}