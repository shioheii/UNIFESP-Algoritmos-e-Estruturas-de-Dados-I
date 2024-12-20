/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 10;

typedef struct cell {
    char *text;
    int number;
    struct cell *next;
} cell;

void insert(char *text, int v, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->number = v;
    newCell->text = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(newCell->text, text);
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
        if (p->number != 0) printf("%d\n", p->number);
        else printf("\n");
}

void identifiesNumbers(cell *lst) {
    cell *p;
    char *text = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    for (p = lst; p != NULL; p = p->next) {
        strcpy(text, p->text);
        
        if (strlen(text) > 3) {
            p->number = 3;
        } else if ((text[0] == 'o' && text[1] == 'n') || (text[0] == 'o' && text[2] == 'e') || (text[1] == 'n' && text[2] == 'e')) {
            p->number = 1;
        } else if ((text[0] == 't' && text[1] == 'w') || (text[0] == 't' && text[2] == 'o') || (text[1] == 'w' && text[2] == 'o')) {
            p->number = 2;
        }
    }
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int n;
    char text[MAX_CHAR_LENGTH];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(text, MAX_CHAR_LENGTH, stdin);
        text[strcspn(text, "\n")] = 0;
        insert(text, 0, &s, &t);
    }

    identifiesNumbers(s);
    printResults(s);
    return 0;
}
