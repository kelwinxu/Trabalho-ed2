#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "funcoes.h"

/// Função para limpar colchetes e quebrar string por vírgula
int parse_lista(char *str, int arr[]) {
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

void executar_busca(int lista[], int tamanho, int valores[], int qtd_valores) {
    int resultado[100][2];

    buscar_valores_repetidos(lista, tamanho, valores, qtd_valores, resultado);

    for (int i = 0; i < qtd_valores; i++) {
        printf("Valor %d: (%d, %d)\n", valores[i], resultado[i][0], resultado[i][1]);
    }
}
///Gambiarra no main
///argc: argument count
///argv argument vector
///Ambos trabalhando com argumentos passados, tentar evitar isso se possivel
int main(int argc, char *argv[]) {
    int lista[100], valores[100], tamanho = 0, qtd_valores = 0;

    /// Caso 1: argumentos pela linha de comando
    if (argc == 4) {
        ///Se forem passados 4 argumentos
            ///Argv[0] -> meu exe
            ///Argv[2] -> asc por exemplo

        /// Converte a string do primeiro argumento para um vetor de inteiros
        tamanho = parse_lista(argv[1], lista);
        /// Converte a string do terceiro argumento para um vetor de inteiros
        qtd_valores = parse_lista(argv[3], valores);
        ///Busca de valores
        buscar_valores_repetidos(lista, tamanho, valores, qtd_valores, (int[100][2]){0});
        //printf("\nResultado da busca:\n");
        executar_busca(lista, tamanho, valores, qtd_valores);
        return 0;
    }

    ///espera por entrada via teclado por 10 segundos se não tiver executa um caso pre estabelecido
    int aguardado = 0;
    for (int i = 0; i < 10; i++) {
        if (_kbhit()) {
            _getch(); // Consome tecla
            aguardado = 1;
            break;
        }
        Sleep(1000);
    }

    if (aguardado) {
        char buffer[256];
        ///Digitar o vetor
        printf("");
        fgets(buffer, sizeof(buffer), stdin);
        tamanho = parse_lista(buffer, lista);
        ///Valores a buscar
        printf("");
        fgets(buffer, sizeof(buffer), stdin);
        qtd_valores = parse_lista(buffer, valores);

        executar_busca(lista, tamanho, valores, qtd_valores);
    } else {
        ///Espera cerca de 10 seg até colocar busca automatica

        /// Teste 1: crescente
        int lista1[] = {1, 2, 3, 3, 3, 4, 5, 6}, valores1[] = {3, 7};
        printf("\nTeste 1 (Crescente):\n");
        executar_busca(lista1, sizeof(lista1) / sizeof(int), valores1, sizeof(valores1) / sizeof(int));

        /// Teste 2: decrescente
        int lista2[] = {8, 8, 6, 5, 5, 5, 3, 2, 1}, valores2[] = {5, 8, 7};
        printf("\nTeste 2 (Decrescente):\n");
        executar_busca(lista2, sizeof(lista2) / sizeof(int), valores2, sizeof(valores2) / sizeof(int));
    }

    return 0;
}
