/***************************************************************
 * UNIFESP - Universidade Federal de São Paulo
 * Nome: Bruno Shiohei Kinoshita do Nascimento
 * RA: 176475
 * Observação: Resolvido utilizando estrutura de dados Listas
***************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 60;
const int RESULT_SIZE = 10000;

typedef struct cell {
    double value;
    char *item;
    struct cell *next;
} cell;

void insert(double v, char *item, cell *p) {
    cell *newCell = (cell*)malloc(sizeof(cell));
    newCell->item = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strncpy(newCell->item, item, MAX_CHAR_LENGTH - 1);
    newCell->value = v;
    newCell->next = p->next;
    p->next = newCell;
}

double buscaValorProduto(int qtd, char *produto, cell *lst) {
    cell *p;
    double t;
    for (p = lst->next; p != NULL; p = p->next) {
        if (strcmp(p->item, produto) == 0) {
            t = p->value * qtd;
            break;
        }
    }
    return t;
}

int main() {
    cell *head = (cell*)malloc(sizeof(cell));
    head->next = NULL;

    int n, m, p, quantidade;
    char str[MAX_CHAR_LENGTH], temp[MAX_CHAR_LENGTH], *produto;
    char *result = (char*)malloc(RESULT_SIZE * sizeof(char));
    result[0] = '\0';

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        double value, total = 0;

        scanf("%d", &m);
        getchar();

        for (int j = 0; j < m; j++) {
            fgets(str, MAX_CHAR_LENGTH, stdin);
            str[strcspn(str, "\n")] = 0;

            produto = strtok(str, " ");
            value = strtod(strtok(NULL, " "), NULL);
            insert(value, produto, head);
        }

        scanf("%d", &p);
        getchar();

        for (int j = 0; j < p; j++) {
            fgets(str, MAX_CHAR_LENGTH, stdin);
            str[strcspn(str, "\n")] = 0;

            produto = strtok(str, " ");
            quantidade = strtol(strtok(NULL, " "), NULL, 10);
            total += buscaValorProduto(quantidade, produto, head);
        }

        sprintf(temp, "R$ %.2lf\n", total);
        strcat(result, temp);
        head->next = NULL;
    }

    printf("%s", result);
    free(result);
    free(head);
    return 0;
}
