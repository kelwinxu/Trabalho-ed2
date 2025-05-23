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
///
void check_operation(int **permutations, int iteracao, int valor);

void F_OP(int op);
void F_ELEM(int a);
void F_print(int v[6],int sinais[5]);
#endif // EXCERC_H_INCLUDED

