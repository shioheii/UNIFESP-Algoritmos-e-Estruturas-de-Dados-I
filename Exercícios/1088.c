/*****************************************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas e ordenação com Bubble Sort
******************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 1000000;

typedef struct cell {
    int value;
    struct cell *next;
} cell;

void insert(int v, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->value = v;
    newCell->next = NULL;
    if (*et == NULL) *et = *es = newCell;
    else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

void printList(cell *first) {
    cell *p;
    for (p = first; p != NULL; p = p->next)
        printf(p->value % 2 == 0 ? "Marcelo\n" : "Carlos\n");
}

int sort(cell *lst) {
    cell *p, *q;

    int aux, x = 1;
    for (p = lst; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->value > q->value) x++;
        }
    }

    return x;
}

int main() {
    cell *s, *t, *rs, *rt;
    s = t = rs = rt = NULL;

    int n, integerNumber;
    char input[MAX_CHAR_LENGTH], *number;

    fgets(input, MAX_CHAR_LENGTH, stdin);
    while (strcmp(input, "0") != 0) {
        
        number = strtok(input, " ");
        n = strtol(number, NULL, 10);

        number = strtok(NULL, " ");
        while(number != NULL) {
            integerNumber = strtol(number, NULL, 10);
            insert(integerNumber, &s, &t);
            number = strtok(NULL, " ");
        }

        int player = sort(s);
        insert(player, &rs, &rt);

        s = t = NULL;
        fgets(input, MAX_CHAR_LENGTH, stdin);
    }

    printList(rs);
    return 0;
}
