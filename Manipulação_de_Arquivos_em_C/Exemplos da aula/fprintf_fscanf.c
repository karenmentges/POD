#include <stdio.h>
#include <string.h>

int main() {
    // gravacao
    FILE *arq = fopen("teste3.aul", "w+");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }

    char c;
    for(int i=0; i < 26; i++){
        c = 65 + i;
        fprintf(arq, "Letra %c - Codigo %d\n", c, c);
    }

    // leitura
    int n;
    char c2;
    fseek(arq, 0, SEEK_SET); // volta para o inicio do arquivo
    while(fscanf(arq, "Letra %c - Codigo %d\n", &c2, &n) > 0){
         printf("%c - %d\n", c2, n);
    }
    fclose(arq);
    return 0;
}