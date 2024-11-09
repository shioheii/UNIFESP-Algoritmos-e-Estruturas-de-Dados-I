#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int MAX_CHAR_LIST = 10000;
const int MAX_CHAR_ITEM = 1000;

typedef struct cell {
    char *item;
    struct cell *next;
} cell;

void sortListItems(cell *lst) {
    cell *p, *q;
    char aux[MAX_CHAR_ITEM];
    for (p = lst; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (strcmp(p->item, q->item) > 0) {
                strcpy(aux, p->item);
                strcpy(p->item, q->item);
                strcpy(q->item, aux);
            }
        }
    }
}

void searchAndRemove(cell *lst) {
    cell *p, *q, *prev;
    p = lst;
    while (p != NULL && p->next != NULL) {
        prev = p;
        q = p->next;
        while (q != NULL) {
            if (strcmp(p->item, q->item) == 0) {
                prev->next = q->next;
                free(q);
                q = prev->next;
            } else {
                prev = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

void printList(cell *lst) {
    cell *p;
    for (p = lst->next; p != NULL; p = p->next) {
        printf ("%s", p->item);
        if (p->next != NULL) printf(" ");
    }
}

void createList(char *item, cell *p) {
    cell *nova = (cell*)malloc(sizeof (cell));
    nova->item = (char*)malloc(MAX_CHAR_ITEM * sizeof(char)); 
    strcpy(nova->item, item);
    nova->next = p->next;
    p->next = nova;
}

cell* str_split(char *str) {
    char *item;
    item = strtok(str, " ");

    cell *head = (cell*)malloc(sizeof(cell));
    head->next = NULL;
    cell *ultimo = head;

    while(item != NULL) {
        createList(item, ultimo);
        item = strtok(NULL, " ");
        ultimo = ultimo->next;
    }

    searchAndRemove(head->next);
    sortListItems(head->next);

    return head;
}

int main() {
    int n = 0;
    char items[MAX_CHAR_LIST]; 

    scanf("%d", &n);
    getchar();

    cell *allLists[n];
    for (int i = 0; i < n; i++) {
        fgets(items, MAX_CHAR_LIST, stdin);
        items[strcspn(items, "\n")] = 0;

        allLists[i] = str_split(items);
    }

    for (int i = 0; i < n; i++) {
        printList(allLists[i]);
        printf("\n");
    }
}
