/*********************************************************************
* UNIFESP - Universidade Federal de São Paulo
* Nome: Bruno Shiohei Kinoshita do Nascimento
* RA: 176475
* Observação: Resolvido utilizando estrutura de dados Listas e Pilhas
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAX_CHAR_LENGTH = 2000;

typedef struct queueCell {
    char *result;
    struct queueCell *next;
} queueCell;

void insert(char *y, queueCell **es, queueCell **et) {
    queueCell *newCell = (queueCell *)malloc(sizeof(queueCell));
    newCell->result = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(newCell->result, y);
    newCell->next = NULL;

    if (*et == NULL)
        *et = *es = newCell;
    else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

char *popQueueCell(queueCell **es, queueCell **et) {
    queueCell *p = *es;
    char *x = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(x, p->result);
    *es = p->next;
    free(p);
    if (*es == NULL) *et = NULL;
    return x;
}

typedef struct cell {
    char value;
    struct cell *next;
} cell;

void createCell(char v, cell *p) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->value = v;
    newCell->next = p->next;
    p->next = newCell;
}

char pop(cell *p) {
    cell *q = p->next;
    char v = q->value;
    p->next = q->next;
    free(q);
    return v;
}

int precedence(char op) {
    if (op == '|') return 1;
    if (op == '.') return 2;
    if (op == '>' || op == '<' || op == '=' || op == '#') return 3;
    if (op == '+' || op == '-') return 4;
    if (op == '*' || op == '/') return 5;
    if (op == '^') return 6;
    return 0;
}

int isValidChar(char c) {
    return isalpha(c) || isdigit(c) || c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ||
           c == '>' || c == '<' || c == '=' || c == '#' || c == '|' || c == '.';
}

int validateExpression(char *s) {
    int balance = 0, lastWasOperator = 1, lastWasOperand = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (!isValidChar(c)) return 0;

        if (isdigit(c) || isalpha(c)) {
            if (lastWasOperand) return -1; 
            lastWasOperand = 1;
            lastWasOperator = 0;
        } else if (c == '(') {
            balance++;
            lastWasOperator = 1;
            lastWasOperand = 0;
        } else if (c == ')') {
            balance--;
            if (balance < 0) return -1; 
            lastWasOperand = 1;
            lastWasOperator = 0;
        } else { 
            if (lastWasOperator) return -1; 
            lastWasOperator = 1;
            lastWasOperand = 0;
        }
    }

    if (balance != 0) return -1;
    if (lastWasOperator) return -1; 

    return 1;
}

char *stringProcess(char *s) {
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
                posfixed[index] = '\0';
            }
            pop(head);
            continue;
        }

        if (strchr("+-*/^><=#|.", s[i])) {
            while (head->next != NULL && precedence(head->next->value) >= precedence(s[i])) {
                char operator = pop(head);
                posfixed[index++] = operator;
                posfixed[index] = '\0';
            }
            createCell(s[i], head);
            continue;
        }

        posfixed[index++] = s[i];
        posfixed[index] = '\0';
    }

    while (head->next != NULL) {
        char operator = pop(head);
        posfixed[index++] = operator;
        posfixed[index] = '\0';
    }

    return posfixed;
}

int main() {
    queueCell *s, *t;
    s = t = NULL;

    char str[MAX_CHAR_LENGTH];

    while (fgets(str, MAX_CHAR_LENGTH, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';

        int validation = validateExpression(str);
        if (validation == 0) {
            insert("Lexical Error!", &s, &t);
        } else if (validation == -1) {
            insert("Syntax Error!", &s, &t);
        } else {
            char *result = stringProcess(str);
            insert(result, &s, &t);
        }
    }

    while (s != NULL) {
        char *r = popQueueCell(&s, &t);
        printf("%s\n", r);
    }

    return 0;
}