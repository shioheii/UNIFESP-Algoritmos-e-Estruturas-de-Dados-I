/***************************************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas e ordenação com Bubblesort
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 21;

typedef struct cell {
    char *meatName;
    int validity;
    struct cell *next;
} cell;

void insert(char *n, int v, cell **es, cell **et) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->meatName = (char*)malloc(MAX_LENGTH * sizeof(char));
    strcpy(newCell->meatName, n);
    newCell->validity = v;
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
    for (p = first; p != NULL; p = p->next) {
        printf("%s", p->meatName);
        if (p->next != NULL) printf(" ");
        else                 printf("\n");
    }
}

void sort(cell *lst) {
    cell *p, *q;
    char tempPieceOfMeat[MAX_LENGTH];
    int tempValidity;

    for (p = lst; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->validity > q->validity) {
                strcpy(tempPieceOfMeat, p->meatName);
                strcpy(p->meatName, q->meatName);
                strcpy(q->meatName, tempPieceOfMeat);

                tempValidity = p->validity;
                p->validity = q->validity;
                q->validity = tempValidity;
            }
        }
    }
}

int main() {
    cell *s, *t;
    s = t = NULL;
    
    int N, D;
    char pieceOfMeat[MAX_LENGTH];

    while (scanf("%d", &N) != EOF) {
        getchar();
        for (int i = 0; i < N; i++) {
            scanf("%s %d", pieceOfMeat, &D);
            insert(pieceOfMeat, D, &s, &t);
        }

        sort(s);
        printList(s);
        s = t = NULL;
    }

    return 0;
}
