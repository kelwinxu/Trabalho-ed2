#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio1.h"


int while_recursivo(char *valores, int numeros[20],int i, int *tam){
if (valores != NULL){
      numeros[i] = atoi(valores);
      valores = strtok(NULL, ",");
      (*tam)++;
   }else{return 0;}
   while_recursivo(valores,numeros,i+1,tam);
}

void funcao(int i, int a,int b, int c,int d,int e,int valor_alvo, int k){
//basicamente, a ideia sera a seguinte: vou chamar cada operacao por um numero inteiro, 1 para adicao, 2 subtracao,3 multiplicacao e 4 divisao, e a partir disso formar todos as combinacoes possiveis de ordens de operacoes
if (i>=4444){
printf("Nao foram encontradas combinacoes possiveis");
return;}

    int unidademilhar,centena,dezena,unidade;
    char operador1[5]; char operador2[5]; char operador3[5]; char operador4[5];
    if (k==3){

if ((i/1000 == 1 || i/1000 == 2 || i/1000 == 3 || i/1000 == 4) && (i>1000 && i<10000)){
    if(((((i/100)-(i/1000)*10)) == 1 || (((i/100)-(i/1000)*10)) == 2 || (((i/100)-(i/1000)*10)) == 3 || (((i/100)-(i/1000)*10)) == 4)){
            if(((((i/10)-(i/100)*10)) == 1 || (((i/10)-(i/100)*10)) == 2 || (((i/10)-(i/100)*10)) == 3 || (((i/10)-(i/100)*10)) == 4)){
                    if(((((i/1)-(i/10)*10)) == 1 || (((i/1)-(i/10)*10)) == 2 || (((i/1)-(i/10)*10)) == 3 || (((i/1)-(i/10)*10)) == 4)){
                            unidademilhar = i/1000;
                            centena = (i/100)-((i/1000)*10);
                            dezena = (i/10)-((i/100)*10);
                            unidade = (i/1)-((i/10)*10);
                            int op1,op2,op3;
                            if (unidademilhar == 1){
                                op1 = a+b;
                                strcpy(operador1, "+");
                            }
                            if (unidademilhar == 2){
                                op1 = a-b;
                                strcpy(operador1, "-");
                            }
                            if (unidademilhar == 3){
                                op1 = a*b;
                                strcpy(operador1, "x");
                            }
                            if (unidademilhar == 4 && a%b == 0 && a%b == 0){
                                op1 = a/b;
                               strcpy(operador1, "/");
                            }
                            if (op1 == valor_alvo){
                                printf("%d %s %d = %d\n", a,operador1,b,valor_alvo);
                                return;
                            }

    }}}}
funcao(i+1,a,b,c,d,e,valor_alvo,k);
}
    if (k==4){

if ((i/1000 == 1 || i/1000 == 2 || i/1000 == 3 || i/1000 == 4) && (i>1000 && i<10000)){
    if(((((i/100)-(i/1000)*10)) == 1 || (((i/100)-(i/1000)*10)) == 2 || (((i/100)-(i/1000)*10)) == 3 || (((i/100)-(i/1000)*10)) == 4)){
            if(((((i/10)-(i/100)*10)) == 1 || (((i/10)-(i/100)*10)) == 2 || (((i/10)-(i/100)*10)) == 3 || (((i/10)-(i/100)*10)) == 4)){
                    if(((((i/1)-(i/10)*10)) == 1 || (((i/1)-(i/10)*10)) == 2 || (((i/1)-(i/10)*10)) == 3 || (((i/1)-(i/10)*10)) == 4)){
                            unidademilhar = i/1000;
                            centena = (i/100)-((i/1000)*10);
                            dezena = (i/10)-((i/100)*10);
                            unidade = (i/1)-((i/10)*10);
                            int op1,op2,op3;
                            if (unidademilhar == 1){
                                op1 = a+b;
                                strcpy(operador1, "+");
                            }
                            if (unidademilhar == 2){
                                op1 = a-b;
                                strcpy(operador1, "-");
                            }
                            if (unidademilhar == 3){
                                op1 = a*b;
                                strcpy(operador1, "x");
                            }
                            if (unidademilhar == 4 && a%b == 0 && a%b == 0){
                                op1 = a/b;
                               strcpy(operador1, "/");
                            }
                            if (centena == 1){
                                op2 = op1+c;
                                strcpy(operador2, "+");
                            }
                            if (centena == 2){
                                op2 = op1-c;
                               strcpy(operador2, "-");
                            }
                            if (centena == 3){
                                op2 = op1*c;
                                strcpy(operador2, "x");
                            }
                            if (centena == 4 && op1%c == 0 && op1%c == 0){
                                op2 = op1/c;
                                strcpy(operador2, "/");
                            }
                            if (op2 == valor_alvo){
                            if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"x")== 0)||(strcmp(operador2,"/")== 0))){
                                printf("(%d %s %d) %s %d = %d\n", a,operador1,b,operador2, c,valor_alvo);
                                return 0;
        }else{
                                printf("%d %s %d %s %d = %d\n", a,operador1,b,operador2, c,valor_alvo);
                                return;}
                            }

    }}}}
funcao(i+1,a,b,c,d,e,valor_alvo,k);
}
    if (k==5){

if ((i/1000 == 1 || i/1000 == 2 || i/1000 == 3 || i/1000 == 4) && (i>1000 && i<10000)){
    if(((((i/100)-(i/1000)*10)) == 1 || (((i/100)-(i/1000)*10)) == 2 || (((i/100)-(i/1000)*10)) == 3 || (((i/100)-(i/1000)*10)) == 4)){
            if(((((i/10)-(i/100)*10)) == 1 || (((i/10)-(i/100)*10)) == 2 || (((i/10)-(i/100)*10)) == 3 || (((i/10)-(i/100)*10)) == 4)){
                    if(((((i/1)-(i/10)*10)) == 1 || (((i/1)-(i/10)*10)) == 2 || (((i/1)-(i/10)*10)) == 3 || (((i/1)-(i/10)*10)) == 4)){
                            unidademilhar = i/1000;
                            centena = (i/100)-((i/1000)*10);
                            dezena = (i/10)-((i/100)*10);
                            unidade = (i/1)-((i/10)*10);
                            int op1,op2,op3;
                            if (unidademilhar == 1){
                                op1 = a+b;
                                strcpy(operador1, "+");
                            }
                            if (unidademilhar == 2){
                                op1 = a-b;
                                strcpy(operador1, "-");
                            }
                            if (unidademilhar == 3){
                                op1 = a*b;
                                strcpy(operador1, "x");
                            }
                            if (unidademilhar == 4 && a%b == 0){
                                op1 = a/b;
                               strcpy(operador1, "/");
                            }
                            if (centena == 1){
                                op2 = op1+c;
                                strcpy(operador2, "+");
                            }
                            if (centena == 2){
                                op2 = op1-c;
                               strcpy(operador2, "-");
                            }
                            if (centena == 3){
                                op2 = op1*c;
                                strcpy(operador2, "x");
                            }
                            if (centena == 4 && op1%c == 0){
                                op2 = op1/c;
                                strcpy(operador2, "/");
                            }
                            if (dezena == 1){
                                op3 = op2+d;
                               strcpy(operador3, "+");
                            }
                            if (dezena == 2){
                                op3 = op2-d;
                                strcpy(operador3, "-");
                            }
                            if (dezena == 3){
                                op3 = op2*d;
                                strcpy(operador3, "x");
                            }
                            if (dezena == 4 && op2%d==0 && op2%d==0){
                                op3 = op2/d;
                                strcpy(operador3, "/");
                            }
                            if (op3 == valor_alvo){
                                if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"x")== 0)||(strcmp(operador2,"/")== 0))){
                                printf("(%d %s %d) %s %d %s %d = %d\n", a,operador1,b,operador2, c,operador3,d,valor_alvo);
                                return;
        }
                            if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"+")== 0)||(strcmp(operador2,"-")== 0))&&((strcmp(operador3,"x")== 0)||(strcmp(operador3,"/")== 0))){
                                printf("(%d %s %d %s %d) %s %d = %d\n", a,operador1,b,operador2, c,operador3,d,valor_alvo);
                                return;}

                                else{
                                printf("%d %s %d %s %d %s %d = %d\n", a,operador1,b,operador2, c,operador3, d,valor_alvo);
                                return;}


    }

    }}}}
funcao(i+1,a,b,c,d,e,valor_alvo,k);
}
    if (k==6){
if ((i/1000 == 1 || i/1000 == 2 || i/1000 == 3 || i/1000 == 4) && (i>1000 && i<10000)){
    if(((((i/100)-(i/1000)*10)) == 1 || (((i/100)-(i/1000)*10)) == 2 || (((i/100)-(i/1000)*10)) == 3 || (((i/100)-(i/1000)*10)) == 4)){
            if(((((i/10)-(i/100)*10)) == 1 || (((i/10)-(i/100)*10)) == 2 || (((i/10)-(i/100)*10)) == 3 || (((i/10)-(i/100)*10)) == 4)){
                    if(((((i/1)-(i/10)*10)) == 1 || (((i/1)-(i/10)*10)) == 2 || (((i/1)-(i/10)*10)) == 3 || (((i/1)-(i/10)*10)) == 4)){
                            unidademilhar = i/1000;
                            centena = (i/100)-((i/1000)*10);
                            dezena = (i/10)-((i/100)*10);
                            unidade = (i/1)-((i/10)*10);
                            int op1,op2,op3,op4;
                            if (unidademilhar == 1){
                                op1 = a+b;
                                strcpy(operador1, "+");
                            }
                            if (unidademilhar == 2){
                                op1 = a-b;
                                strcpy(operador1, "-");
                            }
                            if (unidademilhar == 3){
                                op1 = a*b;
                                strcpy(operador1, "x");
                            }
                            if (unidademilhar == 4 && a%b == 0){
                                op1 = a/b;
                               strcpy(operador1, "/");
                            }
                            if (centena == 1){
                                op2 = op1+c;
                                strcpy(operador2, "+");
                            }
                            if (centena == 2){
                                op2 = op1-c;
                               strcpy(operador2, "-");
                            }
                            if (centena == 3){
                                op2 = op1*c;
                                strcpy(operador2, "x");
                            }
                            if (centena == 4 && op1%c == 0){
                                op2 = op1/c;
                                strcpy(operador2, "/");
                            }
                            if (dezena == 1){
                                op3 = op2+d;
                               strcpy(operador3, "+");
                            }
                            if (dezena == 2){
                                op3 = op2-d;
                                strcpy(operador3, "-");
                            }
                            if (dezena == 3){
                                op3 = op2*d;
                                strcpy(operador3, "x");
                            }
                            if (dezena == 4 && op2%d==0){
                                op3 = op2/d;
                                strcpy(operador3, "/");
                            }
                            if (unidade == 1){
                                op4 = op3+e;
                                strcpy(operador4, "+");
                            }
                            if (unidade == 2){
                                op4 = op3-e;
                                strcpy(operador4, "-");
                            }
                            if (unidade == 3){
                                op4 = op3*e;
                                strcpy(operador4, "x");
                            }
                            if (unidade == 4 && op3%e ==0){
                                op4 = op3/e;
                                strcpy(operador4, "/");
                            }
                            if (op4 == valor_alvo){
                                if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"x")== 0)||(strcmp(operador2,"/")== 0))){
                                printf("(%d %s %d) %s %d %s %d %s %d = %d\n", a,operador1,b,operador2, c,operador3,d,operador4,e,valor_alvo);
                                return;
        }
                            if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"+")== 0)||(strcmp(operador2,"-")== 0))&&((strcmp(operador3,"x")== 0)||(strcmp(operador3,"/")== 0))){
                                printf("(%d %s %d %s %d) %s %d %s %d = %d\n", a,operador1,b,operador2, c,operador3,d,operador4,e,valor_alvo);
                                return;}
                            if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"+")== 0)||(strcmp(operador2,"-")== 0))&&((strcmp(operador3,"+")== 0)||(strcmp(operador3,"-")== 0))&&((strcmp(operador4,"x")== 0)||(strcmp(operador4,"/")== 0))){
                                printf("(%d %s %d %s %d %s %d) %s %d = %d\n", a,operador1,b,operador2, c,operador3,d,operador4,e,valor_alvo);
                                return;}

                                else{
                                printf("%d %s %d %s %d %s %d %s %d = %d\n", a,operador1,b,operador2, c,operador3, d,operador4,e,valor_alvo);
                                return;}


    }}}}
funcao(i+1,a,b,c,d,e,valor_alvo,k);
}}}

