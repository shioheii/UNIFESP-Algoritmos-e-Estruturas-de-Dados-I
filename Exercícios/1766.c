/***************************************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas e ordenação com Bubblesort
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_NAME_LENGTH = 101;

typedef struct cell {
    char *name;
    int weight;
    int age;
    double height;
    struct cell *next;
} cell;

void insert(char *name, int weight, int age, double height, cell **es, cell **et) {
    cell *newCell = (cell *)malloc(sizeof(cell));
    newCell->name = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
    strcpy(newCell->name, name);
    newCell->weight = weight;
    newCell->age = age;
    newCell->height = height;
    newCell->next = NULL;

    if (*et == NULL) {
        *es = *et = newCell;
    } else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

void sort(cell *lst) {
    cell *p, *q;
    char tempName[MAX_NAME_LENGTH];
    int tempWeight, tempAge;
    double tempHeight;

    for (p = lst; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (
                (p->weight < q->weight) || 
                (p->weight == q->weight && p->age > q->age) ||
                (p->weight == q->weight && p->age == q->age && p->height > q->height) ||
                (p->weight == q->weight && p->age == q->age && p->height == q->height && strcmp(p->name, q->name) > 0)
            ) {
                strcpy(tempName, p->name);
                tempWeight = p->weight;
                tempAge = p->age;
                tempHeight = p->height;

                strcpy(p->name, q->name);
                p->weight = q->weight;
                p->age = q->age;
                p->height = q->height;

                strcpy(q->name, tempName);
                q->weight = tempWeight;
                q->age = tempAge;
                q->height = tempHeight;
            }
        }
    }
}

void printTopRenas(cell *first, int M, int scenario) {
    cell *p = first;
    printf("CENARIO {%d}\n", scenario);
    for (int i = 1; i <= M && p != NULL; i++) {
        printf("%d - %s\n", i, p->name);
        p = p->next;
    }
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int T, weight, age, N, M;
    char name[MAX_NAME_LENGTH];
    double height;
    
    scanf("%d", &T);
    for (int scenario = 1; scenario <= T; scenario++) {
        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; i++) {
            scanf("%s %d %d %lf", name, &weight, &age, &height);
            insert(name, weight, age, height, &s, &t);
        }

        sort(s);

        printTopRenas(s, M, scenario);
        s = t = NULL;
    }

    return 0;
}
