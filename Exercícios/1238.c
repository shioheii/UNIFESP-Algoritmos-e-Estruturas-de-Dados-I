/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 110;
const int MAX_CHAR_INPUT_LENGTH = 55;

typedef struct cell {
    char *value;
    struct cell *next;
} cell;

void insert(char *text, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->value = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(newCell->value, text);
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

void string_process(char *str1, char *str2, char *resultado) {
    int i = 0, j = 0, k = 0;

    while (str1[i] != '\0' && str2[j] != '\0') {
        resultado[k++] = str1[i++];
        resultado[k++] = str2[j++];
    }

    while (str1[i] != '\0') resultado[k++] = str1[i++];
    while (str2[j] != '\0') resultado[k++] = str2[j++];

    resultado[k] = '\0';
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int n;
    char inp1[MAX_CHAR_INPUT_LENGTH], inp2[MAX_CHAR_INPUT_LENGTH], result[MAX_CHAR_LENGTH];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%s %s", inp1, inp2);

        string_process(inp1, inp2, result);

        insert(result, &s, &t);
    }

    printResults(s);
    return 0;
}
