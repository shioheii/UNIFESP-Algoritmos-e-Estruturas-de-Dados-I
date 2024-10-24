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
    int instances = 0;
    int sudoku[9][9];
    
    scanf("%d", &instances);

    int results[instances];
    
    for (int i = 0; i < instances; i++) {
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                scanf("%d", &sudoku[x][y]);
            }
        }

        results[i] = verificaSudoku(sudoku);
    }

    for (int i = 0; i < instances; i++) {
        printf("Instancia %d\n", i+1);
        printf("%s\n\n", results[i] ? "SIM" : "NAO");
    }

    return 0;
}