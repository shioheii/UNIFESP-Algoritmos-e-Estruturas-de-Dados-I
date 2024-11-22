/*******************************************************************************
* UNIFESP - Universidade Federal de São Paulo
* Nome: Bruno Shiohei Kinoshita do Nascimento
* RA: 176475
* Observação: Resolvido utilizando estrutura de dados Listas, Filas e Ordenação
********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 30;

typedef struct cell {
    char *name;
    struct cell *next;
} cell;

void printName(cell *lst, int index) {
    cell *p = lst;
    for (int i = 1; i < index; i++)
        p = p->next;
    printf("%s\n", p->name);
}

void createCell(char *v, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->name = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(newCell->name, v);
    newCell->next = NULL;
    if (*et == NULL) *et = *es = newCell;
    else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

void sortListItems(cell *lst) {
    cell *p, *q;
    char aux[MAX_CHAR_LENGTH];
    for (p = lst; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (strcmp(p->name, q->name) > 0) {
                strcpy(aux, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, aux);
            }
        }
    }
}

int main() {
    char firstInput[MAX_CHAR_LENGTH];
    cell *s, *t;
    s = t = NULL;

    fgets(firstInput, MAX_CHAR_LENGTH, stdin);
    int n = strtol(strtok(firstInput, " "), NULL, 10);
    int k = strtol(strtok(NULL, " "), NULL, 10);

    char *name = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    for (int i = 0; i < n; i++) {
        fgets(name, MAX_CHAR_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0;
        createCell(name, &s, &t);
    }

    free(name);
    sortListItems(s);
    printName(s, k);
}
