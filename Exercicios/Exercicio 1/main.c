#include <stdio.h>
#include <stdlib.h>
#include "excerc.h"
int main(){
    int *v;
    int alvo;
    v = calloc(10,sizeof(int));
    for(int i=0;i<6;i++){
        scanf("%d",&v[i]);
    }
    scanf("%d",&alvo);
    funcao_anagramas(v,6);
    return 0;
}
