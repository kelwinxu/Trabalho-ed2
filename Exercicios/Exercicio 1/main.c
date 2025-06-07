#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio1.h"

int main(int argc, char *argv[]) {
    int valor_alvo; // variavel do resultado que devemos alcancar
    int k; // variavel que vai contabilizar a quantidade de elementos na lista + o elemento do resultado
    char stringvalores[20]; // vetor que vai guardar a string antes de ser formatada
    char *valores;
    char valorfinal[5]; //string que vai guardar o valor antes da formatacao
    int tamanho = 0; //variavel que vai servir para guardar o tamanho da lista
    int numeros[20]; //vetor que vai guardar os numeros da lista apos a formatacao, deixando de serem string
    int nrosolucoes = 0; //variavel que vai servir para as funcoes pararem apos acharem a primeira solucao, sem continuar realizando chamadas recursivas.
    int nrochamadas = 0; //variavel que vai servir para identificar quantas chamadas recursivas foram realizadas ate achar o resultado.

    if (argc != 3 && argc != 1) {
        printf("algo deu errado\n"); //se por acaso o numeros de argumentos que o usuario colocou nao esteja de acordo, ou seja, se nao executou o programa com nenhum argumento, o que levaria aos casos de exemplo/teste, ou nao colocou a lista e o resultado. Logo, nao executara o programa como desejado.
        return 1;
    }

 else if (argc == 1) { //argc==1, ou seja, nao foram inseridos nem a lista nem o resultado, devendo fazer os casos de teste para completar o programa.

        char string_exemplo1[] = "3,4,2";//string do primeiro caso de teste

        strcpy(stringvalores, string_exemplo1);
        valor_alvo = 14;
        tamanho = 0;
        nrosolucoes = 0;
        nrochamadas = 0;
        memset(numeros, 0, sizeof(numeros));
        valores = strtok(stringvalores, ",");
        if (valores != NULL) {
            while_recursivo(valores, numeros, 0, &tamanho);
        }

        if (tamanho > 0 && tamanho <= 5) {
            char vetor_indices1[6];
            for (int idx = 0; idx < tamanho; idx++) {
                vetor_indices1[idx] = 'A' + idx;
            }
            vetor_indices1[tamanho] = '\0';
            k = tamanho + 1;

            permutar(vetor_indices1, 0, tamanho - 1, numeros, valor_alvo, k, &nrosolucoes, &nrochamadas);
        }

        char string_exemplo2[] = "5,2,1,8"; //string para o segundo caso de teste

        strcpy(stringvalores, string_exemplo2);
        valor_alvo = 16;
        tamanho = 0;
        nrosolucoes = 0;
        nrochamadas = 0;
        memset(numeros, 0, sizeof(numeros));
        valores = strtok(stringvalores, ",");
        if (valores != NULL) {
            while_recursivo(valores, numeros, 0, &tamanho);
        }

        if (tamanho > 0 && tamanho <= 5) {
            char vetor_indices2[6];
            for (int idx = 0; idx < tamanho; idx++) {
                vetor_indices2[idx] = 'A' + idx;
            }
            vetor_indices2[tamanho] = '\0';
            k = tamanho + 1;

            permutar(vetor_indices2, 0, tamanho - 1, numeros, valor_alvo, k, &nrosolucoes, &nrochamadas);
        }

    }

    else if (argc ==3){ // argc == 3, ou seja, foram inseridos tanto a lista quanto o resultado

        strcpy(stringvalores, argv[1]);
        strcpy(valorfinal, argv[2]);
    }

    valor_alvo = atoi(valorfinal); //convertemos a string do resultado em inteiro
    valores = strtok(stringvalores, ",");
    if (valores != NULL) {
        while_recursivo(valores, numeros, 0, &tamanho);
    }

    if (tamanho > 0 && tamanho <= 5) {
        char vetor_indices[6];

        for (int idx = 0; idx < tamanho; idx++) {
            vetor_indices[idx] = 'A' + idx;
        }
        vetor_indices[tamanho] = '\0';
        k = tamanho + 1; //define k, que ja falamos anteriormente o que signfica

        permutar(vetor_indices, 0, tamanho - 1, numeros, valor_alvo, k, &nrosolucoes, &nrochamadas); //aqui esta chamando a funcao principal, que vai permutar a ordem dos numeros, a partir dela, tambem irao ser chamadas outras funcoes importantes

        if (nrosolucoes == 0) {
            printf("Nao foi possiıvel formar o valor alvo.\n"); //caso, mesmo permutando todos os numeros e embaralhando as operacoes, nao ache nenhuma solucao, nosso programa printara isso.
        }}

    return 0;
}
