/****************************************************************************
* UNIFESP - Universidade Federal de São Paulo
* Nome: Bruno Shiohei Kinoshita do Nascimento
* RA: 176475
* Observação: Resolvido utilizando estrutura de dados Listas, Filas e Pilhas
*****************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 2000;

typedef struct queueCell {
    char *result;
    struct queueCell *next;
} queueCell;

char *popQueueCell(queueCell **es, queueCell **et) {
    queueCell *p;
    p = *es;
    char *x = (char *)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(x, p->result);
    *es = p->next;
    free(p);
    if (*es == NULL) *et = NULL;
    return x;
}

void insert(char *y, queueCell **es, queueCell **et) {
    queueCell *newCell = (queueCell*)malloc(sizeof(queueCell));
    newCell->result = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char)); 
    strcpy(newCell->result, y);
    newCell->next = NULL;
    if (*et == NULL) *et = *es = newCell;
    else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

typedef struct cell {
    char value;
    struct cell *next;
} cell;

char pop(cell *p) {
    cell *q = p->next;
    char v = q->value;
    p->next = q->next;
    free(q);
    return v;
}

void createCell(char v, cell *p) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->value = v;
    newCell->next = p->next;
    p->next = newCell;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

char* stringProcess(char *s) {
    cell *head = (cell*)malloc(sizeof(cell));
    head->next = NULL;

    char *posfixed = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    posfixed[0] = '\0';
    int index = 0; 

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            createCell(s[i], head);
            continue;
        }

        if (s[i] == ')') {
            while (head->next->value != '(') {
                char operator = pop(head);
                posfixed[index++] = operator;
                posfixed[index+1] = '\0';
            }
            pop(head);
            continue;
        }

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
            while (head->next != NULL && precedence(head->next->value) >= precedence(s[i])) {
                char operator = pop(head);
                posfixed[index++] = operator;
                posfixed[index+1] = '\0';
            }
            createCell(s[i], head);
            continue;
        }

        posfixed[index++] = s[i];
        posfixed[index+1] = '\0';
    }

    while (head->next != NULL) {
        char operator = pop(head);
        posfixed[index++] = operator;
        posfixed[index+1] = '\0';
    }

    return posfixed;
}

int main() {
    int n;
    char str[MAX_CHAR_LENGTH];
    queueCell *s, *t;
    s = t = NULL;

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(str, MAX_CHAR_LENGTH, stdin);
        str[strcspn(str, "\n")] = 0;
        char* result = stringProcess(str);
        insert(result, &s, &t);
        free(result); 
    }

    while (s != NULL) {
        char* r = popQueueCell(&s, &t);
        printf("%s\n", r);
        free(r);
    }
}
