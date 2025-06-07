#ifndef EXERCICIO1_H_INCLUDED
#define EXERCICIO1_H_INCLUDED

int while_recursivo(char *valores, int numeros[20], int i, int *tam);
void embaralha_operacoes(int i, int a, int b, int c, int d, int e, int valor_alvo, int k, int *nrosolucoes, int *nrochamadas);
void trocar(char *a, char *b);
int pega_indice(char letra);
void funcaoatribuirvalores(char *vetorpermutado, int *numeros, int valor_alvo, int k, int *nrosolucoes, int *nrochamadas);
void permutar(char *vetor_indices, int inicio, int fim, int *numeros_originais, int valor_alvo, int k, int *nrosolucoes, int *nrochamadas);

#endif
