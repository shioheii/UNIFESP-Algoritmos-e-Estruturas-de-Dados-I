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

int main(){
    clock_t t;
    
    srand((unsigned)time(NULL));

    for (int TAM = VARIATION; TAM <= TAM_MAX; TAM += VARIATION) {
        int vetor[TAM];

        for(int a = 0; a < TAM; a++)
            vetor[a] = rand() % TAM;

        t = clock();
        mergesort(0, TAM, vetor);
        t = clock() - t;

        printf("Tamanho: %d - Tempo de execucao: %lf ms\n", TAM, ((double)t)/((CLOCKS_PER_SEC/1000)));
    }

    return 0;
}
