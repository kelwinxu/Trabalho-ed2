#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#define MAX_N 20

int n = 0;
void resolver(int linha, int *tabuleiro);

int main(int argc, char *argv[]) {
    int tabuleiro[MAX_N];
    char buffer[16];

    //printf("Digite o valor de N (ou apenas ENTER para modo automático): ");

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Erro ao ler entrada.\n");
        return 1;
    }

    // Remove o \n do final da string
    buffer[strcspn(buffer, "\n")] = '\0';

    if (buffer[0] == '\0') {
        // Modo automático
        printf("Iniciando Execucao auto...\n");

        if (argc == 2) {
            n = atoi(argv[1]);
            if (n <= 0 || n > MAX_N) {
                printf("Valor de N invalido.\n");
                return 1;
            }

            total_solucoes = 0;
            chamadas_recursivas = 0;
            resolver(0, tabuleiro);

            if (total_solucoes == 0)
                printf("Nao ha solucao para %d rainhas.\n", n);
            else
                printf("\nTotal de solucoes unicas para n=%d: %d\n", n, total_solucoes);

            printf("Chamadas recursivas: %d\n", chamadas_recursivas);
        } else {
            int testes[] = {4, 8};
            for (int i = 0; i < 2; i++) {
                n = testes[i];
                total_solucoes = 0;
                chamadas_recursivas = 0;
                printf("\nTestando para N = %d:\n", n);
                resolver(0, tabuleiro);

                if (total_solucoes == 0)
                    printf("Nao ha solucao para %d rainhas.\n", n);
                else
                    printf("Total de solucoes unicas: %d\n", total_solucoes);

                printf("Chamadas recursivas: %d\n", chamadas_recursivas);
            }
        }
    } else {
        // Conversão e validação
        n = atoi(buffer);
        if (n < 1 || n > MAX_N) {
            printf("Valor de N invalido.\n");
            return 1;
        }

        total_solucoes = 0;
        chamadas_recursivas = 0;
        resolver(0, tabuleiro);
        printf("Total de solucoes unicas: %d\n", total_solucoes);
        printf("Chamadas recursivas: %d\n", chamadas_recursivas);
    }

    return 0;
}
