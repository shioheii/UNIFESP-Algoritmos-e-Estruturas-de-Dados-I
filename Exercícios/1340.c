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
typedef struct heapNode {
    int value;
    struct heapNode *left;
    struct heapNode *right;
} heapNode;

void swap(heapNode *a, heapNode *b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

void downheap(heapNode *root) {
    if (root == NULL) return;
    heapNode *largest = root;
    heapNode *left = root->left;
    heapNode *right = root->right;
    if (left != NULL && left->value > largest->value) {
        largest = left;
    }
    if (right != NULL && right->value > largest->value) {
        largest = right;
    }
    if (largest != root) {
        swap(root, largest);
        downheap(largest); 
    }
}

void upheap(heapNode *root) {
    if (root == NULL || root->left == NULL) return;
    heapNode *largest = root;
    heapNode *left = root->left;
    if (left != NULL && left->value > largest->value) {
        largest = left;
    }
    if (largest != root) {
        swap(root, largest);
        upheap(largest);
    }
}

void insertHeapMax(heapNode **root, int value) {
    heapNode *newNode = (heapNode*) malloc(sizeof(heapNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if (*root == NULL) {
        *root = newNode;
    } else {
        heapNode *lastNode = *root;
        while (lastNode->left != NULL && lastNode->right != NULL) {
            if (lastNode->left != NULL) {
                lastNode = lastNode->left;
            }
        }
        if (lastNode->left == NULL) {
            lastNode->left = newNode;
        } else {
            lastNode->right = newNode;
        }
        upheap(newNode);
    }
}

int popHeapMax(heapNode **root) {
    if (*root == NULL) return -1;
    int x = (*root)->value;
    heapNode *lastNode = *root;
    heapNode *largest = *root;
    swap(*root, lastNode);
    free(lastNode);
    downheap(largest);
    return x;
}
/*** END HEAP MAX STRUCT AND METHODS ***/

int main() {
    cell *s, *t, *resultsQueueInit, *resultsQueueEnd;
    s = t = resultsQueueInit = resultsQueueEnd = NULL;
    cell *stack = (cell*)malloc(sizeof(cell));
    // heapNode *heapMaxRoot = (heapNode*)malloc(sizeof(heapNode));

    char operationAndValue[MAX_CHAR_LENGTH];
    int operator, value, n, structUsed = 0;

    while (scanf("%d", &n) != EOF) {
        getchar();
        
        int totalRemoveds = 0, queueMatch = 0, stackMatch = 0, heapMatch = 0;

        for (int i = 0; i < n; i++) {
            fgets(operationAndValue, MAX_CHAR_LENGTH, stdin);
            operator = strtol(strtok(operationAndValue, " "), NULL, 10);
            value = strtol(strtok(NULL, " "), NULL, 10);

            if (operator == 1) {
                insertQueue(value, &s, &t);
                insertStack(value, stack);
                // insertHeapMax(&heapMaxRoot, value);
            } else {
                totalRemoveds++;

                if (popQueue(&s, &t) == value) queueMatch++;
                if (popStack(stack) == value) stackMatch++;
                // if (popHeapMax(&heapMaxRoot) == value) heapMatch++;
            }
        }

        if (queueMatch != totalRemoveds && stackMatch != totalRemoveds && heapMatch != totalRemoveds)
            structUsed = 5;

        if ((queueMatch == totalRemoveds && stackMatch == totalRemoveds) ||
            (queueMatch == totalRemoveds && heapMatch == totalRemoveds) ||
            (stackMatch == totalRemoveds && heapMatch == totalRemoveds))
            structUsed = 4;

        if (queueMatch == totalRemoveds) structUsed = 1;
        if (stackMatch == totalRemoveds) structUsed = 2;
        if (heapMatch == totalRemoveds) structUsed = 3;

        insertQueue(structUsed, &resultsQueueInit, &resultsQueueEnd);
    }

    printQueueResults(resultsQueueInit);

    return 0;
}
