#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio1.h"

void trocar(char *a, char *b) { //funcao que o professor utilizou numa das aulas, no arquivo exEDA5 - backtracking
    char temp = *a;
    *a = *b;
    *b = temp;
}

// função recursiva para gerar permutações, inspirada na funcao que o professor fez em aula, no exEDA5 -backtracking, onde ele faz uma permutacao com backtracking
void permutar(char *vetor, int inicio, int fim, int *numeros, int valor_alvo, int k, int *nrosolucoes, int *nrochamadas) {

    (*nrochamadas)++;

    // como queremos uma solucao apenas, se uma solução já foi encontrada, para a recursão imediatamente.
    if (*nrosolucoes != 0) {
        return;
    }


    if (inicio == fim) {
        funcaoatribuirvalores(vetor, numeros, valor_alvo, k, nrosolucoes, nrochamadas);
    }
    else {
        for (int i = inicio; i <= fim; i++) {
            trocar(&vetor[inicio], &vetor[i]);
            permutar(vetor, inicio + 1, fim, numeros, valor_alvo, k, nrosolucoes, nrochamadas);

            // se a chamada recursiva acima encontrou uma solução, para o loop.
            if (*nrosolucoes != 0) {
                return;
            }

            trocar(&vetor[inicio], &vetor[i]);
        }
    }
}

int pega_indice(char letra) {
    if (letra >= 'A' && letra <= 'E') {
        return letra - 'A';  // colocamos letra menos A para obter o indice desejado para a nossa string
    }
    return -1; //se tudo der errado, retorna -1, ou seja, a letra nao estava entre A e E.
}

void funcaoatribuirvalores(char *vetorpermutado, int *numeros, int valor_alvo, int k, int *nrosolucoes, int *nrochamadas) {
    int nro1 = 0, nro2 = 0, nro3 = 0, nro4 = 0, nro5 = 0;
    int num_operandos = k - 1;

    for (int i = 0; i < num_operandos; i++) {
        char letra = vetorpermutado[i];
        int indice = pega_indice(letra);
        if (indice != -1) {
            switch (i) {
                case 0: nro1 = numeros[indice]; break;
                case 1: nro2 = numeros[indice]; break;
                case 2: nro3 = numeros[indice]; break;
                case 3: nro4 = numeros[indice]; break;
                case 4: nro5 = numeros[indice]; break;
            }
        }
    }

    if (*nrosolucoes == 0) {
        int i_inicial_operacoes = 1001;
        //apos termos obtido uma sequencia de numeros possivel, colocaremos essa sequencia na nossa funcao de embaralha-operacoes, para ver
        //se com essa sequencia, seria possivel ou nao achar a solucao.
        embaralha_operacoes(i_inicial_operacoes, nro1, nro2, nro3, nro4, nro5, valor_alvo, k, nrosolucoes, nrochamadas);
    }
}

//a funcao while recursivo vai servir para basicamente separarmos os valores da string que recebemos, alem de contar o tamanho de numeros na lista
int while_recursivo(char *valores, int numeros[20], int i, int *tam) {
    if (i >= 20) return 0;

    if (valores != NULL) {
        numeros[i] = atoi(valores);
        valores = strtok(NULL, ",");
        (*tam)++;
    } else {
        return 0;
    }
    return while_recursivo(valores, numeros, i + 1, tam);
}

//basicamente a funcao principal do nosso codigo, ele vai realizar as combinacoes de operacoes
void embaralha_operacoes(int i, int a,int b, int c,int d,int e,int valor_alvo, int k, int *nrosolucoes, int *nrochamadas){
//basicamente, a ideia sera a seguinte: vou chamar cada operacao por um numero inteiro, 1 para adicao, 2 subtracao,3 multiplicacao e 4 divisao, e a partir disso formar todos as combinacoes possiveis de ordens de operacoes
if (i>=4444){
return;}

(*nrochamadas)++;//mecanismo ja comentado anteriormente, se ja achamos uma solucao, a recursao para

    int unidademilhar,centena,dezena,unidade;
    int op1 = 0;
    int op2 = 0;
    int op3 = 0; int op4 = 0;
    char operador1[5]; char operador2[5]; char operador3[5]; char operador4[5];
    if (k==3){

    //como nao podemos repetir uma operacao, basicamente estes ifs vao garantir que vamos utilzar somente as operacoes uma unica vez.
    //a partir disso, ele verifica se seria possivel ou nao chegar no valor final com uma determinada sequencia de caracteres e operacoes.
if ((i/1000 == 1 || i/1000 == 2 || i/1000 == 3 || i/1000 == 4) && (i>1000 && i<10000)){
    if(((((i/100)-(i/1000)*10)) == 1 || (((i/100)-(i/1000)*10)) == 2 || (((i/100)-(i/1000)*10)) == 3 || (((i/100)-(i/1000)*10)) == 4)){
            if(((((i/10)-(i/100)*10)) == 1 || (((i/10)-(i/100)*10)) == 2 || (((i/10)-(i/100)*10)) == 3 || (((i/10)-(i/100)*10)) == 4)){
                    if(((((i/1)-(i/10)*10)) == 1 || (((i/1)-(i/10)*10)) == 2 || (((i/1)-(i/10)*10)) == 3 || (((i/1)-(i/10)*10)) == 4)){
                            unidademilhar = i/1000;
                            centena = (i/100)-((i/1000)*10);
                            dezena = (i/10)-((i/100)*10);
                            unidade = (i/1)-((i/10)*10);
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
                            if (unidademilhar == 4 && a%b == 0 && b != 0){
                                op1 = a/b;
                               strcpy(operador1, "/");
                            }
                            if (op1 == valor_alvo){
                                printf("(%d %s %d) = %d\nNumero de chamadas recursivas: %d\n", a,operador1,b,valor_alvo, *nrochamadas);
                                (*nrosolucoes)++;
                                return;
                            }

    }}}}
embaralha_operacoes(i+1,a,b,c,d,e,valor_alvo,k, nrosolucoes, nrochamadas);
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
                            if (unidademilhar == 4 && a%b == 0 && b != 0){
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
                            if (centena == 4 && op1%c == 0 && c!= 0){
                                op2 = op1/c;
                                strcpy(operador2, "/");
                            }
                            if (op2 == valor_alvo){
                            if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"x")== 0)||(strcmp(operador2,"/")== 0))){
                                printf("((%d %s %d) %s %d) = %d\nNumero de chamadas recursivas: %d\n", a,operador1,b,operador2, c,valor_alvo, *nrochamadas);
                                (*nrosolucoes)++;
                                return;
        }else{
                                printf("(%d %s %d %s %d) = %d\nNumero de chamadas recursivas: %d\n", a,operador1,b,operador2, c,valor_alvo,*nrochamadas);
                                (*nrosolucoes)++;
                                return;}
                            }

    }}}}
embaralha_operacoes(i+1,a,b,c,d,e,valor_alvo,k, nrosolucoes, nrochamadas);
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
                            if (unidademilhar == 4 && a%b == 0 && b != 0){
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
                            if (centena == 4 && op1%c == 0 && c != 0){
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
                            if (dezena == 4 && op2%d==0 && d != 0){
                                op3 = op2/d;
                                strcpy(operador3, "/");
                            }
                            if (op3 == valor_alvo){
                                if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"x")== 0)||(strcmp(operador2,"/")== 0))){
                                printf("((%d %s %d) %s %d %s %d) = %d\nNumero de chamadas recursivas: %d\n", a,operador1,b,operador2, c,operador3,d,valor_alvo,*nrochamadas);
                                (*nrosolucoes)++;
                                return;
        }
                            if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"+")== 0)||(strcmp(operador2,"-")== 0))&&((strcmp(operador3,"x")== 0)||(strcmp(operador3,"/")== 0))){
                                printf("((%d %s %d %s %d) %s %d) = %d\nNumero de chamadas recursivas: %d\n", a,operador1,b,operador2, c,operador3,d,valor_alvo,*nrochamadas);
                                (*nrosolucoes)++;
                                return;}

                                else{
                                printf("(%d %s %d %s %d %s %d) = %d\nNumero de chamadas recursivas: %d\n", a,operador1,b,operador2, c,operador3, d,valor_alvo, *nrochamadas);
                               (*nrosolucoes)++;
                                return;}


    }

    }}}}
embaralha_operacoes(i+1,a,b,c,d,e,valor_alvo,k, nrosolucoes, nrochamadas);
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
                            if (unidademilhar == 4 && a%b == 0 && b != 0){
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
                            if (centena == 4 && op1%c == 0 && c != 0){
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
                            if (dezena == 4 && op2%d==0 && d != 0){
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
                            if (unidade == 4 && op3%e ==0 && e != 0){
                                op4 = op3/e;
                                strcpy(operador4, "/");
                            }
                            if (op4 == valor_alvo){
                                if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"x")== 0)||(strcmp(operador2,"/")== 0))){
                                printf("((%d %s %d) %s %d %s %d %s %d) = %d\nNumero de chamadas recursivas: %d\n", a,operador1,b,operador2, c,operador3,d,operador4,e,valor_alvo, *nrochamadas);
                              (*nrosolucoes)++;
                                return;
        }
                            if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"+")== 0)||(strcmp(operador2,"-")== 0))&&((strcmp(operador3,"x")== 0)||(strcmp(operador3,"/")== 0))){
                                printf("((%d %s %d %s %d) %s %d %s %d) = %d\nNumero de chamadas recursivas: %d\n", a,operador1,b,operador2, c,operador3,d,operador4,e,valor_alvo, *nrochamadas);
                             (*nrosolucoes)++;
                                return;}
                            if (((strcmp(operador1,"+")== 0)||(strcmp(operador1,"-")== 0))&&((strcmp(operador2,"+")== 0)||(strcmp(operador2,"-")== 0))&&((strcmp(operador3,"+")== 0)||(strcmp(operador3,"-")== 0))&&((strcmp(operador4,"x")== 0)||(strcmp(operador4,"/")== 0))){
                                printf("((%d %s %d %s %d %s %d) %s %d) = %d\nNumero de chamadas recursivas: %d\n", a,operador1,b,operador2, c,operador3,d,operador4,e,valor_alvo, *nrochamadas);
                               (*nrosolucoes)++;
                                return;}

                                else{
                                printf("(%d %s %d %s %d %s %d %s %d) = %d\nNumero de chamadas recursivas: %d\n", a,operador1,b,operador2, c,operador3, d,operador4,e,valor_alvo, *nrochamadas);
                               (*nrosolucoes)++;
                                return;}


    }}}}
embaralha_operacoes(i+1,a,b,c,d,e,valor_alvo,k, nrosolucoes, nrochamadas);
}}}

