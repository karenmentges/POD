#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *gerarVetor(int *vet, int n){

    int i;

    srand(time(NULL));
    for(i = 0; i < n; i++) {
        vet[i] = rand() % (n*100);
    } 

    return vet;

}

int *copiarVetor(int *vet1, int *vet2, int n){
    
    int i;
    for(i = 0; i < n; i++) {
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


// Merge Sort
void intercala(int A[], int inicio, int meio, int fim){
    
    int tamanho = fim - inicio + 1;
    int *auxiliar = malloc(tamanho * sizeof(int));
    int i = inicio;
    int j = meio + 1;
    int k = 0;
        
    while(i <= meio && j <= fim){
        if(A[i] <= A[j]){
            auxiliar[k] = A[i];
            i++;
        }
        else{
            auxiliar[k] = A[j];
            j++;
        }
        k++;
    }

    while(i <= meio){
        auxiliar[k] = A[i];
        k++;
        i++;
    }

    while(j <= fim){
        auxiliar[k] = A[j];
        k++;
        j++;
    }

    for(k = inicio; k <= fim; k++){
        A[k] = auxiliar[k - inicio];
    }
    free(auxiliar);

}

void mergeSort(int A[], int inicio, int fim){
    
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort(A, inicio, meio);
        mergeSort(A, meio + 1, fim);
        intercala(A, inicio, meio, fim);
    }

}


// Quick Sort
int particiona(int A[], int inicio, int fim){
    
    int pivo = fim;
    int k = inicio;
    int aux, i;

    for(i = inicio; i < fim; i++){
        if(A[i] <= A[pivo]){
            aux = A[i];
            A[i] = A[k];
            A[k] = aux;
            k++;
        }
    }

    if(A[k] > A[pivo]){
        aux = A[k];
        A[k] = A[pivo];
        A[pivo] = aux;
    }

    return k;

}

void quickSort(int A[], int inicio, int fim){
    int pivo;

    if(inicio < fim){
        pivo = particiona(A, inicio, fim);
        quickSort(A, inicio, pivo-1);
        quickSort(A, pivo+1, fim);
    }

}


// Heap Sort
void criaHeap(int A[], int i, int n){
    
    int maior = i;
    int left = (2*i)+1;
    int right = (2*i)+2;
    int aux = 0;

    if(left < n && A[left] > A[i]){
        maior = left;
    }

    if(right < n && A[right] > A[maior]){
        maior = right;
    }

    if(maior != i){
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        criaHeap(A, maior, n);
    }

}

void heapSort(int A[], int n){

    int aux, k;

    for(k = ((n/2)-1); k >= 0; k--){
        criaHeap(A, k, n);
    }

    for(k = (n-1); k >= 1; k--){
        aux = A[0];
        A[0] = A[k];
        A[k] = aux;
        criaHeap(A, 0, k);
    }

}


void main(){
    int vet1[10000],  vet1c[10000],  vet1d[10000];
    int vet2[50000],  vet2c[50000],  vet2d[50000];
    int vet3[100000], vet3c[100000], vet3d[100000];
    clock_t start=0, end=0;
    double difTempo=0;


    // Calculando tempo para os vetores de dez mil elementos com o Merge Sort

    // Vetores de dez mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet1, 10000);
    copiarVetor(vet1, vet1c, 10000);
    heapSort(vet1c, 10000);
    organizaDecresc(vet1c, vet1d, 10000);
    
    start = clock();
    mergeSort(vet1, 0, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nMerge Sort: Vetor de 10.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    mergeSort(vet1c, 0, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nMerge Sort: Vetor de 10.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    mergeSort(vet1d, 0, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nMerge Sort: Vetor de 10.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);

    // Calculando tempo para os vetores de dez mil elementos com o Quick Sort

    // Vetores de dez mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet1, 10000);
    copiarVetor(vet1, vet1c, 10000);
    mergeSort(vet1c, 0, 10000);
    organizaDecresc(vet1c, vet1d, 10000);

    start = clock();
    quickSort(vet1, 0, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nQuick Sort: Vetor de 10.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    quickSort(vet1c, 0, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nQuick Sort: Vetor de 10.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    quickSort(vet1d, 0, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nQuick Sort: Vetor de 10.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);


    // Calculando tempo para os vetores de dez mil elementos com o Heap Sort

    // Vetores de dez mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet1, 10000);
    copiarVetor(vet1, vet1c, 10000);
    heapSort(vet1c, 10000);
    organizaDecresc(vet1c, vet1d, 10000);

    start = clock();
    heapSort(vet1, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nHeap Sort: Vetor de 10.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    heapSort(vet1c, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nHeap Sort: Vetor de 10.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    heapSort(vet1d, 10000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nHeap Sort: Vetor de 10.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);





    // Calculando tempo para os vetores de cinquenta mil elementos com o Merge Sort

    // Vetores de cinquenta mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet2, 50000);
    copiarVetor(vet2, vet2c, 50000);
    heapSort(vet2c, 50000);
    organizaDecresc(vet2c, vet2d, 50000);

    start = clock();
    mergeSort(vet2, 0, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nMerge Sort: Vetor de 50.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    mergeSort(vet2c, 0, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nMerge Sort: Vetor de 50.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    mergeSort(vet2d, 0, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nMerge Sort: Vetor de 50.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);


    // Calculando tempo para os vetores de cinquenta mil elementos com o Quick Sort

    // Vetores de cinquenta mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet2, 50000);
    copiarVetor(vet2, vet2c, 50000);
    heapSort(vet2c, 50000);
    organizaDecresc(vet2c, vet2d, 50000);

    start = clock();
    quickSort(vet2, 0, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nQuick Sort: Vetor de 50.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    quickSort(vet2c, 0, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nQuick Sort: Vetor de 50.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    quickSort(vet2d, 0, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nQuick Sort: Vetor de 50.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);
    

    // Calculando tempo para os vetores de cinquenta mil elementos com o Heap Sort

    // Vetores de cinquenta mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet2, 50000);
    copiarVetor(vet2, vet2c, 50000);
    heapSort(vet2c, 50000);
    organizaDecresc(vet2c, vet2d, 50000);

    start = clock();
    heapSort(vet2, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nHeap Sort: Vetor de 50.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    heapSort(vet2c, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nHeap Sort: Vetor de 50.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    heapSort(vet2d, 50000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nHeap Sort: Vetor de 50.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);





    // Calculando tempo para os vetores de dez mil elementos com o Merge Sort

    // Vetores de cem mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet3, 100000);
    copiarVetor(vet3, vet3c, 100000);
    heapSort(vet3c, 100000);
    organizaDecresc(vet3c, vet3d, 100000); 

    start = clock();
    mergeSort(vet3, 0, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nMerge Sort: Vetor de 100.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    mergeSort(vet3c, 0, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nMerge Sort: Vetor de 100.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);
    
    start = clock();
    mergeSort(vet3d, 0, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nMerge Sort: Vetor de 100.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);


    // Calculando tempo para os vetores de dez mil elementos com o Quick Sort

    // Vetores de cem mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet3, 100000);
    copiarVetor(vet3, vet3c, 100000);
    heapSort(vet3c, 100000);
    organizaDecresc(vet3c, vet3d, 100000); 

    start = clock();
    quickSort(vet3, 0, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nQuick Sort: Vetor de 100.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    quickSort(vet3c, 0, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nQuick Sort: Vetor de 100.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    quickSort(vet3d, 0, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nQuick Sort: Vetor de 100.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);
    

    // Calculando tempo para os vetores de dez mil elementos com o Heap Sort

    // Vetores de cem mil elementos (em ordem aleatória, crescente e decrescente)
    gerarVetor(vet3, 100000);
    copiarVetor(vet3, vet3c, 100000);
    heapSort(vet3c, 100000);
    organizaDecresc(vet3c, vet3d, 100000); 
    
    start = clock();
    heapSort(vet3, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nHeap Sort: Vetor de 100.000 elementos, em ordem Aleatoria\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    heapSort(vet3c, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nHeap Sort: Vetor de 100.000 elementos, em ordem Crescente\n\tTempo em ms: %lf", difTempo*1000);

    start = clock();
    heapSort(vet3d, 100000);
    end = clock();
    difTempo = ((double) end - start)/CLOCKS_PER_SEC;
    printf("\n\nHeap Sort: Vetor de 100.000 elementos, em ordem Decrescente\n\tTempo em ms: %lf", difTempo*1000);

}