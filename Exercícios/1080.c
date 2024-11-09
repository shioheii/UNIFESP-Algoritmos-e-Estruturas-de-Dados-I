/*************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Listas
*************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct cell {
    int index;
    int value;
    struct cell *next;
} cell;

cell* searchMaxValue(cell *lst) {
    cell *m = (cell*)malloc(sizeof(cell)); // Por padrão, o primeiro item é o maior
    m = lst->next;

    cell *p = m->next;
    while (p != NULL) {
        if (p->value > m->value)
            m = p;
        p = p->next;
    }

    return m;
}

void createCell(int i, int v, cell *p) {
    cell *nova = (cell*)malloc(sizeof(cell));
    nova->index = i;
    nova->value = v;
    nova->next = p->next;
    p->next = nova;
}

int main() {
    int n;
    cell *head = (cell*)malloc(sizeof(cell));
    head->next = NULL;
    cell *last = head;

    for (int i = 1; i <= 100; i++) {
        scanf("%d", &n);

        createCell(i, n, last);
        last = last->next;
    }

    cell *maxValue = searchMaxValue(head);
    printf("%d\n%d\n", maxValue->value, maxValue->index);
}
