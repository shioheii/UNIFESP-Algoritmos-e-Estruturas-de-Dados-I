/*************************************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas e ordenação com Mergesort
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell {
    int value;
    struct cell *next;
} cell;

void insert(int value, cell **es, cell **et) {
    cell *newCell = (cell *)malloc(sizeof(cell));
    newCell->value = value;
    newCell->next = NULL;
    if (*et == NULL) {
        *es = *et = newCell;
    } else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

// START MERGESORT ALGORITHM
void splitList(cell *source, cell **frontRef, cell **backRef) {
    cell *slow = source;
    cell *fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

cell *sortedMerge(cell *a, cell *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    cell *result = NULL;

    if (a->value <= b->value) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

void mergeSort(cell **headRef) {
    cell *head = *headRef;
    if (head == NULL || head->next == NULL) {
        return;
    }

    cell *a, *b;

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}
// END MERGESORT ALGORITHM

char* search(int v, cell *first) {
    cell *p;
    char *message = (char*)malloc(50 * sizeof(char));
    int firstOcurrence = -1, lastOcurrence = -1, index = 0;

    for (p = first; p != NULL && p->value <= v; p = p->next) {
        if (p->value == v && firstOcurrence == -1) {
            firstOcurrence = index;
            lastOcurrence = index;
        } else if (p->value == v) {
            lastOcurrence = index;
        }
        index++;
    }

    if (firstOcurrence != -1 && lastOcurrence != -1) {
        sprintf(message, "%d found from %d to %d", v, firstOcurrence, lastOcurrence);
        return message;
    }  
    
    sprintf(message, "%d not found", v);
    return message;
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int N, X, Y, NUM;

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &X, &Y);
            
            for (int i = X; i <= Y; i++)
                insert(i, &s, &t);
        }

        scanf("%d", &NUM);

        mergeSort(&s);

        printf("%s\n", search(NUM, s));
        s = t = NULL;
    }

    return 0;
}