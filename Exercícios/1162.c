/*****************************************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas e ordenação com Bubble Sort
******************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 200;

typedef struct cell {
    int value;
    struct cell *next;
} cell;

void insert(int v, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->value = v;
    newCell->next = NULL;
    if (*et == NULL) *et = *es = newCell;
    else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

int sort(cell *lst) {
    cell *p, *q;

    int aux, x = 0;
    for (p = lst; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->value > q->value) {
                aux = p->value;
                p->value = q->value;
                q->value = aux;
                x++;
            }
        }
    }

    return x;
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int n, l, integerVagao;
    char input[MAX_CHAR_LENGTH], *vagao;

    scanf("%d", &n);
    getchar();

    int swaps[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &l);
        getchar();

        fgets(input, MAX_CHAR_LENGTH, stdin);
        vagao = strtok(input, " ");
        while(vagao != NULL) {
            integerVagao = strtol(vagao, NULL, 10);
            insert(integerVagao, &s, &t);
            vagao = strtok(NULL, " ");
        }

        swaps[i] = sort(s);
        s = t = NULL; 
    }

    for (int i = 0; i < n; i++) {
        printf("Optimal train swapping takes %d swaps.\n", swaps[i]);
    }
}

