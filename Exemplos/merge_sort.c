#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM_MAX = 400000;
int const VARIATION = 50000;

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