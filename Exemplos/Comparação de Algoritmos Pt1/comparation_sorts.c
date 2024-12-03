#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM_MAX = 400000;
int const VARIATION = 20000;

// VISME.CO & INFOGRAM para gráficos

// START INSERTION SORT
void insertionSort(int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x;
    }
}
// END INSERTION SORT

// START MERGE SORT
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
// END MERGE SORT

// START QUICK SORT 
int separa(int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    }
    v[r] = v[j], v[j] = c;
    return j;
}

void quicksort(int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = separa(p, r, v);
        quicksort(p, j - 1, v);
        quicksort(j + 1, r, v);
    }
}
// END QUICK SORT 

int main(){
    clock_t insertionSortExecutionTime;
    clock_t mergeSortExecutionTime;
    clock_t quickSortExecutionTime;
    
    srand((unsigned)time(NULL));

    for (int TAM = VARIATION; TAM <= TAM_MAX; TAM += VARIATION) {
        int insertionSortArray[TAM];
        int mergeSortArray[TAM];
        int quickSortArray[TAM];

        for(int a = 0; a < TAM; a++) {
            int ramdomInteger = rand() % TAM;
            insertionSortArray[a] = ramdomInteger;
            mergeSortArray[a] = ramdomInteger;
            quickSortArray[a] = ramdomInteger;
        }

        insertionSortExecutionTime = clock();
        insertionSort(TAM, insertionSortArray);
        insertionSortExecutionTime = clock() - insertionSortExecutionTime;

        mergeSortExecutionTime = clock();
        mergesort(0, TAM, mergeSortArray);
        mergeSortExecutionTime = clock() - mergeSortExecutionTime;

        quickSortExecutionTime = clock();
        quicksort(0, TAM, quickSortArray);
        quickSortExecutionTime = clock() - quickSortExecutionTime;

        printf("Tamanho: %d\n", TAM);
        printf("[insertionSortExecutionTime] => %lf ms\n", ((double)insertionSortExecutionTime)/((CLOCKS_PER_SEC/1000)));
        printf("[mergeSortExecutionTime]     => %lf ms\n", ((double)mergeSortExecutionTime)/((CLOCKS_PER_SEC/1000)));
        printf("[quickSortExecutionTime]     => %lf ms\n", ((double)quickSortExecutionTime)/((CLOCKS_PER_SEC/1000)));
        printf("\n********************\n\n");
    }

    return 0;
}