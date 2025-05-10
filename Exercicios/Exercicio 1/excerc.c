#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excerc.h"
/// obs: printao vetor invertido, ou seja se 1,2,3,4,5,6 escaneia 6,5,4,3,2,1
void printar(int *v,int tam){
    tam= tam-1;
    if(tam <0){
        return;
    }
    printar(v, tam);
    printf("%d ",v[tam]);

}
/// obs: escaneia o vetor invertido, ou seja se 1,2,3,4,5,6 escaneia 6,5,4,3,2,1 não havera diferença nesse exercicio
void escanear(int *v,int tam){
    tam= tam-1;
    if(tam <0){
        return;
    }

    escanear(v,tam);
    scanf("%d",&v[tam]);
}
/// aloca, dentro de um pointeiro de ponteiro, os ponteiros de tamanho MAX_SIZE.
void **vetor_alocate(int **permutations, int tam){
    /// TIRAR O FOR, sem destruir a função
    for(int i=0;i<tam;i++){
    int *elem;
    elem = (int*)malloc(MAX_SIZE*sizeof(int));
    permutations[i] = elem;
    }

}
/// OBS: V_aux, variavel global é usada para contar iteracao da permutacao correspondente.
int V_aux =0;
void funcao_anagramas(int v[MAX_SIZE],int size,int **permutations){
    int aux;
    if (size == 1){
        /*printar(v,MAX_SIZE);
        printf(" %d",V_aux);*/
        memcpy(permutations[V_aux],v,MAX_SIZE*sizeof(int));
        V_aux++;
        return;
    }

    for(int i=0;i <size; i++){
        funcao_anagramas(v,size-1,permutations);
        if(size % 2 ==1){
            aux = v[0];
            v[0] = v[size-1];
            v[size-1] = aux;
        }else{
                aux = v[i];
                v[i] = v[size-1];
                v[size-1] = aux;

    }
    }
}
void check_operation(int **permutations, int iteracao, int valor){

    int *elem = (int*)malloc(MAX_SIZE*sizeof(int));

    if(iteracao<1){
        printf("--Nao existe solucao--");
        return;

    }
    elem = permutations[iteracao-1];
    /*printar(elem,6);*/
    int comp;
    comp = elem[0];

    if(elem[1]>0){
            if(comp%(elem[1])==0){
                comp = comp/(elem[1]);
                    if(elem[2]>0){comp = comp*(elem[2]);}

            }


    }

    comp = comp + elem[3];
    comp = comp - elem[4];

    if(elem[5]>0){
        if(comp*elem[5] == valor){
                printf("((%d / %d)* %d + %d - %d)* %d = %d ",elem[0],elem[1],elem[2],elem[3],elem[4],elem[5],valor);
                return;
            }
        if(comp%elem[5]==0){
            if(comp/elem[5] == valor ){
                printf("((%d / %d)* %d + %d - %d)/ %d = %d ",elem[0],elem[1],elem[2],elem[3],elem[4],elem[5],valor);
                return;
            }
        }
    }
    if((comp - elem[5]) == valor){
        printf("((%d / %d)* %d + %d - %d) - %d = %d ",elem[0],elem[1],elem[2],elem[3],elem[4],elem[5],valor);
        return;
    }

    if((comp + elem[5]) == valor){
        printf("((%d / %d )* %d + %d - %d)  + %d = %d ",elem[0],elem[1],elem[2],elem[3],elem[4],elem[5],valor);
        return;
    }
    check_operation(permutations,iteracao-1,valor);

}
