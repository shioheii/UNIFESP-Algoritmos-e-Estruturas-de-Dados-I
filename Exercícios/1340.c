/*****************************************************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Listas, Filas comuns e de Prioridade, e Pilhas
******************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 10;

typedef struct cell {
    int value;
    struct cell *next;
} cell;

/*** START QUEUE METHODS ***/
void insertQueue(int v, cell **es, cell **et) {
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

int popQueue(cell **es, cell **et) {
    cell *p;
    p = *es;
    int x = p->value;
    *es = p->next;
    free(p);
    if (*es == NULL) *et = NULL;
    return x;
}

void printQueueResults(cell *lst) {
    cell *p;
    for (p = lst; p != NULL; p = p->next) {
        if (p->value == 1) printf("queue\n");
        else if (p->value == 2) printf("stack\n");
        else if (p->value == 3) printf("priority queue\n");
        else if (p->value == 4) printf("not sure\n");
        else printf("impossible\n");
    }
}
/*** END QUEUE METHODS ***/

/*** START STACK METHODS ***/
int popStack(cell *p) {
    cell *q = p->next;
    int x = q->value;
    p->next = q->next;
    free(q);
    return x;
}

void insertStack(int v, cell *p) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->value = v;
    newCell->next = p->next;
    p->next = newCell;
}
/*** END STACK METHODS ***/

/*** START HEAP MAX STRUCT AND METHODS ***/
void SacodeHeap(int m, int v[]) {
    int t, f = 1;
    while (f < m) {
        if (f < m-1 && v[f-1] < v[f]) ++f;
        if (v[f/2-1] >= v[f-1]) break;
        t = v[f/2-1]; v[f/2-1] = v[f-1]; v[f-1] = t;
        f *= 2;
    }
}

int RemoveMaxHeap(int *n, int v[]) {
    if (*n <= 0) return -1; // Heap vazio

    int max = v[0]; // Raiz do heap (maior valor)
    v[0] = v[--(*n)]; // Mover o último elemento para a raiz
    SacodeHeap(*n, v); // Reordenar o heap
    return max;
}

void InsereEmHeap(int m, int v[]) {
    int f = m;
    while (f > 0 && v[f/2-1] < v[f-1]) {
        int t = v[f/2-1]; v[f/2-1] = v[f-1]; v[f-1] = t;
        f = f/2;
    }
}
/*** END HEAP MAX STRUCT AND METHODS ***/

int main() {
    cell *s, *t, *resultsQueueInit, *resultsQueueEnd;
    s = t = resultsQueueInit = resultsQueueEnd = NULL;
    cell *stack = (cell*)malloc(sizeof(cell));
    
    char operationAndValue[MAX_CHAR_LENGTH];
    int operator, value, n, structUsed = 0;

    while (scanf("%d", &n) != EOF) {
        getchar();
        
        int totalRemoveds = 0, queueMatch = 0, stackMatch = 0, heapMatch = 0;
        int heap[n], c = 0;

        for (int i = 0; i < n; i++) {
            fgets(operationAndValue, MAX_CHAR_LENGTH, stdin);
            operator = strtol(strtok(operationAndValue, " "), NULL, 10);
            value = strtol(strtok(NULL, " "), NULL, 10);

            if (operator == 1) {
                insertQueue(value, &s, &t);
                insertStack(value, stack);
                heap[c++] = value;
                InsereEmHeap(c, heap);
            } else {
                totalRemoveds++;

                if (popQueue(&s, &t) == value) queueMatch++;
                if (popStack(stack) == value) stackMatch++;
                if (RemoveMaxHeap(&c, heap) == value) heapMatch++;
            }
        }

        if (queueMatch != totalRemoveds && stackMatch != totalRemoveds && heapMatch != totalRemoveds)
            structUsed = 5;

        else if ((queueMatch == totalRemoveds && stackMatch == totalRemoveds) ||
                  (queueMatch == totalRemoveds && heapMatch == totalRemoveds) ||
                  (stackMatch == totalRemoveds && heapMatch == totalRemoveds))
            structUsed = 4;

        else if (queueMatch == totalRemoveds) structUsed = 1;
        else if (stackMatch == totalRemoveds) structUsed = 2;
        else                                  structUsed = 3;

        insertQueue(structUsed, &resultsQueueInit, &resultsQueueEnd);
    }

    printQueueResults(resultsQueueInit);

    return 0;
}
