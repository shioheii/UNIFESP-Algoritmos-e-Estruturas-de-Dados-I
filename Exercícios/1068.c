/*********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Listas e Pilhas
*********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int LIMIT_CHAR = 1000;

typedef struct cell {
    char value;
    struct cell *next;
} cell;

void pop(cell *p) {
    cell *q = p->next;
    p->next = q->next;
    free(q);
}

void createCell(char v, cell *p) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->value = v;
    newCell->next = p->next;
    p->next = newCell;
}

int stringProcess(char *v, cell *p) {
    for (int i = 0; v[i] != '\0'; i++) {
        if (v[i] == '(') {
            createCell(v[i], p);
        } else if (v[i] == ')') {
            if (p->next != NULL) {
                pop(p);
            } else {
                return 0;
            }

        }
    }
    if (p->next != NULL) return 0;

    return 1;
}

int main() {
    char entrada[LIMIT_CHAR];
    int allStacks[10000];

    int i = 0;
    while(fgets(entrada, LIMIT_CHAR, stdin)){
        if (strcmp(entrada, "\n") == 0) break;

        cell *head = (cell*)malloc(sizeof(cell));
        head->next = NULL;
        allStacks[i++] = stringProcess(entrada, head);
    }

    for (int j = 0; j < i; j++) 
        printf(allStacks[j] == 0 ? "incorrect\n" : "correct\n");
}
