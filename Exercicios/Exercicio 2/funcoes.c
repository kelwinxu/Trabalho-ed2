#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

// Encontra a primeira ocorrência do valor
int encontrar_primeira_ocorrencia(int lista[], int esquerda, int direita, int valor, int decrescente) {
    if (esquerda > direita) return -1;

    int meio = esquerda + (direita - esquerda) / 2;

    if (lista[meio] == valor) {
        int anterior = encontrar_primeira_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
        return (anterior != -1) ? anterior : meio;
    }

    if ((decrescente && lista[meio] < valor) || (!decrescente && lista[meio] > valor))
        return encontrar_primeira_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
    else
        return encontrar_primeira_ocorrencia(lista, meio + 1, direita, valor, decrescente);
}

// Encontra a última ocorrência do valor
int encontrar_ultima_ocorrencia(int lista[], int esquerda, int direita, int valor, int decrescente) {
    if (esquerda > direita) return -1;

    int meio = esquerda + (direita - esquerda) / 2;

    if (lista[meio] == valor) {
        int posterior = encontrar_ultima_ocorrencia(lista, meio + 1, direita, valor, decrescente);
        return (posterior != -1) ? posterior : meio;
    }

    if ((decrescente && lista[meio] < valor) || (!decrescente && lista[meio] > valor))
        return encontrar_ultima_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
    else
        return encontrar_ultima_ocorrencia(lista, meio + 1, direita, valor, decrescente);
}

// Busca os valores repetidos recursivamente
void buscar_valores_repetidos_rec(int lista[], int tamanho, int valores[], int resultado[][2], int decrescente, int i, int qtd_valores) {
    if (i >= qtd_valores) return;
    resultado[i][0] = encontrar_primeira_ocorrencia(lista, 0, tamanho - 1, valores[i], decrescente);
    resultado[i][1] = encontrar_ultima_ocorrencia(lista, 0, tamanho - 1, valores[i], decrescente);
    buscar_valores_repetidos_rec(lista, tamanho, valores, resultado, decrescente, i + 1, qtd_valores);
}

// Interface para busca
void buscar_valores_repetidos(int lista[], int tamanho, int valores[], int qtd_valores, int resultado[][2], int decrescente) {
    buscar_valores_repetidos_rec(lista, tamanho, valores, resultado, decrescente, 0, qtd_valores);
}

// Impressão recursiva dos resultados
void imprimir_resultado_rec(int valores[], int resultado[][2], int i, int qtd_valores) {
    if (i >= qtd_valores) return;
    printf("Valor %d: (%d, %d)\n", valores[i], resultado[i][0], resultado[i][1]);
    imprimir_resultado_rec(valores, resultado, i + 1, qtd_valores);
}

void executar_busca_com_ordem(int lista[], int tamanho, int valores[], int qtd_valores, int decrescente) {
    int resultado[100][2];
    buscar_valores_repetidos(lista, tamanho, valores, qtd_valores, resultado, decrescente);
    imprimir_resultado_rec(valores, resultado, 0, qtd_valores);
}

// Remove colchetes recursivamente
void limpar_colchetes_rec(char *origem, char *destino, int i, int j) {
    if (origem[i] == '\0') {
        destino[j] = '\0';
        return;
    }
    if (origem[i] != '[' && origem[i] != ']') {
        destino[j] = origem[i];
        limpar_colchetes_rec(origem, destino, i + 1, j + 1);
    } else {
        limpar_colchetes_rec(origem, destino, i + 1, j);
    }
}

// Converte string em inteiros recursivamente
int quebrar_valores_rec(char *str, int arr[], int pos) {
    if (str == NULL) return pos;
    arr[pos] = atoi(str);
    return quebrar_valores_rec(strtok(NULL, ","), arr, pos + 1);
}

// Interface principal para quebra de colchetes
int quebra_col(char *str, int arr[]) {
    int len = strlen(str);
    char *limpa = malloc(len + 1);
    limpar_colchetes_rec(str, limpa, 0, 0);
    int resultado = quebrar_valores_rec(strtok(limpa, ","), arr, 0);
    free(limpa);
    return resultado;
}
