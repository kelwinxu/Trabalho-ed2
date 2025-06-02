#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio1.h"

int main(int argc, char *argv[]){
    int a,b,c,d,e,valor_alvo;
    //scanf("%d %d %d %d %d %d", &a,&b,&c,&d, &e, &valor_alvo);

    int i=1001;

int k; //tamanho do vetor a realizar as operacoes, ja com a resposta
//scanf("%d",&k);

char stringvalores[20];
char *valores;
char valorfinal[5];
int tamanho=0;

int numeros[20];

//scanf("%s",stringvalores);
//scanf("%s",valorfinal);


if (argc != 3 && argc != 1){
printf("erro!");
return 0;}

else if (argc==1)//nao foi informado valores para calcular, logo, serao executados os casos de exemplo;
{
char stringexemplo1[] = "3,4,2";
valor_alvo = 14;
strcpy(stringvalores, stringexemplo1);
tamanho = 0;
valores = strtok(stringvalores, ",");
while_recursivo(valores,numeros,0,&tamanho);
    a=0; b=0; c=0; d=0; e=0;
    if (tamanho >= 1) a = numeros[0];
    if (tamanho >= 2) b = numeros[1];
    if (tamanho >= 3) c = numeros[2];
    k=4;
    funcao(i, a, b, c, d, e, valor_alvo, k);

char stringexemplo2[] = "5,2,1,8";
valor_alvo = 16;
strcpy(stringvalores, stringexemplo2);
tamanho = 0;
valores = strtok(stringvalores, ",");
while_recursivo(valores,numeros,0,&tamanho);
    a=0; b=0; c=0; d=0; e=0;
    if (tamanho >= 1) a = numeros[0];
    if (tamanho >= 2) b = numeros[1];
    if (tamanho >= 3) c = numeros[2];
    if (tamanho >= 4) d = numeros[3];
    k=5;
    funcao(i, a, b, c, d, e, valor_alvo, k);
}

else if(argc==3){

strcpy(stringvalores, argv[1]);
strcpy(valorfinal, argv[2]);
valor_alvo = atoi(valorfinal);
valores = strtok(stringvalores,",");
while_recursivo(valores,numeros,0,&tamanho);
if (tamanho==2){
    a = numeros[0];
    b = numeros[1];
    k=3;
    funcao(i,a,b,c,d,e,valor_alvo,k);
}

if (tamanho==3){
    a = numeros[0];
    b = numeros[1];
    c = numeros[2];
    k=4;
    funcao(i,a,b,c,d,e,valor_alvo,k);
}

if (tamanho==4){
    a = numeros[0];
    b = numeros[1];
    c = numeros[2];
    d = numeros[3];
    k=5;
    funcao(i,a,b,c,d,e,valor_alvo,k);
}

if (tamanho==5){
    a = numeros[0];
    b = numeros[1];
    c = numeros[2];
    d = numeros[3];
    e = numeros[4];
    k=6;
    funcao(i,a,b,c,d,e,valor_alvo,k);
}

}
}

