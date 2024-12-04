#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM_MAX = 400000;
int const VARIATION = 20000;

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

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(){
    clock_t manualQuickSort;
    clock_t nativeQuickSort;
    
    srand((unsigned)time(NULL));

    for (int TAM = VARIATION; TAM <= TAM_MAX; TAM += VARIATION) {
        int manualQuickSortArray[TAM];
        int nativeQuickSortArray[TAM];

        for(int a = 0; a < TAM; a++) {
            int ramdom = rand() % TAM;
            manualQuickSortArray[a] = ramdom;
            nativeQuickSortArray[a] = ramdom;
        }

        manualQuickSort = clock();
        quicksort(0, TAM, manualQuickSortArray);
        manualQuickSort = clock() - manualQuickSort;

        nativeQuickSort = clock();
        qsort(nativeQuickSortArray, TAM, sizeof(int), compare);
        nativeQuickSort = clock() - nativeQuickSort;

        printf("Tamanho: %d\n", TAM);
        printf("[manualQuickSort] Tempo de execucao: %lf ms\n", ((double)manualQuickSort)/((CLOCKS_PER_SEC/1000)));
        printf("[nativeQuickSort] Tempo de execucao: %lf ms\n", ((double)nativeQuickSort)/((CLOCKS_PER_SEC/1000)));
        printf("\n********************\n\n");
    }

    return 0;
}
