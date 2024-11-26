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

int main(){
    clock_t t;
    
    srand((unsigned)time(NULL));

    for (int TAM = VARIATION; TAM <= TAM_MAX; TAM += VARIATION) {
        int vetor[TAM];

        for(int a = 0; a < TAM; a++)
            vetor[a] = rand() % TAM;

        t = clock();
        insertionSort(TAM, vetor);
        t = clock() - t;

        printf("Tamanho: %d - Tempo de execucao: %lf ms\n", TAM, ((double)t)/((CLOCKS_PER_SEC/1000)));
    }

    return 0;
}