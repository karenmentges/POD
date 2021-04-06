#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int codigo;
    char nome[41];
} Produto;

int buscaMax(Produto A[], int n){
    int max = A[0].codigo;
    
    for(int i=1; i<n; i++){
        if(A[i].codigo>max){
            max = A[i].codigo;
        }
    }
    
    return max;
}

void countingSort(Produto A[], int n, int pos){
    Produto *aux = malloc(n * sizeof(Produto));
    int *count = calloc(10, sizeof(int));
    int digito;

    for(int i=0; i<n; i++){
        digito = (A[i].codigo/pos) % 10;
        count[digito]++;
    }

    for(int i=1; i<10; i++){
        count[i] = count[i] + count[i-1];
    }

    for(int i = n-1; i>=0; i--){
        digito = (A[i].codigo/pos) % 10;
        count[digito]--;
        aux[count[digito]].codigo = A[i].codigo;
        strcpy(aux[count[digito]].nome, A[i].nome);
    }

    for(int i=0; i<n; i++){
        A[i].codigo = aux[i].codigo;
        strcpy(A[i].nome, aux[i].nome);
    }

}

void radixSort(Produto A[], int n){
    int max = 0;
    
    max = buscaMax(A, n);
    for(int pos = 1; max/pos > 0; pos *= 10){
        countingSort(A, n, pos);
    }
}

int main(){
    Produto A[10];

    for(int x=0; x<10; x++){
        printf("Digite o codigo de 3 digitos do produto: ");
        scanf("%d", &A[x].codigo);
        printf("Digite o nome do produto: ");
        scanf("\n");
        fgets(A[x].nome, sizeof(A[x].nome), stdin);
        A[x].nome[strcspn(A[x].nome, "\n")] = '\0';
    }

    printf("\n\nVetor antes da ordenacao:\n");
    printf("\nCodigo - Nome\n");
    for(int x=0; x<10; x++){
        printf("%d      %s\n", A[x].codigo, A[x].nome);
    }

    radixSort(A, 10);

    printf("\n\nVetor depois da ordenacao:\n");
    printf("\nCodigo - Nome\n");
    for(int x=0; x<10; x++){
        printf("%d      %s\n", A[x].codigo, A[x].nome);
    }
    printf("\n");
}