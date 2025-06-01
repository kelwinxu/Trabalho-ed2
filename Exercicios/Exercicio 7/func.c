bool sao_iguais(int *a, int *b) {
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) return false;
    return true;
}

///Gambiarra rota��o
void gerar_transformacoes(int *original, int transformacoes[8][MAX_N]) {
    for (int i = 0; i < n; i++)
        transformacoes[0][i] = original[i]; // Identidade

    // Rota��o 90�
    for (int i = 0; i < n; i++)
        transformacoes[1][original[i]] = n - 1 - i;

    // Rota��o 180�
    for (int i = 0; i < n; i++)
        transformacoes[2][n - 1 - i] = n - 1 - original[i];

    // Rota��o 270�
    for (int i = 0; i < n; i++)
        transformacoes[3][n - 1 - original[i]] = i;

    // Reflex�o horizontal
    for (int i = 0; i < n; i++)
        transformacoes[4][i] = n - 1 - original[i];

    // Reflex�o vertical
    for (int i = 0; i < n; i++)
        transformacoes[5][n - 1 - i] = original[i];

    // Diagonal principal
    for (int i = 0; i < n; i++)
        transformacoes[6][original[i]] = i;

    // Diagonal secund�ria
    for (int i = 0; i < n; i++)
        transformacoes[7][n - 1 - original[i]] = n - 1 - i;
}

/// Verifica se a solu��o (com simetrias) j� foi encontrada
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

/// Exibe vetor da solu��o
void exibir_solucao(int *tabuleiro) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", tabuleiro[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}
