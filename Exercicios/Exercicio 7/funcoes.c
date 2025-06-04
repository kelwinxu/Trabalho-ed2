#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 20
#define MAX_SOLUCOES 100000
int flag;
int n;
void sao_iguais_rec(int *a, int *b, int i, int *flag) {
    if (*flag == 0 || i == n) return;
    if (a[i] != b[i]) {
        *flag = 0;
        return;
    }
    sao_iguais_rec(a, b, i + 1, flag);
}

typedef struct {
    int posicoes[MAX_N];
} Solucao;

Solucao solucoes[MAX_SOLUCOES];
int total_solucoes = 0;

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
/// Rotação de 90 graus
void rotacao_90_rec(int *original, int *destino, int i) {
    if (i == n) return;
    destino[original[i]] = n - 1 - i;
    rotacao_90_rec(original, destino, i + 1);
}
/// Rotação de 180 graus
void rotacao_180_rec(int *original, int *destino, int i) {
    if (i == n) return;
    destino[n - 1 - i] = n - 1 - original[i];
    rotacao_180_rec(original, destino, i + 1);
}
/// Rotação de 270 graus
void rotacao_270_rec(int *original, int *destino, int i) {
    if (i == n) return;
    destino[n - 1 - original[i]] = i;
    rotacao_270_rec(original, destino, i + 1);
}
/// reflexo horizontal
void reflexo_horizontal_rec(int *original, int *destino, int i) {
    if (i == n) return;
    destino[i] = n - 1 - original[i];
    reflexo_horizontal_rec(original, destino, i + 1);
}
/// reflexo vertical
void reflexo_vertical_rec(int *original, int *destino, int i) {
    if (i == n) return;
    destino[n - 1 - i] = original[i];
    reflexo_vertical_rec(original, destino, i + 1);
}

void diagonal_principal_rec(int *original, int *destino, int i) {
    if (i == n) return;
    destino[original[i]] = i;
    diagonal_principal_rec(original, destino, i + 1);
}

void diagonal_secundaria_rec(int *original, int *destino, int i) {
    if (i == n) return;
    destino[n - 1 - original[i]] = n - 1 - i;
    diagonal_secundaria_rec(original, destino, i + 1);
}
///Top 10 gambiarras do ano, puro algelin (teorizado não totalmente)
void gerar_transformacoes(int *original, int transformacoes[8][MAX_N]) {
    copiar_identidade_rec(original, transformacoes[0], 0);
    rotacao_90_rec(original, transformacoes[1], 0);
    rotacao_180_rec(original, transformacoes[2], 0);
    rotacao_270_rec(original, transformacoes[3], 0);
    reflexo_horizontal_rec(original, transformacoes[4], 0);
    reflexo_vertical_rec(original, transformacoes[5], 0);
    diagonal_principal_rec(original, transformacoes[6], 0);
    diagonal_secundaria_rec(original, transformacoes[7], 0);
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


/// Exibe vetor da solu��o
void exibir_solucao_rec(int *tabuleiro, int i){
    if (i == n){
        printf("]\n");
        return;
    }
    printf("%d", tabuleiro[i]);
    if(i < n - 1) printf(",");
    exibir_solucao_rec(tabuleiro, i + 1);  // ✅ chamada correta
}

void exibir_solucao(int *tabuleiro){
    printf("[");
    exibir_solucao_rec(tabuleiro, 0);
}

///O diabo vai temer isso
