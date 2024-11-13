/*********************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Listas e Pilhas
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 300;
const int MAX_TEMP_CHAR_LENGTH = 50;

/*** ESTRUTURA DE DADOS E METODOS PARA LISTA DE RESULTADOS ***/
typedef struct queueCell {
    char *text;
    struct queueCell *next;
} queueCell;

void createQueue(char *v, queueCell *p) {
    queueCell *newCell = (queueCell*)malloc(sizeof(queueCell));
    newCell->text = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(newCell->text, v);
    newCell->next = p->next;
    p->next = newCell;
}

void printQueueResults(queueCell *lst) {
    queueCell *p;
    for (p = lst->next; p != NULL; p = p->next)
        printf("%s", p->text);
}
/*** FIM ESTRUTURA DE DADOS E METODOS PARA LISTA DE RESULTADOS ***/

/*** ESTRUTURA DE DADOS E METODOS DE PILHAS ***/
typedef struct stackCell {
    int value;
    struct stackCell *next;
} stackCell;

int pop(stackCell *p) {
    stackCell *q = p->next;
    int x = q->value;
    p->next = q->next;
    free(q);
    return x;
}

void createStackCell(int v, stackCell *p) {
    stackCell *newCell = (stackCell*)malloc(sizeof(stackCell));
    newCell->value = v;
    newCell->next = p->next;
    p->next = newCell;
}
/*** FIM ESTRUTURA DE DADOS E METODOS DE PILHAS ***/

stackCell* createStack(int n) {
    stackCell *head = (stackCell*)malloc(sizeof(stackCell));
    head->next = NULL;

    for (int i = n; i >= 1; i--)
        createStackCell(i, head);
    return head;
}

char* findRemainingCard(int t, stackCell *p) {
    stackCell *q, *remaining;
    char *result = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    char temp[MAX_TEMP_CHAR_LENGTH];
    int removedCards[t];
    for (int i = 0; i < t - 1; i++) {
        removedCards[i] = pop(p);
        q = remaining = p->next;
        while (q->next != NULL)
            q = q->next;
        q->next = remaining;
        p->next = remaining->next;
        remaining->next = NULL;
    }

    strcpy(result, "Discarded cards: ");
    for (int i = 0; i < t - 2; i++) {
        sprintf(temp, "%d, ", removedCards[i]);
        strcat(result, temp);
    }
    sprintf(temp, "%d\n", removedCards[t - 2]);
    strcat(result, temp);

    sprintf(temp, "Remaining card: %d\n", p->next->value);
    strcat(result, temp);

    return result;
}

int main() {
    int cards;
    stackCell *stack;
    char *result;

    queueCell *queueResults = (queueCell*)malloc(sizeof(queueCell));
    queueResults->next = NULL;
    queueCell *lastQueueResult = queueResults;

    scanf("%d", &cards);
    getchar();
    while (cards != 0) {
        stack = createStack(cards);
        result = findRemainingCard(cards, stack);
        createQueue(result, lastQueueResult);
        lastQueueResult = lastQueueResult->next;

        scanf("%d", &cards);
        getchar();
    }

    printQueueResults(queueResults);

    return 0;
}
