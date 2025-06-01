#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 20
#define MAX_SOLUCOES 100000

int chamadas_recursivas = 0;
int n; // Número de rainhas

typedef struct {
    int posicoes[MAX_N]; // índice = coluna, valor = linha
} Solucao;

Solucao solucoes[MAX_SOLUCOES];
int total_solucoes = 0;

/// Marcações para linhas e diagonais
bool linha_ocupada[MAX_N];
bool diagonal_principal_ocupada[2 * MAX_N];
bool diagonal_secundaria_ocupada[2 * MAX_N];

bool sao_iguais(int *a, int *b) {
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) return false;
    return true;
}

///Gambiarra rotação
void gerar_transformacoes(int *original, int transformacoes[8][MAX_N]) {
    for (int i = 0; i < n; i++)
        transformacoes[0][i] = original[i]; // Identidade

    // Rotação 90°
    for (int i = 0; i < n; i++)
        transformacoes[1][original[i]] = n - 1 - i;

    // Rotação 180°
    for (int i = 0; i < n; i++)
        transformacoes[2][n - 1 - i] = n - 1 - original[i];

    // Rotação 270°
    for (int i = 0; i < n; i++)
        transformacoes[3][n - 1 - original[i]] = i;

    // Reflexão horizontal
    for (int i = 0; i < n; i++)
        transformacoes[4][i] = n - 1 - original[i];

    // Reflexão vertical
    for (int i = 0; i < n; i++)
        transformacoes[5][n - 1 - i] = original[i];

    // Diagonal principal
    for (int i = 0; i < n; i++)
        transformacoes[6][original[i]] = i;

    // Diagonal secundária
    for (int i = 0; i < n; i++)
        transformacoes[7][n - 1 - original[i]] = n - 1 - i;
}

/// Verifica se a solução (com simetrias) já foi encontrada
bool solucao_e_unica(int *nova) {
    int transformacoes[8][MAX_N] = {0};
    gerar_transformacoes(nova, transformacoes);

    for (int i = 0; i < total_solucoes; i++) {
        for (int t = 0; t < 8; t++) {
            if (sao_iguais(solucoes[i].posicoes, transformacoes[t]))
                return false;
        }
    }
    return true;
}

/// Exibe vetor da solução
void exibir_solucao(int *tabuleiro) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", tabuleiro[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Função recursiva de backtracking
void resolver_n_rainhas(int coluna, int *tabuleiro) {
    chamadas_recursivas++;

    if (coluna == n) {
        if (solucao_eh_unica(tabuleiro)) {
            memcpy(solucoes[total_solucoes].posicoes, tabuleiro, sizeof(int) * n);
            total_solucoes++;
            exibir_solucao(tabuleiro);
        }
        return;
    }

    for (int linha = 0; linha < n; linha++) {
        if (linha_ocupada[linha] ||
            diagonal_principal_ocupada[coluna - linha + n] ||
            diagonal_secundaria_ocupada[coluna + linha]) continue;

        tabuleiro[coluna] = linha;
        linha_ocupada[linha] = true;
        diagonal_principal_ocupada[coluna - linha + n] = true;
        diagonal_secundaria_ocupada[coluna + linha] = true;

        resolver_n_rainhas(coluna + 1, tabuleiro);

        linha_ocupada[linha] = false;
        diagonal_principal_ocupada[coluna - linha + n] = false;
        diagonal_secundaria_ocupada[coluna + linha] = false;
    }
}

void iniciar_resolucao(int tamanho) {
    n = tamanho;
    if (n > MAX_N) {
        printf("Valor de N muito grande (máximo: %d)\n", MAX_N);
        return;
    }

    int tabuleiro[MAX_N];
    chamadas_recursivas = 0;
    total_solucoes = 0;
    memset(linha_ocupada, 0, sizeof(linha_ocupada));
    memset(diagonal_principal_ocupada, 0, sizeof(diagonal_principal_ocupada));
    memset(diagonal_secundaria_ocupada, 0, sizeof(diagonal_secundaria_ocupada));

    resolver_n_rainhas(0, tabuleiro);

    if (total_solucoes == 0)
        printf("Não há solução para %d rainhas.\n", n);
    else {
        printf("Chamadas recursivas: %d\n", chamadas_recursivas);
        printf("Soluções distintas: %d\n", total_solucoes);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int valor = atoi(argv[1]);
        printf("Resolvendo para %d rainhas...\n", valor);
        iniciar_resolucao(valor);
    } else {
        printf("Executando testes automáticos:\n\n");

        int testes[] = {4, 8};
        for (int i = 0; i < 2; i++) {
            printf("==== %d rainhas ====\n", testes[i]);
            iniciar_resolucao(testes[i]);
            printf("\n");
        }
    }

    return 0;
}
