/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

const int MAX_CHAR_LENGTH = 51;

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

void make_dancing_sentence(char *sentence, char *res) {
    int capitalize = 1;
    strcpy(res, sentence);

    for (int i = 0; res[i] != '\0'; i++) {
        if (res[i] != ' ') {
            if (capitalize) {
                res[i] = toupper(res[i]);
            } else {
                res[i] = tolower(res[i]);
            }
            capitalize = !capitalize;
        }
    }
}

int main() {
    cell *s, *t;
    s = t = NULL;

    char text[MAX_CHAR_LENGTH], result[MAX_CHAR_LENGTH];

    while (fgets(text, MAX_CHAR_LENGTH, stdin)) {
        text[strcspn(text, "\n")] = '\0';

        make_dancing_sentence(text, result);

        insert(result, &s, &t);
    }

    printResults(s);
    return 0;
}
