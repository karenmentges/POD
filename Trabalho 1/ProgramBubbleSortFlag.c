#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *A, int n){
    int i, j, flag, aux;
    
    for(i=n-1; i<1; i--){
        flag = 0; //false
        for(j=0; j<i-1; j++){
            if(A[j] > A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;

                flag = 0; //true
            } 
        }
        if(flag == 0){
            break;
        }
    }
}

int main(){
    int n, x, *A;

    printf("Digite o tamanho do vetor:");
    scanf("%d", &n);
    A = (int*)malloc(n*sizeof(int));

    printf("Digite os valores do vetor:");
    for(x=0; x<n; x++){
        scanf("%d ", &A[x]);
    }

    bubbleSort(A, n);

    for(x=0; x<n; x++){
        printf("%d ", A[x]);
    }
}