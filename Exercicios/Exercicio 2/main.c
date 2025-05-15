#include <stdio.h>
#define DEBUG 1

#include <stdio.h>
#include <conio.h>    // Para _kbhit() e _getch()
#include <windows.h>  // Para Sleep()
#define DEBUG 1

// Declaração da função externa
void buscar_valores_repetidos(int lista[], int tamanho, int valores[], int qtd_valores, int resultado[][2]);
/*
8
8
6
5
5
5
3
2
1
*/
int main() {
    int lista[50];
    int valores[50];
    int tamanho = 8;       // usaremos 9 posições em lista
    int qtd_valores = 3;   // usaremos 3 posições em valores
    int resultado[3][2];   // tamanho fixo correspondente a qtd_valores

    int entrada_feita = 0;

    for (int i = 0; i < 10; i++) {  // loop com espera de entrada
        if (_kbhit()) {
            char ch = _getch(); // consome o caractere digitado
            if (DEBUG) printf("DEBUG: Digite 9 valores para o vetor da lista:\n");

            for (int j = 0; j < tamanho; j++) {
                scanf("%d", &lista[j]);
            }
            tamanho = sizeof(lista) / sizeof(lista[0]);

            if (DEBUG) printf("DEBUG: Digite 3 valores a buscar:\n");
            for (int k = 0; k < qtd_valores; k++) {
                scanf("%d", &valores[k]);
            }

            buscar_valores_repetidos(lista, tamanho, valores, qtd_valores, resultado);

            printf("\nResultado da busca:\n");
            for (int i = 0; i < qtd_valores; i++) {
                printf("Valor %d: (%d, %d)\n", valores[i], resultado[i][0], resultado[i][1]);
            }

            entrada_feita = 1;
            break;  // sai do laço após entrada do usuário
        } else {
            Sleep(1000); // espera 1 segundo antes de tentar novamente
        }
    }

    // Se o usuário não digitou nada em 10 segundos, usa vetor fixo
    if (!entrada_feita) {
        int lista_padrao[] = {8, 8, 6, 5, 5, 5, 3, 2, 1};
        int valores_padrao[] = {5, 8, 7};

        tamanho = sizeof(lista_padrao) / sizeof(lista_padrao[0]);
        qtd_valores = sizeof(valores_padrao) / sizeof(valores_padrao[0]);

        // Copiando para os vetores principais
        for (int i = 0; i < tamanho; i++) lista[i] = lista_padrao[i];
        for (int i = 0; i < qtd_valores; i++) valores[i] = valores_padrao[i];

        buscar_valores_repetidos(lista, tamanho, valores, qtd_valores, resultado);

        printf("\nResultado (automático após 10 segundos):\n");
        for (int i = 0; i < qtd_valores; i++) {
            printf("Valor %d: (%d, %d)\n", valores[i], resultado[i][0], resultado[i][1]);
        }
    }

    return 0;
}

/*
#include <stdio.h>
#define DEBUG 1

int main()
{
    int lista[50];
    int valores[50];

    for (int i = 0; i < 10; i++)   // espera durante 1 segundo ser digitado algo, se nada for digitado faz com os veotres
{
        if (_kbhit())   // se uma tecla foi pressionada
        {
            char ch = _getch(); // lê sem esperar Enter
            if(DEBUG == 1)printf("DEBUG: Digite o valor do vetor da lista\n");
            for(int j = 0; j < 9; j++)
            {
                scanf("%d",&lista[j]);
            }
            int tamanho = sizeof(lista) / sizeof(lista[0]);
            if(DEBUG == 1)printf("DEBUG: Digite o valor do vetor de valor\n");
            for(int k=0; k<3; k++)
            {
                scanf("%d",&valores[k]);
            }
            int qtd_valores = sizeof(valores) / sizeof(valores[0]);
            int resultado[qtd_valores][2];

            // Chama a função para buscar os valores
            buscar_valores_repetidos(lista, tamanho, valores, qtd_valores, resultado);

            // Imprime os resultados
            for (int i = 0; i < qtd_valores; i++)
            {
                printf("Valor %d: (%d, %d)\n", valores[i], resultado[i][0], resultado[i][1]);
            }


        }
        else
        {
            int lista[] = {8,8,6,5,5,5,3,2,1};
            int tamanho = sizeof(lista) / sizeof(lista[0]);
            int valores[] = {5,8,7};
            int qtd_valores = sizeof(valores) / sizeof(valores[0]);
            // Vetor que armazenará os resultados da busca
            int resultado[qtd_valores][2];

            // Chama a função para buscar os valores
            buscar_valores_repetidos(lista, tamanho, valores, qtd_valores, resultado);

            // Imprime os resultados
            for (int i = 0; i < qtd_valores; i++)
            {
                printf("Valor %d: (%d, %d)\n", valores[i], resultado[i][0], resultado[i][1]);
            }

        }
        Sleep(1000); // espera 100ms
    }
    // Exemplo de lista ordenada de forma decrescente
    //int lista[] = {8,8,6,5,5,5,3,2,1};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    // Valores a serem buscados
    //if(DEBUG == 1)printf("DEBUG: Digite o valor do vetor de valor\n");
    //int valores[] = {5,8,7};
    int qtd_valores = sizeof(valores) / sizeof(valores[0]);

    // Vetor que armazenará os resultados da busca
    int resultado[qtd_valores][2];

    // Chama a função para buscar os valores
    buscar_valores_repetidos(lista, tamanho, valores, qtd_valores, resultado);

    // Imprime os resultados
    for (int i = 0; i < qtd_valores; i++)
    {
        printf("Valor %d: (%d, %d)\n", valores[i], resultado[i][0], resultado[i][1]);
    }

    return 0;
}
*/
