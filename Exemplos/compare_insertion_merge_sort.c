#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM_MAX = 400000;
int const VARIATION = 50000;

void insertionSort(int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x;
    }
}

void intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; i++) v[i] = w[i-p];
    free (w);
}

void mergesort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        mergesort (p, q, v);
        mergesort (q, r, v);
        intercala (p, q, r, v);
    }
}

int main(){
    clock_t insertionSortExecutionTime;
    clock_t mergeSortExecutionTime;
    
    srand((unsigned)time(NULL));

    for (int TAM = VARIATION; TAM <= TAM_MAX; TAM += VARIATION) {
        int vetorInsertionSort[TAM];
        int vetorMergeSort[TAM];

        for(int a = 0; a < TAM; a++) {
            int ramdomInteger = rand() % TAM;
            vetorInsertionSort[a] = ramdomInteger;
            vetorMergeSort[a] = ramdomInteger;
        }

        insertionSortExecutionTime = clock();
        insertionSort(TAM, vetorInsertionSort);
        insertionSortExecutionTime = clock() - insertionSortExecutionTime;

        mergeSortExecutionTime = clock();
        mergesort(0, TAM, vetorMergeSort);
        mergeSortExecutionTime = clock() - mergeSortExecutionTime;

        printf("Tamanho: %d\n", TAM);
        printf("[insertionSortExecutionTime] => %lf ms\n", ((double)insertionSortExecutionTime)/((CLOCKS_PER_SEC/1000)));
        printf("[mergeSortExecutionTime]     => %lf ms\n", ((double)mergeSortExecutionTime)/((CLOCKS_PER_SEC/1000)));
        printf("\n********************\n\n");
    }

    return 0;
}