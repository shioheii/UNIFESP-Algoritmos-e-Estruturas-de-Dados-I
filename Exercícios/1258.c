/******************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando o metodo de ordenação Quicksort
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_NAME_LENGTH = 100;
const int MAX_DETAILS_LENGTH = 12;

typedef struct cell {
    char length;      
    char *color;  
    char *name;   
} cell;

cell insert(char l, char *c, char *n) {
    cell newCell;
    newCell.color = (char*)malloc(MAX_DETAILS_LENGTH * sizeof(char));
    newCell.name = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    strcpy(newCell.color, c);
    strcpy(newCell.name, n);
    newCell.length = l;
    return newCell;
}

int compare(cell a, cell b) {
    int colorCmp = strcmp(a.color, b.color);
    if (colorCmp != 0) return colorCmp;

    if (a.length != b.length) return b.length - a.length;

    return strcmp(a.name, b.name);
}

int separa(int p, int r, cell v[]) {
    int j = p;
    cell c = v[r], t;

    for (int k = p; k < r; k++) {
        if (compare(v[k], c) < 0) {
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
    if (p < r) {
        int j = separa(p, r, v);
        quicksort(p, j - 1, v);
        quicksort(j + 1, r, v);
    }
}

int main() {
    int n, isFirstCase = 1;
    char name[MAX_NAME_LENGTH], *color, details[MAX_DETAILS_LENGTH], length;

    while (scanf("%d", &n) && n != 0) {
        getchar();
        if (!isFirstCase) printf("\n");
        else              isFirstCase = 0;

        cell vet[n];
        for (int i = 0; i < n; i++) {
            fgets(name, MAX_NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0';
            fgets(details, MAX_DETAILS_LENGTH, stdin);
            color = strtok(details, " ");
            length = strtok(NULL, " ")[0];

            vet[i] = insert(length, color, name);
        }

        quicksort(0, n - 1, vet);

        for (int i = 0; i < n; i++) 
            printf("%s %c %s\n", vet[i].color, vet[i].length, vet[i].name);
    }

    return 0;
}
