#ifndef EXERCICIO1_H_INCLUDED
#define EXERCICIO1_H_INCLUDED

//O programa deste exercicio aceita, assim como especificado no enunciado do trabalho, 6 valores inteiros como parametro, ou seja, 5 digitos que formam a expressao e outro sendo o valor final.

int while_recursivo(char *valores, int numeros[20], int i, int *tam); //esta será uma funcao que vai basicamente pegar a string e separar em um vetor de inteiros, alem de contar a quantidade de numeros que vai formar a expressao.
void embaralha_operacoes(int i, int a, int b, int c, int d, int e, int valor_alvo, int k, int *nrosolucoes, int *nrochamadas); //a função que é a base do nosso programa, ela vai basicamente embaralhar as operacoes e testar se com uma determinada sequencia de numeros seria possivel chegar ao valor final.
void trocar(char *a, char *b); //funcao auxiliar que vai ajudar a funcao permutar.
int pega_indice(char letra); //outra função auxiliar, neste caso vai ajudar com a função funcaoatribuirvalores.
void funcaoatribuirvalores(char *vetorpermutado, int *numeros, int valor_alvo, int k, int *nrosolucoes, int *nrochamadas); //funcao que vai, a partir da funcao de permutacao abaixo, transformar a string em numeros, pois na funcao de permutar eu nao lidei com o vetor de inteiros diretamente, mas com esta função aqui ela transforma nos inteiros.
void permutar(char *vetor_indices, int inicio, int fim, int *numeros_originais, int valor_alvo, int k, int *nrosolucoes, int *nrochamadas); //funcao muito importante, diferente da funcao embaralhaoperacoes, que embaralhava a ordem de operacoes, esta funcao embaralha a ordem dos numeros, criando todas as permutações.

#endif
