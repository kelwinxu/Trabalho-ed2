#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
///argc: argument count
///argv argument vector
int main(int argc, char *argv[]) {
    int lista[100], valores[100], tamanho = 0, qtd_valores = 0;

    /// Caso 1: argumentos pela linha de comando
    if (argc == 4) {
        tamanho = quebra_col(argv[1], lista);
        qtd_valores = quebra_col(argv[3], valores);
        executar_busca(lista, tamanho, valores, qtd_valores);
        return 0;
    }

    char buffer[256];

    printf("Digite a lista:");
    fgets(buffer, sizeof(buffer), stdin);
    /// Se apenas apertar ENTER, ativa o modo automático usando 'goto' (poderia ser substitudo por uma flag)
    if (strcmp(buffer, "\n") == 0) goto automatico;
    tamanho = quebra_col(buffer, lista);

    printf("Digite os valores a buscar:");
    fgets(buffer, sizeof(buffer), stdin);
    if (strcmp(buffer, "\n") == 0) goto automatico;
    qtd_valores = quebra_col(buffer, valores);

    executar_busca(lista, tamanho, valores, qtd_valores);
    return 0;

automatico:
    printf("Casos de teste auto\n");

    /// Teste 1: crescente
    int lista1[] = {1, 2, 3, 3, 3, 4, 5, 6}, valores1[] = {3, 7};
    printf("\nTeste 1 (Crescente):\n");
    executar_busca(lista1, sizeof(lista1) / sizeof(int), valores1, sizeof(valores1) / sizeof(int));

    /// Teste 2: decrescente
    int lista2[] = {8, 8, 6, 5, 5, 5, 3, 2, 1}, valores2[] = {5, 8, 7};
    printf("\nTeste 2 (Decrescente):\n");
    executar_busca(lista2, sizeof(lista2) / sizeof(int), valores2, sizeof(valores2) / sizeof(int));

    return 0;
}
