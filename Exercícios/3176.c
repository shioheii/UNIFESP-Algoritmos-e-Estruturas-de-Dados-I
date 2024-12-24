#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 21;

typedef struct cell {
    char *name;
    int age;
    struct cell *next;
} cell;

void insert(char *n, int a, cell **es, cell **et) {
    cell *newCell = (cell *)malloc(sizeof(cell));
    newCell->name = (char *)malloc(MAX_LENGTH * sizeof(char));
    strcpy(newCell->name, n);
    newCell->age = a;
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
    char tempName[MAX_LENGTH];
    int tempAge;

    for (p = lst; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if ((p->age < q->age) || 
                (p->age == q->age && strcmp(p->name, q->name) > 0)) {
                strcpy(tempName, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, tempName);

                tempAge = p->age;
                p->age = q->age;
                q->age = tempAge;
            }
        }
    }
}


void printTeams(cell *first, int N) {
    int numberOfTeams = N / 3;
    cell *leaders = first;
    cell *deliverers = first;
    cell *pilots = first;

    for (int i = 0; i < numberOfTeams; i++) deliverers = deliverers->next;
    for (int i = 0; i < 2 * numberOfTeams; i++) pilots = pilots->next;

    for (int i = 1; i <= numberOfTeams; i++) {
        printf("Time %d\n", i);
        printf("%s %d\n", leaders->name, leaders->age);
        leaders = leaders->next;

        printf("%s %d\n", deliverers->name, deliverers->age);
        deliverers = deliverers->next;

        printf("%s %d\n", pilots->name, pilots->age);
        pilots = pilots->next;

        printf("\n");
    }
}

int main() {
    cell *s, *t;
    s = t = NULL;

    int N, age;
    char name[MAX_LENGTH];

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%s %d", name, &age);
            insert(name, age, &s, &t);
        }

        sort(s);
        printTeams(s, N);
        s = t = NULL;
    }

    return 0;
}
