#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 100000; //constante para tamanho do vetor
int const BUSCA = 1194948194; //constante para buscar no vetor

int BuscaBinária (int x, int n, int v[]) {
    int e, m, d;
    e = -1; d = n;
    while (/*X*/ e < d - 1) {
        m = (e + d)/2;
        if (v[m] < x) e = m;
        else d = m;
    }
    return d;
}

int BuscaSeqüencial (int x, int n, int v[]) {
    int j = 0;
    while (j < n && v[j] < x) ++j;
    return j;
}

void bubbleSort (int v[TAM]) {
    int a, b, aux;
    for (a=TAM-1; a>=1; a--) {
        for (b=0; b<a; b++) {
            if (v[b]>v[b+1]) {
                aux = v[b];
                v[b] = v[b+1];
                v[b+1] = aux;
            }
        }
    }
}

int main(){
    clock_t t, t2, t3; //variável para armazenar tempo
    int vetor[TAM];
    
    //semente de aleatoriedade
    srand((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); //armazena tempo
    bubbleSort(vetor);
    t = clock() - t; //tempo final - tempo 

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    //Verificando tempo de execução da busca sequencial
    t2 = clock(); //armazena tempo
    BuscaSeqüencial(BUSCA, TAM, vetor);
    t2 = clock() - t2; //tempo final - tempo 

    //imprime o tempo na tela
    printf("Tempo de execucao BuscaSeqüencial: %lf ms\n", ((double)t2)/((CLOCKS_PER_SEC/1000))); //conversão para double

    //Verificando tempo de execução da busca binaria
    t3 = clock(); //armazena tempo
    BuscaBinária(BUSCA, TAM, vetor);
    t3 = clock() - t3; //tempo final - tempo 

    //imprime o tempo na tela
    printf("Tempo de execucao BuscaBinária: %lf ms\n", ((double)t3)/((CLOCKS_PER_SEC/1000))); //conversão para double

    return 0;
}
