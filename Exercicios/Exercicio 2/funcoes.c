#include <stdio.h>
// Fun��o que verifica se a lista est� ordenada de forma decrescente
int ver_decrescente(int lista[], int esquerda, int direita) {
    if (esquerda >= direita) return 0;
    return lista[esquerda] > lista[direita];
}
// Fun��o recursiva que encontra a primeira ocorr�ncia de um valor na lista
int encontrar_primeira_ocorrencia(int lista[], int esquerda, int direita, int valor, int decrescente) {
    if (esquerda > direita) return -1; // Caso base: n�o encontrou o valor

    int meio = esquerda + (direita - esquerda) / 2;

    // Se encontrou o valor no meio, procura a primeira ocorr�ncia (� esquerda)
    if (lista[meio] == valor) {
        int anterior = encontrar_primeira_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
        return (anterior != -1) ? anterior : meio; // Retorna a posi��o mais � esquerda
    }

    // Se a lista for decrescente e o valor procurado for menor que o valor do meio, procura � esquerda
    // Se for crescente e o valor procurado for maior, procura � esquerda
    if ((decrescente && lista[meio] < valor) || (!decrescente && lista[meio] > valor)) {
        return encontrar_primeira_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
    }
    // Caso contr�rio, procura � direita
    else {
        return encontrar_primeira_ocorrencia(lista, meio + 1, direita, valor, decrescente);
    }
}

// Fun��o recursiva que encontra a �ltima ocorr�ncia de um valor na lista
int encontrar_ultima_ocorrencia(int lista[], int esquerda, int direita, int valor, int decrescente) {
    if (esquerda > direita) return -1; // Caso base: n�o encontrou o valor

    int meio = esquerda + (direita - esquerda) / 2;

    // Se encontrou o valor no meio, procura a �ltima ocorr�ncia (� direita)
    if (lista[meio] == valor) {
        int posterior = encontrar_ultima_ocorrencia(lista, meio + 1, direita, valor, decrescente);
        return (posterior != -1) ? posterior : meio; // Retorna a posi��o mais � direita
    }

    // Se a lista for decrescente e o valor procurado for menor que o valor do meio, procura � esquerda
    // Se for crescente e o valor procurado for maior, procura � esquerda
    if ((decrescente && lista[meio] < valor) || (!decrescente && lista[meio] > valor)) {
        return encontrar_ultima_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
    }
    // Caso contr�rio, procura � direita
    else {
        return encontrar_ultima_ocorrencia(lista, meio + 1, direita, valor, decrescente);
    }
}

// Fun��o principal que realiza a busca para m�ltiplos valores
void buscar_valores_repetidos(int lista[], int tamanho, int valores[], int qtd_valores, int resultado[][2]) {
    // Determina se a lista est� em ordem decrescente ou crescente
    int decrescente = ver_decrescente(lista, 0, tamanho - 1);

    // Fun��o recursiva auxiliar para percorrer todos os valores a serem buscados
    void procurar_valor(int indice) {
        if (indice == qtd_valores) return; // Caso base: n�o h� mais valores para procurar

        // Encontrar a primeira e �ltima ocorr�ncia do valor procurado
        int primeira = encontrar_primeira_ocorrencia(lista, 0, tamanho - 1, valores[indice], decrescente);
        int ultima = encontrar_ultima_ocorrencia(lista, 0, tamanho - 1, valores[indice], decrescente);

        // Armazenar os resultados no vetor resultado
        resultado[indice][0] = primeira;
        resultado[indice][1] = ultima;

        // Chama recursivamente para o pr�ximo valor a ser buscado
        procurar_valor(indice + 1);
    }

    // Inicia a busca recursiva para o primeiro valor
    procurar_valor(0);
}
