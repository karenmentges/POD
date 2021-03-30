#include<stdio.h>

void bubbleSort(int *A, int n){
    int i, j, flag, aux;
    
    for(i=n-1; i>=1; i--){
        flag = 0; //false
        for(j=0; j<=i-1; j++){
            if(A[j] > A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;

                flag = 1; //true
            } 
        }
        if(flag == 0){
            break;
        }
    }

    for(i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
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

    bubbleSort(A, n);
}