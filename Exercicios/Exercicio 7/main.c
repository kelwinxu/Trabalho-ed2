#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "funcoes.h"

#define MAX_N 20 ///O programa simplemente da overflow entre 13-15

/// Protótipos
int n = 0;
void resolver(int linha, int *tabuleiro);

int main(int argc, char *argv[])
{
    int tabuleiro[MAX_N];
    char buffer[16];
    int tecla_pressionada = 0;

    while (_kbhit()) _getch(); // limpar buffer

    for (int i = 0; i < 10; i++)
    {
        //printf("%d...\n", i);
        if (_kbhit())
        {
            tecla_pressionada = 1;
            break;
        }
        Sleep(1000);
    }

    if (tecla_pressionada)
    {
        // Leitura da linha inteira para aceitar valores maiores que 9
        printf("Digite o valor de N (1-%d): ", MAX_N);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            n = atoi(buffer);
            if (n < 1 || n > MAX_N)
            {
                printf("Valor de N invalido.\n");
                return 1;
            }

            total_solucoes = 0;
            chamadas_recursivas = 0;
            //printf("\nExecutando para N = %d (entrada do usuário)\n", n);
            resolver(0, tabuleiro);
            printf("Total de solucoes unicas: %d\n", total_solucoes);
            printf("Chamadas recursivas: %d\n", chamadas_recursivas);
            return 0;
        }
        else
        {
            printf("Erro ao ler entrada.\n");
            return 1;
        }
    }
    else
    {
        printf("Iniciando Execucao auto...\n");

        if (argc == 2)
        {
            n = atoi(argv[1]);
            if (n <= 0 || n > MAX_N)
            {
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
        }
        else
        {
            int testes[] = {4, 8};
            for (int i = 0; i < 2; i++)
            {
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
    }

    return 0;
}
