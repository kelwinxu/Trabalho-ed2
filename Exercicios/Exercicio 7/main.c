#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funcoes.h"

#define MAX_N 20
#define MAX_SOLUCOES 100000

int main() {
    int n = 8; // Tamanho do tabuleiro (por exemplo, 8x8)

    // Testando uma nova solução qualquer
    int nova_solucao[MAX_N] = {0,4,7,5,2,6,1,3}; // Solução conhecida para 8 rainhas

    if (solucao_e_unica(nova_solucao)) {
        printf("Solucao e unica. Armazenando...\n");

        // Armazena a nova solução
        copiar_identidade_rec(nova_solucao, solucoes[total_solucoes].posicoes, 0);
        total_solucoes++;

        exibir_solucao(nova_solucao); // Mostra a solução
    } else {
        printf("Solucao ja existe (simetrica).\n");
    }

    // Testando uma simétrica (espelho horizontal, por exemplo)
    int espelho[MAX_N];
    reflexo_horizontal_rec(nova_solucao, espelho, 0);

    if (solucao_e_unica(espelho)) {
        printf("Espelho e unico. Armazenando...\n");
        copiar_identidade_rec(espelho, solucoes[total_solucoes].posicoes, 0);
        total_solucoes++;

        exibir_solucao(espelho);
    } else {
        printf("Espelho ja existe (simetrico de uma solucao anterior).\n");
    }

    return 0;
}

