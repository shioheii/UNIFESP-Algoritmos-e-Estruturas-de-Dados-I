/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 2000;

typedef struct cell {
    int leds;
    struct cell *next;
} cell;

void insert(int v, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->leds = v;
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
        printf("%d leds\n", p->leds);
}

int countLeds(cell *first) {
    int leds[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    int totalLeds = 0;
    cell *p;

    for (p = first; p != NULL; p = p->next) {
        totalLeds += leds[p->leds];
    }
    
    return totalLeds;
}

int main() {
    cell *s, *t, *rs, *rt;
    s = t = rs = rt = NULL;

    int n, r;
    char input[MAX_CHAR_LENGTH];

    scanf("%d", &n);
    getchar();

    while (fgets(input, MAX_CHAR_LENGTH, stdin)) {
        for (int i = 0; input[i] != '\0'; i++) {
            r = input[i] - '0';
            insert(r, &s, &t);
        }

        int leds = countLeds(s);

        insert(leds, &rs, &rt);
        s = t = NULL;
    }

    printResults(rs);
    return 0;
}
