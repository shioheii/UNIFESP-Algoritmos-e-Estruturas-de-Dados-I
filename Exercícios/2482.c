/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 100;

typedef struct cell {
    char *language;
    char *message;
    struct cell *next;
} cell;

void insert(char *l, char *m, cell **es, cell **et) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->language = (char*)malloc(MAX_LENGTH * sizeof(char));
    newCell->message = (char*)malloc(MAX_LENGTH * sizeof(char));
    strcpy(newCell->language, l);
    strcpy(newCell->message, m);
    newCell->next = NULL;
    if (*et == NULL) {
        *es = *et = newCell;
    } else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

char* searchMessageByLanguage(char *l, cell *first) {
    cell *p;
    for (p = first; p != NULL; p = p->next) {
        if (strcmp(p->language, l) == 0)
            return p->message; 
    }
    return "Merry Christmas";
}

int main() {
    cell *s, *t;
    s = t = NULL;
    
    int N, M;
    char language[MAX_LENGTH], message[MAX_LENGTH], name[MAX_LENGTH];

    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        fgets(language, MAX_LENGTH, stdin);
        fgets(message, MAX_LENGTH, stdin);
        language[strcspn(language, "\n")] = '\0';
        message[strcspn(message, "\n")] = '\0';

        insert(language, message, &s, &t);
    }

    scanf("%d", &M);
    getchar();
    for (int i = 0; i < M; i++) {
        fgets(name, MAX_LENGTH, stdin);
        fgets(language, MAX_LENGTH, stdin);
        name[strcspn(name, "\n")] = '\0';
        language[strcspn(language, "\n")] = '\0';
        
        printf("%s\n", name);
        printf("%s\n", searchMessageByLanguage(language, s));
        printf("\n");
    }

    return 0;
}
