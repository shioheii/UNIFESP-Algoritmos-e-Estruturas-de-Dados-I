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
    int diamonds = 0;
    for (int i = 0; v[i] != '\0'; i++) {
        if (v[i] == '<') {
            createCell(v[i], p);
        } else if (v[i] == '>') {
            if (p->next != NULL) {
                pop(p);
                diamonds++;
            }
        }
    }
    return diamonds;
}

int main() {
    char str[LIMIT_CHAR];
    int n;
    
    scanf("%d", &n);
    getchar();
    int diamonds[n];

    for (int i = 0; i < n; i++) {
        fgets(str, LIMIT_CHAR, stdin);

        cell *head = (cell*)malloc(sizeof(cell));
        head->next = NULL;
        diamonds[i] = stringProcess(str, head);
    }

    for (int i = 0; i < n; i++) 
        printf("%d\n", diamonds[i]);
}
