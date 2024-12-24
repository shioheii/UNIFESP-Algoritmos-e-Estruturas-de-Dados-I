/***************************************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas e ordenação com Bubblesort
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 11;

typedef struct cell {
    char *name;   
    char *murderedName;        
    struct cell *next;
} cell;

void insert(char *name, char *murderedName, cell **es, cell **et) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->name = (char*)malloc(MAX_LENGTH * sizeof(char));
    newCell->murderedName = (char*)malloc(MAX_LENGTH * sizeof(char));
    strcpy(newCell->name, name);
    strcpy(newCell->murderedName, murderedName);
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
    char tempName[MAX_LENGTH], tempMurderedName[MAX_LENGTH];

    for (p = lst; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (strcmp(p->name, q->name) > 0) {
                strcpy(tempName, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, tempName);

                strcpy(tempMurderedName, p->murderedName);
                strcpy(p->murderedName, q->murderedName);
                strcpy(q->murderedName, tempMurderedName);
            }
        }
    }
}

int isMurderMudered(cell *first, char *name) {
    cell *p;
    for (p = first; p != NULL; p = p->next) {
        if (strcmp(p->murderedName, name) == 0) 
            return 1;
    }
    return 0;
}

void printList(cell *first) {
    cell *p, *q;
    int killCount;

    printf("HALL OF MURDERERS\n");
    p = first;
    while (p != NULL) {
        killCount = 1;

        for (q = p->next; q != NULL && strcmp(p->name, q->name) == 0; q = q->next) 
            killCount++;

        if (!isMurderMudered(first, p->name)) printf("%s %d\n", p->name, killCount);
        p = q;
    }
}

int main() {
    cell *s, *t;
    s = t = NULL;

    char name[MAX_LENGTH], murderedName[MAX_LENGTH];

    while (scanf("%s %s", name, murderedName) != EOF) {
        insert(name, murderedName, &s, &t);
    }

    // sort(s);
    sort(s);
    printList(s);

    return 0;
}
