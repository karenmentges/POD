#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char nome[40];
    int quantidade, vtp = 0, vtc = 0;
    double preco;

    // Leitura da lista
    FILE *arq = fopen("ListadeCompras.txt", "r");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    while(!feof(arq)){
        fscanf(arq, "%s - %d - %d\n", nome, &quantidade, &preco);
        vtp = quantidade * preco;
        printf("%s %d\n", nome, vtp);
        vtc = vtc + vtp;
    }

    printf("Total: %d\n", vtc);
    
    fclose(arq);  

}
