/*************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
**************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 300;

typedef struct cell {
    int value;
    struct cell *next;
} cell;

void insert(int v, cell **es, cell **et) {
    cell *newCell;
    newCell = (cell*)malloc(sizeof(cell));
    newCell->value = v;
    newCell->next = NULL;
    if (*et == NULL) *et = *es = newCell;
    else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

void printList(cell *first) {
    cell *p;
    for (p = first; p != NULL; p = p->next)
        printf("%d\n", p->value);
}

int count(long f, cell *first) {
    cell *p = first;
    long accumulatedFollowers = 0;
    int days = 0; 

    while (accumulatedFollowers < f && p != NULL) {
        accumulatedFollowers += p->value;
        p = p->next;
        days++;
    }

    return days;
}

int main() {
    cell *s, *t, *ri, *rf;
    s = t = ri = rf = NULL;

    int daysNeeded; 
    long n, m, followersNeeded, integerFollowers;
    char *input = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    char *followers;

    while (scanf("%ld %ld", &n, &m) != EOF) {
        getchar();

        fgets(input, MAX_CHAR_LENGTH, stdin);

        followers = strtok(input, " ");
        while(followers != NULL) {
            integerFollowers = strtol(followers, NULL, 10);
            insert(integerFollowers, &s, &t);
            followers = strtok(NULL, " ");
        }

        followersNeeded = m - n;
        daysNeeded = count(followersNeeded, s);
        insert(daysNeeded, &ri, &rf);
    
        s = t = NULL; 
    }

    printList(ri);

    free(input);
    return 0;
}
