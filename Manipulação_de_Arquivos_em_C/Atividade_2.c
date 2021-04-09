#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char nome[40];
    int quantidade;
    double preco, vtp = 0, vtc = 0;

    // Leitura da lista
    FILE *arq = fopen("ListadeCompras.txt", "r");
    if(arq == NULL){
        printf("Não foi possível acessar o arquivo!");
        exit(1);
    }
    while(!feof(arq)){
        fscanf(arq, "%s - %d - %lf\n", nome, &quantidade, &preco);
        vtp = quantidade * preco;
        printf("%s %lf\n", nome, vtp);
        vtc = vtc + vtp;
    }

    printf("\nTotal: %lf\n", vtc);
    
    fclose(arq);  

}
