/******************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando o metodo de ordenação Quicksort
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_CHAR_LENGTH = 100000;
const int MAX_NUMBER_LENGTH = 10;

typedef struct cell {
    int index;
    int value;
    struct cell *next;
} cell;

cell insert(int i, int v) {
    cell newCell;
    newCell.index = i;
    newCell.value = v;
    newCell.next = NULL;
    return newCell;
}

int separa(int p, int r, cell v[]) {
    int j, k;
    cell c, t;

    c = v[r];
    j = p;
    for (k = p; k < r; k++) {
        if (v[k].value < c.value || (v[k].value == c.value && v[k].index < c.index)) {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = c;
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

int searchIndexOfValue(int occurrence, int value, cell values[], int t) {
    int matches = 0;
    for (int i = 0; i < t && values[i].value <= value; i++) {
        if (value == values[i].value) matches++;
        if (matches == occurrence) return values[i].index;
    }
    return 0;
}

int main() {
    int n, m, k, v, integerNumber;
    char str[MAX_CHAR_LENGTH];
    char *number;

    while (scanf("%d %d", &n, &m) != EOF) {
        getchar();

        cell vet[n];
        int i = 0;   

        fgets(str, MAX_CHAR_LENGTH, stdin);
        number = strtok(str, " ");
        while (number != NULL && i < n) {
            integerNumber = strtol(number, NULL, 10);
            vet[i] = insert(i + 1, integerNumber);
            number = strtok(NULL, " ");
            i++;
        }

        quicksort(0, n - 1, vet);

        for (int j = 0; j < m; j++) {
            scanf("%d %d", &k, &v);
            getchar(); 

            int search = searchIndexOfValue(k, v, vet, n);
            printf("%d\n", search);
        }
    }

    return 0;
}