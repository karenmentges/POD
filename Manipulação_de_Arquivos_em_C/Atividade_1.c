#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char c;
    char texto[229];
    int i;

    // Leitura do texto
    FILE *arq = fopen("Poem.txt", "r");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    i = 0;
    while(!feof(arq)) {
        c = fgetc(arq);
        //printf("%c", c);
        if(c=='\n' || c==' '){
            //printf("%c", c);
            texto[i] = c;
            i++;
        }
        else{
            if(c<=90){
                //printf("%c", c);
                texto[i] = c;
                i++;
            }
            else{
                c = c - 32;
                //printf("%c", c);
                texto[i] = c;
                i++;
            }
        }  
    }   
    fclose(arq);   
    
    // Gravação do texto em outro arquivo
    FILE *arq2 = fopen("Poem2.txt", "w");
    if(arq2 == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    char a = 'a';
    putc(a, arq2);
    for(i=0; i<229; i++){
        c = texto[i];
        putc(c, arq2);
        printf("%c", c);
    }
    fclose(arq2);


    return 0;
}