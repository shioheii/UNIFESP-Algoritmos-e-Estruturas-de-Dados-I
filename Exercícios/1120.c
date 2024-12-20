/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 102;

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

void string_process(char D, char *N, char *resultado) {
    char res[MAX_CHAR_LENGTH];
    int result_index = 0;

    for (int i = 0; N[i] != '\0'; i++) {
        if (N[i] != D) {
            res[result_index++] = N[i];
        }
    }

    res[result_index] = '\0';

    if (result_index == 0) {
        strcpy(resultado, "0");
    } else {
        int i = 0;
        while (res[i] == '0') i++;

        if (res[i] == '\0') strcpy(resultado, "0");
        else                strcpy(resultado, res + i);
    }
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int n;
    char digit, number[MAX_CHAR_LENGTH], result[MAX_CHAR_LENGTH];

    while (scanf("%c %s", &digit, number)) {
        getchar();
        if (digit == '0' && strcmp(number, "0") == 0) break;
        
        string_process(digit, number, result);

        insert(result, &s, &t);
    }

    printResults(s);
    return 0;
}
