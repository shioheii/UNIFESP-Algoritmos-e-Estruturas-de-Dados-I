#include <stdio.h>

int verificaSudoku(int vet[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int elemento = 0; elemento < 9; elemento++){
            for (int j = elemento + 1; j < 9; j++) {
                if (vet[i][elemento] == vet[i][j]) return 0; // Linha
                if (vet[elemento][i] == vet[j][i]) return 0; // Coluna
            }   

            int linha = i;
            int j = elemento + 1;
            while (1) {
                if (j % 3 == 0 && j != 0 && linha % 3 == 0 && linha != i) break;
                if (j % 3 == 0 && j != 0) {
                    j -= 3;
                    linha++;
                }
                if (linha % 3 == 0 && linha != 0) break;
                if (vet[i][elemento] == vet[linha][j]) return 0;

                j++;
            }
        }
    }
        
    return 1;
}

int main() {
    int x, y, k;        // Coordenadas e valor
    int JOGADAS = 11;   // Quantidade de * 
    int sudoku[9][9] = {
        {1, 3, 2, 5, 7, 9, 4, 6, 8},
        {4, 9, 0, 2, 0, 1, 3, 0, 5},
        {0, 5, 6, 3, 8, 4, 0, 1, 9},
        {6, 4, 3, 0, 5, 8, 7, 9, 2},
        {5, 2, 1, 7, 9, 3, 8, 4, 0},
        {9, 0, 7, 4, 2, 6, 5, 3, 1},
        {2, 1, 4, 9, 3, 5, 6, 8, 7},
        {3, 0, 5, 8, 1, 7, 0, 2, 4},
        {8, 7, 9, 6, 4, 0, 1, 5, 3}
    };
    
    printf("\n*** BEM VINDO AO SUDOKU ***\n");
    for (int rodada = 0; rodada < JOGADAS; rodada++) {
        printf("\n-------------------------\n");
        for (int i = 0; i < 9; i++) {
            printf("| ");
            for (int j = 0; j < 9; j++) {
                printf(sudoku[i][j] == 0 ? "* " : "%d ", sudoku[i][j]);
                if ((j+1) % 3 == 0 && j+1 < 9) printf("| ");
            }
            printf("|\n");
            if ((i+1) % 3 == 0) printf("-------------------------\n");
        }
        printf("\n========== Jogada %d ==========\n\n", rodada+1);

        do {
            printf("Digite uma linha válida [1-9]: ");
            scanf("%d", &x);
            printf("Digite uma coluna válida [1-9]: ");
            scanf("%d", &y);
            printf("Digite um valor válido [1-9]: ");
            scanf("%d", &k);
        } while (sudoku[x-1][y-1] != 0 || k > 9 || k < 1);

        sudoku[--x][--y] = k;
    }
    
    printf("\n\n");
    printf(verificaSudoku(sudoku) ? "*** PARABENS, VOCE GANHOU ***" : "*** QUE PENA, VOCE PERDEU ***");

    return 0;
}
