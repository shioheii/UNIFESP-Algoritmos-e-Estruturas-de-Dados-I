/***************************************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas e ordenação com Bubblesort
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 51;

typedef struct cell {
    char *name;   
    char region;     
    int cost;        
    struct cell *next;
} cell;

void insert(char *name, char region, int cost, cell **es, cell **et) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->name = (char*)malloc(MAX_LENGTH * sizeof(char));
    strcpy(newCell->name, name);
    newCell->region = region;
    newCell->cost = cost;
    newCell->next = NULL;

    if (*et == NULL) {
        *es = *et = newCell;
    } else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

void sort(cell *lst) {
    cell *p, *q;
    char tempName[MAX_LENGTH];
    char tempRegion;
    int tempCost;

    for (p = lst; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->cost > q->cost || 
               (p->cost == q->cost && p->region > q->region) || 
               (p->cost == q->cost && p->region == q->region && strcmp(p->name, q->name) > 0)) {

                strcpy(tempName, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, tempName);

                tempRegion = p->region;
                p->region = q->region;
                q->region = tempRegion;

                tempCost = p->cost;
                p->cost = q->cost;
                q->cost = tempCost;
            }
        }
    }
}

void printList(cell *first) {
    cell *p;
    for (p = first; p != NULL; p = p->next)
        printf("%s\n", p->name);
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int Q, cost;
    char name[MAX_LENGTH], region;

    while (scanf("%d", &Q) != EOF) {
        for (int i = 0; i < Q; i++) {
            scanf("%s %c %d", name, &region, &cost);
            insert(name, region, cost, &s, &t);
        }

        sort(s);
        printList(s);
        s = t = NULL;
    }

    return 0;
}
