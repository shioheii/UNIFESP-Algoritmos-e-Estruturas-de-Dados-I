/**********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando o método de ordenação Quicksort
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>

void printResults(int *pares, int *impares, int par, int imp) {
    for (int i = 0; i < par; i++) 
        printf("%d\n", pares[i]);
    for (int i = imp-1; i >= 0; i--) 
        printf("%d\n", impares[i]);
}

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

int main() {
    int n, value;

    scanf("%d", &n);
    getchar();

    int values[n], imp = 0, par = 0;
    int valuesPares[n], valuesImpares[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        getchar();

        if (value % 2 == 0) valuesPares[par++] = value;
        else                valuesImpares[imp++] = value;
    }

    quicksort(0, par-1, valuesPares);
    quicksort(0, imp-1, valuesImpares);

    printResults(valuesPares, valuesImpares, par, imp);
}
