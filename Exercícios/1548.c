/*********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Listas e Filas
*********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 10000;

typedef struct cell {
    int value;
    struct cell *next;
} cell;

void createCell(int y, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->value = y;
    newCell->next = NULL;
    if (*et == NULL) *et = *es = newCell;
    else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

int countNoChanges(cell *lst, cell *sortedLst) {
    cell *p = lst;
    cell *q = sortedLst;
    int noChanges = 0;
    while (p != NULL && q != NULL) {
        if (p->value == q->value)
            noChanges++;
        p = p->next;
        q = q->next;
    }

    return noChanges;
}

cell* sortListItems(cell *lst) {
    cell *p, *q;

    cell *s, *t;
    s = t = NULL;
    for (p = lst; p != NULL; p = p->next)
        createCell(p->value, &s, &t);

    int aux;
    for (p = s; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->value < q->value) {
                aux = p->value;
                p->value = q->value;
                q->value = aux;
            }
        }
    }

    return s;
}

cell* str_split(char *str, int n) {
    cell *s, *t;
    s = t = NULL;

    int integerItem;
    char *item;
    item = strtok(str, " ");
    for (int i = 0; i < n; i++) {
        integerItem = strtol(item, NULL, 10);
        createCell(integerItem, &s, &t);
        item = strtok(NULL, " ");
    }

    return s;
}

int main() {
    int n, m;
    char str[MAX_CHAR_LENGTH];
    
    scanf("%d", &n);
    getchar();

    cell *allQueues[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        getchar();
        fgets(str, MAX_CHAR_LENGTH, stdin);

        allQueues[i] = str_split(str, m);
    }

    cell *sortedList;
    int studentsNotChangePlaces;
    for (int i = 0; i < n; i++) {
        sortedList = sortListItems(allQueues[i]);

        studentsNotChangePlaces = countNoChanges(allQueues[i], sortedList);
        printf("%d\n", studentsNotChangePlaces);
    }
}
