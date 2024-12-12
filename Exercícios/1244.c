/*********************************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Listas, Filas e Quicksort
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 3000;

typedef struct cell {
    int length;
    char *word;
    struct cell *next;
} cell;

void insert(char *v, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->word = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    newCell->length = strlen(v);
    strcpy(newCell->word, v);
    newCell->next = NULL;
    if (*et == NULL) *et = *es = newCell;
    else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

void saveResults(cell **es, cell **et, cell *lst) {
    cell *p = lst, *q;
    char *result = (char *)malloc(MAX_CHAR_LENGTH * sizeof(char));
    result[0] = '\0';

    while (p != NULL) {
        q = p->next;
        strcat(result, p->word);
        if (q != NULL) strcat(result, " ");
        free(p->word);
        free(p);
        p = q;
    }

    insert(result, es, et);
    free(result);
}


void printResults(cell *lst) {
    cell *p;
    for (p = lst; p != NULL; p = p->next) 
        printf("%s\n", p->word);
}

void sort(cell **first) {
    cell *sorted = NULL;
    cell *current = *first;

    while (current != NULL) {

        cell *next = current->next;
        if (sorted == NULL || current->length > sorted->length) {

            current->next = sorted;
            sorted = current;
        } else {
            
            cell *sortedCurrent = sorted;

            while (sortedCurrent->next != NULL && sortedCurrent->next->length >= current->length) {
                sortedCurrent = sortedCurrent->next;
            }

            current->next = sortedCurrent->next;
            sortedCurrent->next = current;
        }

        current = next;
    }

    *first = sorted;
}

int main() {
    cell *s, *t, *rs, *rt;
    s = t = rs = rt = NULL;

    int n;
    char str[MAX_CHAR_LENGTH], *aux;

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(str, MAX_CHAR_LENGTH, stdin);
        str[strcspn(str, "\n")] = 0;

        aux = strtok(str, " ");
        while(aux != NULL) {
            insert(aux, &s, &t);
            aux = strtok(NULL, " ");
        }

        sort(&s);
        saveResults(&rs, &rt, s);
        s = t = NULL;
    }

    printResults(rs);
}
