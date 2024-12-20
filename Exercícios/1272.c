/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 60;

typedef struct cell {
    char *value;
    struct cell *next;
} cell;

void insert(char *text, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->value = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    if (text[0] == '\0') newCell->value[0] = '\0';
    else strcpy(newCell->value, text);
    newCell->next = NULL;
    if (*et == NULL) *et = *es = newCell;
    else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

void printResults(cell *first) {
    cell *p;
    for (p = first; p != NULL; p = p->next)
        printf("%s\n", p->value);
}

void string_process(char *t, char *res) {
    int newWord = 1, c = 0;
    char *word = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));

    for (int i = 0; t[i] != '\0'; i++) {
        if (t[i] >= 'a' && t[i] <= 'z' && newWord) {
            res[c++] = t[i];
            newWord = 0;
        } else if (t[i] == ' ') {
            newWord = 1;
        }
    }

    res[c] = '\0';
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int n;
    char text[MAX_CHAR_LENGTH], result[MAX_CHAR_LENGTH];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(text, MAX_CHAR_LENGTH, stdin);
        text[strcspn(text, "\n")] = 0;

        string_process(text, result);

        insert(result, &s, &t);
    }

    printResults(s);
    return 0;
}
