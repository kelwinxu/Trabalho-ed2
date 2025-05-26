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

// Função recursiva que encontra a última ocorrência de um valor na lista
int encontrar_ultima_ocorrencia(int lista[], int esquerda, int direita, int valor, int decrescente) {
    if (esquerda > direita) return -1; // Caso base: não encontrou o valor

    int meio = esquerda + (direita - esquerda) / 2;

    // Se encontrou o valor no meio, procura a última ocorrência (à direita)
    if (lista[meio] == valor) {
        int posterior = encontrar_ultima_ocorrencia(lista, meio + 1, direita, valor, decrescente);
        return (posterior != -1) ? posterior : meio; // Retorna a posição mais à direita
    }

    // Se a lista for decrescente e o valor procurado for menor que o valor do meio, procura à esquerda
    // Se for crescente e o valor procurado for maior, procura à esquerda
    if ((decrescente && lista[meio] < valor) || (!decrescente && lista[meio] > valor)) {
        return encontrar_ultima_ocorrencia(lista, esquerda, meio - 1, valor, decrescente);
    }
    // Caso contrário, procura à direita
    else {
        return encontrar_ultima_ocorrencia(lista, meio + 1, direita, valor, decrescente);
    }
}

// Função principal que realiza a busca para múltiplos valores
void buscar_valores_repetidos(int lista[], int tamanho, int valores[], int qtd_valores, int resultado[][2]) {
    // Determina se a lista está em ordem decrescente ou crescente
    int decrescente = ver_decrescente(lista, 0, tamanho - 1);

    // Função recursiva auxiliar para percorrer todos os valores a serem buscados
    void procurar_valor(int indice) {
        if (indice == qtd_valores) return; // Caso base: não há mais valores para procurar

        // Encontrar a primeira e última ocorrência do valor procurado
        int primeira = encontrar_primeira_ocorrencia(lista, 0, tamanho - 1, valores[indice], decrescente);
        int ultima = encontrar_ultima_ocorrencia(lista, 0, tamanho - 1, valores[indice], decrescente);

        // Armazenar os resultados no vetor resultado
        resultado[indice][0] = primeira;
        resultado[indice][1] = ultima;

        // Chama recursivamente para o próximo valor a ser buscado
        procurar_valor(indice + 1);
    }

    // Inicia a busca recursiva para o primeiro valor
    procurar_valor(0);
}
