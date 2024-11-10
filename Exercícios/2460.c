/********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Listas e Filas
********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR = 500000;

typedef struct cell {
    int id;
    struct cell *next;
} cell;

void printQueue(cell *head) {
    cell *p;
    for (p = head->next; p != NULL; p = p->next) {
        printf("%d", p->id);
        if (p->next != NULL) printf(" ");
    }
    printf("\n");
}

void pop(int id, cell *head) {
    cell *p, *q;

    p = head;
    q = head->next;
    while (q != NULL) {
        if (q->id == id) {
            p->next = q->next;
            free(q);
            break;
        }
        p = q;
        q = q->next;
    }
}

void removeIdsFromQueue(char *ids, int t, cell *head) {
    char *id;
    int integerId;

    id = strtok(ids, " ");
    for (int i = 0; i < t; i++) {
        integerId = strtol(id, NULL, 10);
        pop(integerId, head);
        id = strtok(NULL, " ");
    }
}

void createCell(int v, cell *p) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->id = v;
    newCell->next = p->next;
    p->next = newCell;
}

cell* strSplit(char *str, int n) {
    char *id;
    int integerId;

    cell *head = (cell*)malloc(sizeof(cell));
    head->next = NULL;
    cell *last = head;

    id = strtok(str, " ");
    for (int i = 0; i < n; i++) {
        integerId = strtol(id, NULL, 10);
        createCell(integerId, last);
        id = strtok(NULL, " ");
        last = last->next;
    }

    return head;
}

int main() {
    int n, m;
    char initialQueue[MAX_CHAR], idsToRemoveList[MAX_CHAR];

    scanf("%d", &n);
    getchar();
    fgets(initialQueue, MAX_CHAR, stdin);

    scanf("%d", &m);
    getchar();
    fgets(idsToRemoveList, MAX_CHAR, stdin);

    cell *queue = strSplit(initialQueue, n);
    removeIdsFromQueue(idsToRemoveList, m, queue);

    printQueue(queue);
}
