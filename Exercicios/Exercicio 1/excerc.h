#ifndef EXCERC_H_INCLUDED
#define EXCERC_H_INCLUDED
#define MAX_SIZE 6

/// algoritmo "Heap's Algorithm"
void funcao_anagramas(int v[MAX_SIZE],int tam,int **permutations);

/// funcao escanear
void escanear(int *v,int tam);

/// funcao printar
void printar(int  *v,int tam);

/// aloca, dentro de um pointeiro de ponteiro, os ponteiros de tamanho MAX_SIZE.
void **vetor_alocate(int **permutations, int tam);
#endif // EXCERC_H_INCLUDED
