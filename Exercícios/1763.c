/***********************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Filas
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 50;

typedef struct cell {
    char *country;
    char *message;
    struct cell *next;
} cell;

void insert(char *country, char *message, cell **es, cell **et) {
    cell *newCell = (cell *)malloc(sizeof(cell));
    newCell->country = (char *)malloc(MAX_CHAR_LENGTH * sizeof(char));
    newCell->message = (char *)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(newCell->country, country);
    strcpy(newCell->message, message);
    newCell->next = NULL;
    if (*et == NULL) {
        *es = *et = newCell;
    } else {
        (*et)->next = newCell;
        *et = newCell;
    }
}

char *searchInList(char *country, cell *head) {
    cell *current = head;
    while (current != NULL) {
        if (strcmp(current->country, country) == 0) {
            return current->message;
        }
        current = current->next;
    }
    return "--- NOT FOUND ---";
}

int main() {
    cell *s, *t;
    s = t = NULL;

    insert("brasil", "Feliz Natal!", &s, &t);
    insert("alemanha", "Frohliche Weihnachten!", &s, &t);
    insert("austria", "Frohe Weihnacht!", &s, &t);
    insert("coreia", "Chuk Sung Tan!", &s, &t);
    insert("espanha", "Feliz Navidad!", &s, &t);
    insert("grecia", "Kala Christougena!", &s, &t);
    insert("estados-unidos", "Merry Christmas!", &s, &t);
    insert("inglaterra", "Merry Christmas!", &s, &t);
    insert("australia", "Merry Christmas!", &s, &t);
    insert("portugal", "Feliz Natal!", &s, &t);
    insert("suecia", "God Jul!", &s, &t);
    insert("turquia", "Mutlu Noeller", &s, &t);
    insert("argentina", "Feliz Navidad!", &s, &t);
    insert("chile", "Feliz Navidad!", &s, &t);
    insert("mexico", "Feliz Navidad!", &s, &t);
    insert("antardida", "Merry Christmas!", &s, &t);
    insert("canada", "Merry Christmas!", &s, &t);
    insert("irlanda", "Nollaig Shona Dhuit!", &s, &t);
    insert("belgica", "Zalig Kerstfeest!", &s, &t);
    insert("italia", "Buon Natale!", &s, &t);
    insert("libia", "Buon Natale!", &s, &t);
    insert("siria", "Milad Mubarak!", &s, &t);
    insert("marrocos", "Milad Mubarak!", &s, &t);
    insert("japao", "Merii Kurisumasu!", &s, &t);

    char country[MAX_CHAR_LENGTH];

    while (scanf("%s", country) != EOF) {
        printf("%s\n", searchInList(country, s));
    }

    return 0;
}
