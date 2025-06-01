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
