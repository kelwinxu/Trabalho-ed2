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
    tam = tam-1;
    if(tam <0){
        return;
    }
    scanf("%d",&v[tam]);
    escanear(v,tam);
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
void F_OP(int op){
    switch (op){
    case 1:
    printf("/");
    break;
    case 2:
    printf("*");
    break;
    case 3:
    printf("+");
    break;
    case 4:
    printf("-");
    break;
    case 0:
    break;
    }
}
void F_ELEM(int a){
    if(a>0){
        printf(" %d ",a);
    }
}
void F_print(int v[6],int sinais[6]){
    for(int i=0;i<MAX_SIZE;i++){
        F_ELEM(v[i]);
        F_OP(sinais[i]);
    }
    printf("\n\n\n");
    for(int i=0;i<MAX_SIZE;i++){
        printf(" %d",v[i]);
    }
    printf("\n\n\n");
    for(int i=0;i<MAX_SIZE;i++){
        printf(" %d",sinais[i]);
    }
}

void check_operation(int **permutations, int iteracao, int valor){
    int comp;
    int *v = (int*)malloc(MAX_SIZE*sizeof(int));
    int *sinais = (int*)calloc(6,sizeof(int));
    if(iteracao<1){
        printf("--Nao existe solucao--");
        return;

    }
    v = permutations[iteracao-1];
    /*printar(elem,6);*/
    comp = v[0];
    comp = comp + v[1];
    if(v[1]>0){sinais[0]=3;}
    comp = comp - v[2];
    if(v[2]>0){sinais[1]=4;}

    if(comp>0 && v[3]>0){
        if(comp%v[3]== 0){
            comp = (comp/(v[3]));
            sinais[2]=1;
        }
    }
    if(comp>0 && v[4]>0){
        comp = (comp*(v[4]));
        sinais[3]=2;
    }

    if(v[5]>0){
        if(comp>0 && (comp+v[5])==valor){comp = comp + v[5];sinais[4]=3;}
        if(comp>0 && (comp-v[5])==valor){comp = comp - v[5];sinais[4]=4;}
        if(comp>0 && (comp%v[5])==0 && (comp/v[5])== valor){comp = (comp/v[5]);sinais[4]=1;}
        if(comp>0 && (comp*v[5])== valor){comp = (comp*v[5]);sinais[4]=2;}
    }
    if(comp == valor){
        printf("%d",comp);
        F_print(permutations[iteracao-1],sinais);
        return;
    }

    check_operation(permutations,iteracao-1,valor);

}

    if((comp + elem[5]) == valor){
        printf("((%d / %d )* %d + %d - %d)  + %d = %d ",elem[0],elem[1],elem[2],elem[3],elem[4],elem[5],valor);
        return;
    }
    check_operation(permutations,iteracao-1,valor);

}
