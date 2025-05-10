#include <stdio.h>
#include <stdlib.h>
#include "excerc.h"

int main(){
    int *v, **permutations;
    int alvo;
    v = calloc(MAX_SIZE,sizeof(int));
    /// permutations, é um ponteiro que armazena os ponteiros que comtem as respectivas permutacoes do ponteiro v.
    permutations = (int**)malloc(2000*sizeof(int)); /// obs, por algum motivo, o tammanho d vetor precisa ser pelo menos duas vezes maior,
    vetor_alocate(permutations, 720);

    escanear(v,MAX_SIZE);
    funcao_anagramas(v,MAX_SIZE,permutations);

    for(int i=0;i<720;i++){
            printf("\n");
        printar(permutations[i],MAX_SIZE);
    }
    return 0;
}
