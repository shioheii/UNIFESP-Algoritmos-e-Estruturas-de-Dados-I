/*********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando o algoritmo de ordenação Quicksort
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>

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

int searchMarmore(int ms[], int consult, int t) {
    int i;

    for (i = 0; i < t; i++) {
        if (ms[i] == consult) return i + 1;
    }

    return 0;
}

int main() {
    int n, q, consulta, c = 0;

    while (1) {
        scanf("%d %d", &n, &q);
        getchar();

        if (n == 0 && q == 0) break;

        int marmores[n];
        c++;

        for (int i = 0; i < n; i++) {
            scanf("%d", &marmores[i]);
            getchar();
        }

        quicksort(0, n-1, marmores);

        printf("CASE# %d:\n", c);
        for (int i = 0; i < q; i++) {
            scanf("%d", &consulta);
            getchar();
            
            int search = searchMarmore(marmores, consulta, n);
            if (search == 0) printf("%d not found\n", consulta);
            else             printf("%d found at %d\n", consulta, search);
        }
    }

    return 0;
}
