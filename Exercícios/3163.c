/*********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Listas e Filas
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 10;

typedef struct cell {
    char *value;
    struct cell *next;
} cell;

char *pop(cell **es, cell **et) {
    cell *p;
    p = *es;
    char *x = (char *)malloc(MAX_CHAR_LENGTH * sizeof(char));;
    strcpy(x, p->value);
    *es = p->next;
    free(p);
    if (*es == NULL) *et = NULL;
    return x;
}

void insert(char *y, cell **es, cell **et) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->value = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char)); 
    strcpy(newCell->value, y);
    newCell->next = NULL;
    if (*et == NULL) *et = *es = newCell;
    else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

int main() {
    cell *first[4] = { NULL, NULL, NULL, NULL };
    cell *last[4] = { NULL, NULL, NULL, NULL };

    char str[MAX_CHAR_LENGTH], side;
    while (fgets(str, MAX_CHAR_LENGTH, stdin)) {
        str[strcspn(str, "\n")] = 0;
        if (strcmp(str, "0") == 0) break;
        if (str[0] == '-') {
            side = str[1];
            continue;
        }

        if (side == '1') insert(str, &first[0], &last[0]);
        else if (side == '3') insert(str, &first[1], &last[1]);
        else if (side == '2') insert(str, &first[2], &last[2]);
        else insert(str, &first[3], &last[3]);
    }

    int firstPrinted = 0;
    while (first[0] != NULL || first[1] != NULL || first[2] != NULL || first[3] != NULL) {
        for (int i = 0; i < 4; i++) {
            if (first[i] != NULL) {
                if (firstPrinted) printf(" ");
                printf("%s", pop(&first[i], &last[i]));
                if (firstPrinted == 0) firstPrinted = 1;
            }
        }
    }

    printf("\n");
    return 0;
}
