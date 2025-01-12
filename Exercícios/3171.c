/************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell {
    int id;
    int connected;
    struct cell *next;
} cell;

void insert(int id, cell **es, cell **et) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->id = id;
    newCell->connected = 0;
    newCell->next = NULL;

    if (*et == NULL) {
        *es = *et = newCell;
    } else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

void printList(cell *first) {
    cell *p;
    for (p = first; p != NULL; p = p->next)
        printf("id: %d c: %d\n", p->id, p->connected);
}

void connectLeds(int id1, int id2, cell *first) {
    cell *p;
    int connecteds = 0;

    for (p = first; p != NULL; p = p->next) {
        if (p->id == id1 || p->id == id2) {
            p->connected = 1;
            connecteds++;
            if (connecteds == 2) return;
        }
    }
}

int thereIsDisconnectedLeds(cell *first) {
    cell *p;
    for (p = first; p != NULL; p = p->next) {
        if (p->connected == 0) return 1;
    }
    return 0;
}

int main() {
    cell *s, *t;
    s = t = NULL;
    
    int N, L, X, Y;

    while (scanf("%d %d", &N, &L) != EOF) {
        getchar();

        for (int i = 1; i <= N; i++) insert(i, &s, &t);

        for (int i = 0; i < L; i++) {
            scanf("%d %d", &X, &Y);
            getchar();
            connectLeds(X, Y, s);
        }

        if (L < N - 1)                        printf("INCOMPLETO\n");
        else if (!thereIsDisconnectedLeds(s)) printf("COMPLETO\n");
        else                                  printf("INCOMPLETO\n");

        s = t = NULL;
    }

    return 0;
}