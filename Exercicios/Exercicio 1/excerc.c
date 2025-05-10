#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excerc.h"

void printar(int v[4],int i){
for(int k=0;k<i;k++){
    printf("\%d",v[k]);
}
printf("\n");
}

void funcao_anagramas(int v[6],int size){
    int aux;
    if (size == 1){
        printar(v,6);
        return;
    }

    for(int i=0;i <size; i++){
        funcao_anagramas(v,size-1);
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
