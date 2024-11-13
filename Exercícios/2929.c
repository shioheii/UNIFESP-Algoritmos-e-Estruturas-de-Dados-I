/*********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Listas e Pilhas
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 50;

typedef struct cell {
    int value;
    struct cell *next;
} cell;

void pop(cell *p) {
    cell *q = p->next;
    p->next = q->next;
    free(q);
}

void createCell(int v, cell *p) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->value = v;
    newCell->next = p->next;
    p->next = newCell;
}

int findMinValue(cell *lst) {
    cell *p = lst->next;
    int minValue = p->value;
    for (p = p->next; p != NULL; p = p->next)
        if (p->value < minValue) minValue = p->value;

    return minValue;
}

int stringProcess(char *c, cell *p) {
    char *command, *value;
    int integerValue;

    command = strtok(c, " ");
    if (strcmp(command, "PUSH") == 0) {
        value = strtok(NULL, " ");
        integerValue = strtol(value, NULL, 10);
        createCell(integerValue, p);
    } else {
        if (p->next == NULL) return -1;
        
        if (strcmp(command, "POP") == 0) {
            pop(p);
        } else {
            return findMinValue(p);
        }
    }

    return -2;
}

int main() {
    int n;
    char commandLine[MAX_CHAR_LENGTH];

    scanf("%d", &n);
    getchar();

    cell *head = (cell*)malloc(sizeof(cell));
    head->next = NULL;

    int results[n];
    for (int i = 0; i < n; i++) {
        fgets(commandLine, MAX_CHAR_LENGTH, stdin);
        commandLine[strcspn(commandLine, "\n")] = 0;

        results[i] = stringProcess(commandLine, head);
    }

    for (int i = 0; i < n; i++) {
        if (results[i] > -1) printf("%d\n", results[i]);
        else if (results[i] == -1) printf("EMPTY\n");
    }
}
