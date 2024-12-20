/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 51;

typedef struct cell {
    char *message;
    char *encrypted;
    struct cell *next;
} cell;

void insert(char *encrypted_message, char *message, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->encrypted = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    newCell->message = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(newCell->encrypted, encrypted_message);
    strcpy(newCell->message, message);
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
        printf("%s\n", p->message);
}

void string_process(char *m, int displacement) {
    int len = strlen(m);
    for (int j = 0; j < len; j++) {
        m[j] = ((m[j] - 'A' - displacement + 26) % 26) + 'A';
    }
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int n, d;
    char encrypted[MAX_CHAR_LENGTH], message[MAX_CHAR_LENGTH];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(encrypted, MAX_CHAR_LENGTH, stdin);
        encrypted[strcspn(encrypted, "\n")] = 0;

        scanf("%d", &d);
        getchar();

        strcpy(message, encrypted);
        string_process(message, d);

        insert(encrypted, message, &s, &t);
    }

    printResults(s);
    return 0;
}
