/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_CHAR_LENGTH = 20;

typedef struct cell {
    char *key;
    int value;
    struct cell *next;
} cell;

void insert(char *key, int value, cell **es, cell **et) {
    cell *newCell = (cell *)malloc(sizeof(cell));
    newCell->key = (char *)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(newCell->key, key);
    newCell->value = value;
    newCell->next = NULL;
    if (*et == NULL) {
        *es = *et = newCell;
    } else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

int search(char *key, cell *first) {
    while (first != NULL) {
        if (strcmp(first->key, key) == 0) {
            return first->value;
        }
        first = first->next;
    }
    return 0;
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int M, N;
    char key[MAX_CHAR_LENGTH], word[MAX_CHAR_LENGTH];
    int value, salary;

    while (scanf("%d %d", &M, &N) != EOF) {
        for (int i = 0; i < M; i++) {
            scanf("%s %d", key, &value);
            insert(key, value, &s, &t);
        }

        for (int i = 0; i < N; i++) {
            salary = 0.0;

            while (1) {
                scanf("%s", word);
                if (strcmp(word, ".") == 0) break; 
                salary += search(word, s);
            }

            printf("%d\n", salary);
        }
    }

    return 0;
}