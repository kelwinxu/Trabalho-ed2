#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 20 /// Máximo tamanho do tabuleiro suportado (além de 13-15 pode ocorrer overflow ou lentidão)

#define MAX_SOLUCOES 10000000
#include "funcoes.h"

///Area de Variaveis
int flag;
extern int n;
int chamadas_recursivas = 0; ///Para contar as chamadas
Solucao solucoes[MAX_SOLUCOES];
int total_solucoes = 0;
/// Compara recursivamente dois vetores. Se forem diferentes em algum ponto, zera a flag.
void sao_iguais_rec(int *a, int *b, int i, int *flag) {
    if (*flag == 0 || i == n) return;
    if (a[i] != b[i]) {
        *flag = 0;
        return;
    }
    sao_iguais_rec(a, b, i + 1, flag);
}
///Faz matriz indentidade recursivamente
void copiar_identidade_rec(int *original, int *destino, int i) {
    if (i == n) return;
    destino[i] = original[i];
    copiar_identidade_rec(original, destino, i + 1);
}

///Importante para entender as operações com vetores
/*
i é a coluna atual, então a da rainha é (i,original[i])
geometricamente seria mais ou menos assim (x,y) -> (y,n-1-x)
então estou invertendo por exemplo coluna <-> linha
270 graus: nada mais é do que 90 anti-horário
se pensar geometricamente faz mais sentido
*/
///------------FIM explicação----------------------------
///Por divisão e conquista
// Rotação 90 graus
void rotacao_90_divide_conquista(int *original, int *destino, int inicio, int fim) {
    if (inicio > fim) return;
    if (inicio == fim) {
        destino[original[inicio]] = n - 1 - inicio;
        return;
    }
    int meio = (inicio + fim) / 2;
    rotacao_90_divide_conquista(original, destino, inicio, meio);
    rotacao_90_divide_conquista(original, destino, meio + 1, fim);
}

// Rotação 180 graus
void rotacao_180_divide_conquista(int *original, int *destino, int inicio, int fim) {
    if (inicio > fim) return;
    if (inicio == fim) {
        destino[n - 1 - inicio] = n - 1 - original[inicio];
        return;
    }
    int meio = (inicio + fim) / 2;
    rotacao_180_divide_conquista(original, destino, inicio, meio);
    rotacao_180_divide_conquista(original, destino, meio + 1, fim);
}

// Rotação 270 graus
void rotacao_270_divide_conquista(int *original, int *destino, int inicio, int fim) {
    if (inicio > fim) return;
    if (inicio == fim) {
        destino[n - 1 - original[inicio]] = inicio;
        return;
    }
    int meio = (inicio + fim) / 2;
    rotacao_270_divide_conquista(original, destino, inicio, meio);
    rotacao_270_divide_conquista(original, destino, meio + 1, fim);
}

// Reflexo horizontal
void reflexo_horizontal_divide_conquista(int *original, int *destino, int inicio, int fim) {
    if (inicio > fim) return;
    if (inicio == fim) {
        destino[inicio] = n - 1 - original[inicio];
        return;
    }
    int meio = (inicio + fim) / 2;
    reflexo_horizontal_divide_conquista(original, destino, inicio, meio);
    reflexo_horizontal_divide_conquista(original, destino, meio + 1, fim);
}

// Reflexo vertical
void reflexo_vertical_divide_conquista(int *original, int *destino, int inicio, int fim) {
    if (inicio > fim) return;
    if (inicio == fim) {
        destino[n - 1 - inicio] = original[inicio];
        return;
    }
    int meio = (inicio + fim) / 2;
    reflexo_vertical_divide_conquista(original, destino, inicio, meio);
    reflexo_vertical_divide_conquista(original, destino, meio + 1, fim);
}

// Diagonal principal
void diagonal_principal_divide_conquista(int *original, int *destino, int inicio, int fim) {
    if (inicio > fim) return;
    if (inicio == fim) {
        destino[original[inicio]] = inicio;
        return;
    }
    int meio = (inicio + fim) / 2;
    diagonal_principal_divide_conquista(original, destino, inicio, meio);
    diagonal_principal_divide_conquista(original, destino, meio + 1, fim);
}

// Diagonal secundária
void diagonal_secundaria_divide_conquista(int *original, int *destino, int inicio, int fim) {
    if (inicio > fim) return;
    if (inicio == fim) {
        destino[n - 1 - original[inicio]] = n - 1 - inicio;
        return;
    }
    int meio = (inicio + fim) / 2;
    diagonal_secundaria_divide_conquista(original, destino, inicio, meio);
    diagonal_secundaria_divide_conquista(original, destino, meio + 1, fim);
}

///Gera todas as 8 transformações geométricas possíveis da solução
void gerar_transformacoes(int *original, int transformacoes[8][MAX_N]) {
    copiar_identidade_rec(original, transformacoes[0], 0);
    rotacao_90_divide_conquista(original, transformacoes[1], 0, n - 1);
    rotacao_180_divide_conquista(original, transformacoes[2], 0, n - 1);
    rotacao_270_divide_conquista(original, transformacoes[3], 0, n - 1);
    reflexo_horizontal_divide_conquista(original, transformacoes[4], 0, n - 1);
    reflexo_vertical_divide_conquista(original, transformacoes[5], 0, n - 1);
    diagonal_principal_divide_conquista(original, transformacoes[6], 0, n - 1);
    diagonal_secundaria_divide_conquista(original, transformacoes[7], 0, n - 1);
}

///Comparação com flag + recusiva (não sei se presisava)
// Verifica recursivamente se nova solução é igual a alguma transformação

void compara_com_transformacoes(int sol_idx, int t_idx, int transformacoes[8][MAX_N], int *encontrado) {
    if (*encontrado || t_idx == 8) return;

    int flag = 1;
    sao_iguais_rec(solucoes[sol_idx].posicoes, transformacoes[t_idx], 0, &flag);

    if (flag) {
        *encontrado = 1;
        return;
    }

    compara_com_transformacoes(sol_idx, t_idx + 1, transformacoes, encontrado);
}

void verifica_solucoes_existentes(int sol_idx, int total, int transformacoes[8][MAX_N], int *achou) {
    if (*achou || sol_idx == total) return;

    compara_com_transformacoes(sol_idx, 0, transformacoes, achou);

    if (*achou) return;

    verifica_solucoes_existentes(sol_idx + 1, total, transformacoes, achou);
}

/// CHECAGEM FINAL

int solucao_e_unica(int *nova) {
    int transformacoes[8][MAX_N] = {0};
    gerar_transformacoes(nova, transformacoes);

    int achou = 0;
    verifica_solucoes_existentes(0, total_solucoes, transformacoes, &achou);
    return !achou; // retorna 1 se for única, 0 se já existe
}


/// Exibe vetor da solução
void exibir_solucao_rec(int *tabuleiro, int i){
    if (i == n){
        printf("]\n");
        return;
    }
    printf("%d", tabuleiro[i]);
    if(i < n - 1) printf(",");
    exibir_solucao_rec(tabuleiro, i + 1);  //  chamada correta
}

void exibir_solucao(int *tabuleiro){
    printf("[");
    exibir_solucao_rec(tabuleiro, 0);
}
///Verifica se a posição atual da rainha (na linha `linha`) não entra em conflito
///com as linhas anteriores
int solucao_parcial_rec(int *tabuleiro, int linha, int k) {
    if (k == linha) return 1;
    if (tabuleiro[k] == tabuleiro[linha] || abs(tabuleiro[k] - tabuleiro[linha]) == abs(k - linha))
        return 0;
    return solucao_parcial_rec(tabuleiro, linha, k + 1);
}
void tentar_colunas(int linha, int *tabuleiro, int coluna) {
    if (coluna == n) return;

    tabuleiro[linha] = coluna;

    if (solucao_parcial_rec(tabuleiro, linha, 0)) {
        resolver(linha + 1, tabuleiro);
    }

    tentar_colunas(linha, tabuleiro, coluna + 1);
}

///backtracking
void resolver(int linha, int *tabuleiro) {
    chamadas_recursivas++;
    if (linha == n) {
        if (solucao_e_unica(tabuleiro)) {
            copiar_identidade_rec(tabuleiro, solucoes[total_solucoes].posicoes, 0);
            exibir_solucao(tabuleiro);
            total_solucoes++;
        }
        return;
    }
    tentar_colunas(linha, tabuleiro, 0);
}
