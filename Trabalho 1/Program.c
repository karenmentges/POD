#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *gerarVetor(int *vet, int n){

    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        vet[i] = rand() % (n*100);
    } 

    return vet;

}

int *copiarVetor(int *vet1, int *vet2, int n){
    
    for(int i = 0; i < n; i++) {
        vet2[i] = vet1[i];
    } 
    
    return vet2;
}

int *organizaDecresc(int *vet1, int *vet2, int n){

    int i, j;

    j=n-1;
    i=0;
    while(j>=0){
        vet2[j] = vet1[i];
        i++;
        j--;
    }

    return vet2;
}

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

}

void insertionSort(int *A, int n){
    int i, j, aux, p;
    
    for(i=1; i<=(n-1); i++){
        p = A[i];
        for(j=i; (j>=1) && (p<A[j-1]); j--){
            A[j] = A[j-1];
        }
        A[j] = p;
    }

}

void selectionSort(int *A, int n){
    int i, j, aux, menor;
    
    for(i=0; i<=n-2; i++){
        menor = i;
        for(j=i+1; j<=n-1; j++){
            if(A[menor]>A[j]){
                menor = j;
            }
        }
        aux = A[i];
        A[i] = A[menor];
        A[menor] = aux;
    }

}

int main(){
    int i, j;
    int vet1[10000],  vet1c[10000],  vet1d[10000];
    int vet2[50000],  vet2c[50000],  vet2d[50000];
    int vet3[100000], vet3c[100000], vet3d[100000];
    clock_t start=0, end=0;
    double difTempo=0;


    // Calculando tempo para os vetores de dez mil elementos com o BubbleSort

    // Vetores de dez mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet1, 10000);
    copiarVetor(vet1, vet1c, 10000);
    selectionSort(vet1c, 10000);
    organizaDecresc(vet1c, vet1d, 10000);
    
    start = clock();
    bubbleSort(vet1, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nBubble Sort: Vetor de 10.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    bubbleSort(vet1c, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nBubble Sort: Vetor de 10.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    bubbleSort(vet1d, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nBubble Sort: Vetor de 10.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);


    // Calculando tempo para os vetores de dez mil elementos com o SelectionSort

    // Vetores de dez mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet1, 10000);
    copiarVetor(vet1, vet1c, 10000);
    selectionSort(vet1c, 10000);
    organizaDecresc(vet1c, vet1d, 10000);

    start = clock();
    selectionSort(vet1, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nSelection Sort: Vetor de 10.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    selectionSort(vet1c, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nSelection Sort: Vetor de 10.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    selectionSort(vet1d, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nSelection Sort: Vetor de 10.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);


    // Calculando tempo para os vetores de dez mil elementos com o InsertionSort

    // Vetores de dez mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet1, 10000);
    copiarVetor(vet1, vet1c, 10000);
    selectionSort(vet1c, 10000);
    organizaDecresc(vet1c, vet1d, 10000);

    start = clock();
    insertionSort(vet1, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort: Vetor de 10.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    insertionSort(vet1c, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort: Vetor de 10.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    insertionSort(vet1d, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort: Vetor de 10.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);





    // Calculando tempo para os vetores de cinquenta mil elementos com o BubbleSort

    // Vetores de cinquenta mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet2, 50000);
    copiarVetor(vet2, vet2c, 50000);
    selectionSort(vet2c, 50000);
    organizaDecresc(vet2c, vet2d, 50000);

    start = clock();
    bubbleSort(vet2, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nBubble Sort: Vetor de 50.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    bubbleSort(vet2c, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nBubble Sort: Vetor de 50.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    bubbleSort(vet2d, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nBubble Sort: Vetor de 50.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);


    // Calculando tempo para os vetores de cinquenta mil elementos com o SelectionSort

    // Vetores de cinquenta mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet2, 50000);
    copiarVetor(vet2, vet2c, 50000);
    selectionSort(vet2c, 50000);
    organizaDecresc(vet2c, vet2d, 50000);

    start = clock();
    selectionSort(vet2, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nSelection Sort: Vetor de 50.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    selectionSort(vet2c, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nSelection Sort: Vetor de 50.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    selectionSort(vet2d, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nSelection Sort: Vetor de 50.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);
    

    // Calculando tempo para os vetores de cinquenta mil elementos com o InsertionSort

    // Vetores de cinquenta mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet2, 50000);
    copiarVetor(vet2, vet2c, 50000);
    selectionSort(vet2c, 50000);
    organizaDecresc(vet2c, vet2d, 50000);

    start = clock();
    insertionSort(vet2, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort: Vetor de 50.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    insertionSort(vet2c, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort: Vetor de 50.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    insertionSort(vet2d, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort: Vetor de 50.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);





    // Calculando tempo para os vetores de dez mil elementos com o BubbleSort

    // Vetores de cem mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet3, 100000);
    copiarVetor(vet3, vet3c, 100000);
    selectionSort(vet3c, 100000);
    organizaDecresc(vet3c, vet3d, 100000); 

    start = clock();
    bubbleSort(vet3, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nBubble Sort: Vetor de 100.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    bubbleSort(vet3c, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nBubble Sort: Vetor de 100.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    bubbleSort(vet3d, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nBubble Sort: Vetor de 100.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);


    // Calculando tempo para os vetores de dez mil elementos com o SelectionSort

    // Vetores de cem mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet3, 100000);
    copiarVetor(vet3, vet3c, 100000);
    selectionSort(vet3c, 100000);
    organizaDecresc(vet3c, vet3d, 100000); 

    start = clock();
    selectionSort(vet3, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nSelection Sort: Vetor de 100.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    selectionSort(vet3c, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nSelection Sort: Vetor de 100.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    selectionSort(vet3d, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nSelection Sort: Vetor de 100.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);
    

    // Calculando tempo para os vetores de dez mil elementos com o InsertionSort

    // Vetores de cem mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet3, 100000);
    copiarVetor(vet3, vet3c, 100000);
    selectionSort(vet3c, 100000);
    organizaDecresc(vet3c, vet3d, 100000); 
    
    start = clock();
    insertionSort(vet3, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort: Vetor de 100.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    insertionSort(vet3c, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort: Vetor de 100.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    insertionSort(vet3d, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort: Vetor de 100.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);

}