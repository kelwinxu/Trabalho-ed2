#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define MAX_N 20

int n = 0;

// Protótipo da função que resolve o problema (backtracking)
void resolver(int linha, int *tabuleiro);

int main(int argc, char *arg v[]) {
    int tabuleiro[MAX_N]; // Array para guardar as posições das rainhas no tabuleiro


    if (argc == 1) {
        // Nenhum argumento -> rodar casos de teste automáticos
        int testes[] = {4, 8};
        for (int i = 0; i < 2; i++) {
            n = testes[i];
            total_solucoes = 0;
            chamadas_recursivas = 0;
            printf("\nTestando para N = %d:\n", n);
            resolver(0, tabuleiro);
            if (total_solucoes == 0)
                printf("Nao ha solucao para %d rainhas.\n", n);
            else
                printf("Total de solucoes unicas: %d\n", total_solucoes);
            printf("Chamadas recursivas: %d\n", chamadas_recursivas);
        }
    }
    else if (argc == 2) {
            // Caso tenha exatamente 1 argumento, interpretá-lo como o valor de N
        n = atoi(argv[1]);
        if (n < 1 || n > MAX_N) {  // Verifica se N está dentro dos limites permitidos (limitados no começo do codigo)
            printf("Valor de N invalido.\n"); // Sai do programa com erro
            return 1;
        }
        total_solucoes = 0;
        chamadas_recursivas = 0;
        resolver(0, tabuleiro);
        if (total_solucoes == 0)
            printf("Nao ha solucao para %d rainhas.\n", n);
        else
            printf("Total de solucoes unicas: %d\n", total_solucoes);
        printf("Chamadas recursivas: %d\n", chamadas_recursivas);
    }
    else {
        // Caso o número de argumentos seja diferente de 0 ou 1, mostrar mensagem de uso incorreto
        printf("Uso incorreto: execute sem argumentos para casos de teste ou com 1 argumento (valor de N).\n");
        return 1;
    }

    return 0;
}
