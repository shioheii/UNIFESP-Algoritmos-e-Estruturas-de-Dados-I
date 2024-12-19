/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 1001;

typedef struct cell {
    char *plain_text;
    char *encrypted;
    struct cell *next;
} cell;

void insert(char *text, char *encrypt, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->plain_text = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    newCell->encrypted = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(newCell->plain_text, text);
    strcpy(newCell->encrypted, encrypt);
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
        printf("%s\n", p->encrypted);
}

// START STRING PROCESS METHODS
void step_one(char *text) {
    int i = 0;
    while (text[i] != '\0') {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            text[i] = text[i] + 3;
        }
        i++;
    }
}

void step_two(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len / 2; i++) {
        char temp = text[i];
        text[i] = text[len - i - 1];
        text[len - i - 1] = temp;
    }
}

void step_three(char *text) {
    int len = strlen(text);
    for (int i = len / 2; i < len; i++) {
        text[i] = text[i] - 1;
    }
}

void string_process(char *text) {
    step_one(text);
    step_two(text);
    step_three(text);
}
// END STRING PROCESS METHODS

int main() {
    cell *s, *t;
    s = t = NULL;

    int n;
    char input[MAX_CHAR_LENGTH], plain_text[MAX_CHAR_LENGTH];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(input, MAX_CHAR_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;

        strcpy(plain_text, input);
        string_process(input);

        insert(plain_text, input, &s, &t);
    }

    printResults(s);
    return 0;
}
