#include<stdio.h>
#include<stdlib.h>

int buscaMax(int A[], int n){
    int max = A[0];
    
    for(int i=1; i<n; i++){
        if(A[i]>max){
            max = A[i];
        }
    }
    
    return max;
}

void countingSort(int A[], int n, int pos){
    int *aux = malloc(n * sizeof(int));
    int *count = calloc(10, sizeof(int));
    int digito;

    for(int i=0; i<n; i++){
        digito = (A[i]/pos) % 10;
        count[digito]++;
    }

    for(int i=1; i<10; i++){
        count[i] = count[i] + count[i-1];
    }

    for(int i = n-1; i>=0; i--){
        digito = (A[i]/pos) % 10;
        count[digito]--;
        aux[count[digito]] = A[i];
    }

    for(int i=0; i<n; i++){
        A[i] = aux[i];
    }

}

void radixSort(int A[], int n){
    int max = 0;
    
    max = buscaMax(A, n);
    for(int pos = 1; max/pos > 0; pos *= 10){
        countingSort(A, n, pos);
    }
}

int main(){
    int n;
    
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    int A[n];

    printf("Digite os valores do vetor:\n");
    for(int x=0; x<n; x++){
        scanf("%d", &A[x]);
    }

    radixSort(A, n);

    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}