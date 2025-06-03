#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 20
#define MAX_SOLUCOES 100000

int chamadas_recursivas = 0;
int n; // N�mero de rainhas

typedef struct {
    int posicoes[MAX_N]; // �ndice = coluna, valor = linha
} Solucao;

Solucao solucoes[MAX_SOLUCOES];
int total_solucoes = 0;

/// Marca��es para linhas e diagonais
bool linha_ocupada[MAX_N];
bool diagonal_principal_ocupada[2 * MAX_N];
bool diagonal_secundaria_ocupada[2 * MAX_N];


int main()
{
    printf("Hello world!\n");
    return 0;
}
