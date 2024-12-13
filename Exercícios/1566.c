/*********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando o método de ordenação Quicksort
*********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 12000000;

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
    int nc, n, h;
    char *input = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    char *height;

    scanf("%d", &nc);
    getchar();

    for (int i = 0; i < nc; i++) {
        scanf("%d", &n);
        getchar();

        int c = 0;
        int *vetor = (int *)malloc(n * sizeof(int));

        fgets(input, MAX_CHAR_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        height = strtok(input, " ");
        while(height != NULL) {
            h = strtol(height, NULL, 10);
            vetor[c++] = h;
            height = strtok(NULL, " ");
        }

        quicksort(0, c-1, vetor);
        for (int j = 0; j < c; j++) {
            printf("%d", vetor[j]);
            if (j < c-1) printf(" ");
            else         printf("\n");
        }

        free(vetor);
    }

    free(input);
    return 0;
}
