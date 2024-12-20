/*********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando o método de ordenação Quicksort
*********************************************************************/

#include<stdio.h>
#include<stdlib.h>

int compara(int a, int b, int module) {
    int modA = a % module;
    int modB = b % module;

    // Primeiro critério: ordenar pelo módulo M
    if (modA != modB) return modA - modB;

    // Se o módulo for igual, impares vem primeiro
    int isOddA = a % 2 != 0;
    int isOddB = b % 2 != 0;

    if (isOddA && !isOddB) return -1; // A impar, B par
    if (!isOddA && isOddB) return 1;  // A par, B impar

    if (isOddA && isOddB) return b - a; // Entre dois ímpares, o maior vem primeiro

    return a - b; // Entre dois pares, o menor vem primeiro
}

int separa(int p, int r, int v[], int module) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++) {
        if (compara(v[k], c, module) <= 0) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    }
    v[r] = v[j], v[j] = c;
    return j;
}

void quicksort(int p, int r, int v[], int module) {
    int j;
    if (p < r) {
        j = separa(p, r, v, module);
        quicksort(p, j - 1, v, module);
        quicksort(j + 1, r, v, module);
    }
}

void sort(int n, int v[], int module) {
    quicksort(0, n - 1, v, module);
}

int main() {
    int n, m;

    while (1) {
        scanf("%d %d", &n, &m);
        getchar();

        if (n == 0 && m == 0) break;

        int numbers[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
            getchar();
        }

        sort(n, numbers, m);

        printf("%d %d\n", n, m);
        for (int i = 0; i < n; i++) 
            printf("%d\n", numbers[i]);
    }
    printf("0 0\n");
}