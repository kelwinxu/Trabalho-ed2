#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

// Função que encontra a primeira ocorrência de um valor na lista ordenada asc ou desc
int encontrar_primeira_ocorrencia(int lista[], int esquerda, int direita, int valor, int decrescente) {
    if (esquerda > direita) return -1;

    int meio = esquerda + (direita - esquerda) / 2;

    if (lista[meio] == valor) {
        int anterior = encontrar_primeira_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
        return (anterior != -1) ? anterior : meio;
    }

    if ((decrescente && lista[meio] < valor) || (!decrescente && lista[meio] > valor)) {
        return encontrar_primeira_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
    } else {
        return encontrar_primeira_ocorrencia(lista, meio + 1, direita, valor, decrescente);
    }
}

// Função que encontra a última ocorrência de um valor na lista ordenada asc ou desc
int encontrar_ultima_ocorrencia(int lista[], int esquerda, int direita, int valor, int decrescente) {
    if (esquerda > direita) return -1;

    int meio = esquerda + (direita - esquerda) / 2;

    if (lista[meio] == valor) {
        int posterior = encontrar_ultima_ocorrencia(lista, meio + 1, direita, valor, decrescente);
        return (posterior != -1) ? posterior : meio;
    }

    if ((decrescente && lista[meio] < valor) || (!decrescente && lista[meio] > valor)) {
        return encontrar_ultima_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
    } else {
        return encontrar_ultima_ocorrencia(lista, meio + 1, direita, valor, decrescente);
    }
}

// Busca valores e armazena resultados
void buscar_valores_repetidos(int lista[], int tamanho, int valores[], int qtd_valores, int resultado[][2], int decrescente) {
    for (int i = 0; i < qtd_valores; i++) {
        resultado[i][0] = encontrar_primeira_ocorrencia(lista, 0, tamanho - 1, valores[i], decrescente);
        resultado[i][1] = encontrar_ultima_ocorrencia(lista, 0, tamanho - 1, valores[i], decrescente);
    }
}

// Função que executa busca e imprime resultados
void executar_busca_com_ordem(int lista[], int tamanho, int valores[], int qtd_valores, int decrescente) {
    int resultado[100][2];
    buscar_valores_repetidos(lista, tamanho, valores, qtd_valores, resultado, decrescente);

    for (int i = 0; i < qtd_valores; i++) {
        printf("Valor %d: (%d, %d)\n", valores[i], resultado[i][0], resultado[i][1]);
    }
}

// Função que limpa colchetes e separa por vírgula
int quebra_col(char *str, int arr[]) {
    int c = 0;
    int len = strlen(str);
    char *limpa = malloc(len + 1);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != '[' && str[i] != ']') {
            limpa[j++] = str[i];
        }
    }
    limpa[j] = '\0';

    char *quebra = strtok(limpa, ",");
    while (quebra != NULL) {
        arr[c++] = atoi(quebra);
        quebra = strtok(NULL, ",");
    }

    free(limpa);
    return c;
}
