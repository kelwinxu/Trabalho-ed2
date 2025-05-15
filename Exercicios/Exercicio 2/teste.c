#include <stdio.h>

// Função que verifica se a lista está ordenada de forma decrescente
int ver_decrescente(int lista[], int esquerda, int direita) {
    if (esquerda >= direita) return 0;
    return lista[esquerda] > lista[direita];
}

// Função recursiva que encontra a primeira ocorrência de um valor na lista
int encontrar_primeira_ocorrencia(int lista[], int esquerda, int direita, int valor, int decrescente) {
    if (esquerda > direita) return -1; // Caso base: não encontrou o valor

    int meio = esquerda + (direita - esquerda) / 2;

    // Se encontrou o valor no meio, procura a primeira ocorrência (à esquerda)
    if (lista[meio] == valor) {
        int anterior = encontrar_primeira_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
        return (anterior != -1) ? anterior : meio; // Retorna a posição mais à esquerda
    }

    // Se a lista for decrescente e o valor procurado for menor que o valor do meio, procura à esquerda
    // Se for crescente e o valor procurado for maior, procura à esquerda
    if ((decrescente && lista[meio] < valor) || (!decrescente && lista[meio] > valor)) {
        return encontrar_primeira_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
    }
    // Caso contrário, procura à direita
    else {
        return encontrar_primeira_ocorrencia(lista, meio + 1, direita, valor, decrescente);
    }
}