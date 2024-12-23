/**************************************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas e ordenação com Bubblesort
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_NAME_LENGTH = 51;
const int MAX_CHOICE_LENGTH = 4;

typedef struct cell {
    char *name;
    char *choice;
    int order;    
    struct cell *next;
} cell;

int nameExists(char *name, cell *first) {
    cell *p;
    for (p = first; p != NULL; p = p->next) {
        if (strcmp(p->name, name) == 0) return 1;
    }
    return 0;
}

void insert(char *n, char *c, int i, cell **es, cell **et) {
    if (nameExists(n, *es)) return;

    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->name = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    newCell->choice = (char*)malloc(MAX_CHOICE_LENGTH * sizeof(char));
    strcpy(newCell->name, n);
    strcpy(newCell->choice, c);
    newCell->order = i;
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
    char tempName[MAX_NAME_LENGTH], tempChoice[MAX_CHOICE_LENGTH];
    int tempOrder;

    for (p = lst; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (strcmp(p->name, q->name) > 0) {
                strcpy(tempName, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, tempName);

                strcpy(tempChoice, p->choice);
                strcpy(p->choice, q->choice);
                strcpy(q->choice, tempChoice);

                tempOrder = p->order;
                p->order = q->order;
                q->order = tempOrder;
            }
        }
    }
}

void printList(cell *head, const char *choice) {
    while (head != NULL) {
        if (strcmp(head->choice, choice) == 0) {
            printf("%s\n", head->name);
        }
        head = head->next;
    }
}

void findWinner(cell *head) {
    cell *winner = NULL;

    while (head != NULL) {
        if (strcmp(head->choice, "YES") == 0) {
            if (winner == NULL || strlen(head->name) > strlen(winner->name) || 
                (strlen(head->name) == strlen(winner->name) && head->order < winner->order)) {
                winner = head;
            }
        }
        head = head->next;
    }

    if (winner != NULL) {
        printf("\nAmigo do Habay:\n%s\n", winner->name);
    }
}

int main() {
    cell *s, *t;
    s = t = NULL;
    char name[MAX_NAME_LENGTH], choice[MAX_CHOICE_LENGTH];
    int index = 0;

    while (scanf("%s", name)) {
        if (strcmp(name, "FIM") == 0) break;

        scanf("%s", choice);
        insert(name, choice, index++, &s, &t);
    }

    sort(s);

    printList(s, "YES");
    printList(s, "NO");

    findWinner(s);

    return 0;
}
