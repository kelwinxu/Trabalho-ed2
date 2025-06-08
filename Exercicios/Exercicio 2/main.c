#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(int argc, char *argv[]) {
    int lista[100], valores[100], tamanho = 0, qtd_valores = 0;
    int decrescente = 0;

    if (argc == 4) {  // vetor, ordem, valores
        tamanho = quebra_col(argv[1], lista);
        qtd_valores = quebra_col(argv[3], valores);

        // Interpreta ordem
        if (strcmp(argv[2], "desc") == 0) {
            decrescente = 1;
        } else if (strcmp(argv[2], "asc") == 0) {
            decrescente = 0;
        } else {
            printf("Par�metro de ordem invalido. Use 'asc' ou 'desc'.\n");
            return 1;
        }

        executar_busca_com_ordem(lista, tamanho, valores, qtd_valores, decrescente);
        return 0;
    }

    if (argc == 1) {
        printf("Casos de teste autom:\n");

        int lista1[] = {1, 2, 3, 3, 3, 4, 5, 6}, valores1[] = {3, 7};
        printf("\nTeste 1 (Crescente):\n");
        executar_busca_com_ordem(lista1, sizeof(lista1) / sizeof(int), valores1, sizeof(valores1) / sizeof(int), 0);

        int lista2[] = {8, 8, 6, 5, 5, 5, 3, 2, 1}, valores2[] = {5, 8, 7};
        printf("\nTeste 2 (Decrescente):\n");
        executar_busca_com_ordem(lista2, sizeof(lista2) / sizeof(int), valores2, sizeof(valores2) / sizeof(int), 1);

        return 0;
    }

    printf("Uso incorreto.\n");
    printf("Modo correto: %s \"<vetor>\" <asc|desc> \"<valores>\"\n", argv[0]);
    return 1;
}
