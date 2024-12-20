/***********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando o método de ordenação com Quicksort
************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 1000;

typedef struct cell {
    int index;
    int value;
    int module;
    struct cell *next;
} cell;

void printResults(cell v[], int t, int mod) {
    int j = 0;
    for (int i = 0; i < mod; i++) {
        printf("%d -> ", i);
        for (j; j < t && v[j].module == i; j++) {
            printf("%d -> ", v[j].value);
        }
        printf("\\\n");
    }
}

cell insert(int i, int v, int m) {
    cell newCell;
    newCell.index = i;
    newCell.value = v;
    newCell.module = m;
    newCell.next = NULL;
    return newCell;
}

int separa(int p, int r, cell v[]) {
    int j, k;
    cell c, t;

    c = v[r]; j = p;
    for (k = p; k < r; k++) {
        if (v[k].module < c.module || (v[k].module == c.module && v[k].index < c.index)) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    }
    v[r] = v[j], v[j] = c;
    return j;
}

void quicksort(int p, int r, cell v[]) {
    int j;
    if (p < r) {
        j = separa(p, r, v);
        quicksort(p, j - 1, v);
        quicksort(j + 1, r, v);
    }
}

int main() {
    int n, m, c, integerKey, mod;
    char keys[MAX_CHAR_LENGTH];
    char *key = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &c);
        getchar();

        cell modules[c];
        int cont = 0;
        fgets(keys, MAX_CHAR_LENGTH, stdin);

        key = strtok(keys, " ");
        while (key != NULL) {
            integerKey = strtol(key, NULL, 10);
            mod = integerKey % m;
            modules[cont] = insert(cont, integerKey, mod);
            key = strtok(NULL, " ");
            cont++;
        }

        quicksort(0, c-1, modules);
        printResults(modules, c, m);

        if (i < n - 1) printf("\n");
    }
    
    return 0;
}
