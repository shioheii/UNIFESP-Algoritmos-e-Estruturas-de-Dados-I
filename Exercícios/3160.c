#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int LIMITE_CARACTERES = 1000;
const int MAX_CHAR_NAME = 100;

typedef struct cell {
    char *nome;
    struct cell *seguinte;
} cell;

void printList(cell *lst) {
    cell *p;
    for (p = lst->seguinte; p != NULL; p = p->seguinte) {
        printf ("%s", p->nome);
        if (p->seguinte != NULL) printf(" ");
    }
}

cell* joinLists(cell *first_lst, cell *second_lst) {
    cell *lastItemOfFirstList;

    lastItemOfFirstList = first_lst->seguinte;
    while (lastItemOfFirstList != NULL && lastItemOfFirstList->seguinte != NULL) {
        lastItemOfFirstList = lastItemOfFirstList->seguinte;
    }

    lastItemOfFirstList->seguinte = second_lst->seguinte; 
    free(second_lst);

    return first_lst;
}

cell* searchAndInsertList(char *nome_busca, cell *lst, cell *new_lst) {
    cell *p, *q, *firstItem, *lastItem;

    p = lst;
    q = lst->seguinte;
    while (q != NULL && strcmp(q->nome, nome_busca) != 0) {
        p = q;
        q = q->seguinte;
    }

    firstItem = new_lst->seguinte; 
    lastItem = firstItem;

    while (lastItem != NULL && lastItem->seguinte != NULL) {
        lastItem = lastItem->seguinte;
    }

    lastItem->seguinte = q;
    p->seguinte = firstItem;

    return lst;
}

void createList(char *nome, cell *p) {
    cell *nova = (cell*)malloc(sizeof (cell));
    nova->nome = (char*)malloc(MAX_CHAR_NAME * sizeof(char)); 
    strcpy(nova->nome, nome);
    nova->seguinte = p->seguinte;
    p->seguinte = nova;
}

cell* str_split(char *str) {
    char *item;
    item = strtok(str, " ");

    cell *cabeca = (cell*)malloc(sizeof(cell));
    cabeca->seguinte = NULL;
    cell *ultimo = cabeca;

    while( item != NULL ) {
        createList(item, ultimo);
        item = strtok(NULL, " ");
        ultimo = ultimo->seguinte;
    }

    return cabeca;
}

int main() {
    char luiggyFriends[LIMITE_CARACTERES]; 
    char newFriends[LIMITE_CARACTERES];
    char recommendedFriend[MAX_CHAR_NAME];

    fgets(luiggyFriends, LIMITE_CARACTERES, stdin);
    fgets(newFriends, LIMITE_CARACTERES, stdin);
    fgets(recommendedFriend, MAX_CHAR_NAME, stdin);

    luiggyFriends[strcspn(luiggyFriends, "\n")] = 0;
    newFriends[strcspn(newFriends, "\n")] = 0;
    recommendedFriend[strcspn(recommendedFriend, "\n")] = 0;

    cell *luiggyFriendsList = str_split(luiggyFriends);
    cell *newFriendsList = str_split(newFriends);

    cell *totalFriendsList;
    if (strcmp(recommendedFriend, "nao") != 0) {
        totalFriendsList = searchAndInsertList(recommendedFriend, luiggyFriendsList, newFriendsList);
    } else {
        totalFriendsList = joinLists(luiggyFriendsList, newFriendsList);
    }

    printList(totalFriendsList);
    printf("\n");
}