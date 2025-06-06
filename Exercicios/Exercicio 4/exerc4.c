#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exerc4.h"

/// estruttura dos elementos da tabela hash
struct formulario{
    int indice;
    char *nusp;
    char *nome;
    char *curso;
    aluno *prox; ////ponteiro ao priximo no
};

///criar tabela hash
tabela *f_criatabela(int tamanho){
    tabela *hash = (tabela*)malloc(tamanho*sizeof(tabela));
    if(hash== NULL){
            return NULL;
    }
    for(int i=0;i<tamanho;i++){
        aluno *al = (aluno*)malloc(sizeof(aluno));
        al->indice = i;
        al->curso = NULL;
        al->nome = NULL;
        al->nusp = NULL;
        al->prox = NULL;
        hash[i] = al;
    }
return hash;
}
///criar arquivo txt tabela hash(hash.txt)
void *f_criararq(char *path){
    FILE *arq;
    path = strtok(path,"\n");
    arq = fopen(path,"w+");
return arq;
}
///carrega arquivo ntxt na memoria  tabela hash(hash.txt)
void *f_carregaarq(char *path){
    char *path2;
    FILE *arq;
    path2 = strtok(path,"\n");
    arq = fopen(path,"r+");
return arq;
}

///carrega tabela hash do arquivo txt

tabela *f_carregatabela(char *path){
    char str[MAX_SIZE], *endptr,*token,*strsave;
    int tam, qtde;

    int indice;
    FILE *arq;
    tabela *hash;

    arq = f_carregaarq(path);

    fgets(str,MAX_SIZE,arq);
    tam = strtol(str,&endptr,10); ////tamamho da tabela
    fgets(str,MAX_SIZE,arq);
    qtde = strtol(str,&endptr,10);//// qtde de elementos na tabela
    hash = f_criatabela(tam);

    for(int i = 0; i < tam; i++) {
        char *strsave;

        fgets(str, MAX_SIZE, arq);                          // índice
        token = strtok_r(str,",", &strsave);                //// usa strtok_r para tokenizar os elementos, neste caso o indice
        aluno *alprox = (aluno*)malloc(sizeof(aluno));      //// aloca alprox
        alprox = hash[i];                                   //// guarda o enndereço de hash[i] em alrpox
        indice = strtol(token,&endptr,10);
        alprox->indice = indice;
        token = strtok_r(NULL,",",&strsave);                // strtok_r nusp, para a primeira iteraçao
        for(;;){
            alprox->indice = indice;                        // insere indice (desnecessario)
            alprox->nusp = malloc(MAX_SIZE*sizeof(char));   // aloca nusp
            strncpy(alprox->nusp, token, MAX_SIZE);         // insere nusp
            token = strtok_r(NULL, ",",&strsave);           // strtok_r nome
            alprox->nome = malloc(MAX_SIZE*sizeof(char));
            strncpy(alprox->nome, token, MAX_SIZE);
            token = strtok_r(NULL, ",\n",&strsave);        //  strtok_r curso
            alprox->curso = malloc(MAX_SIZE*sizeof(char));
            strncpy(alprox->curso, token, MAX_SIZE);
           /* printf("%d %s %s %s\n",hash[i]->indice,hash[i]->nusp,hash[i]->nome,hash[i]->curso);*/

            token = strtok_r(NULL,", \n",&strsave);          // strtok_r nusp
            if(token == NULL){                               //// verifica se o proximo token é null, como condiçao de parada
                alprox->prox = NULL;
                break;
            }
            alprox->prox = (aluno*)malloc(sizeof(aluno));   //// caso seja diferente de null, aloca o proximo elemento da lista
            alprox = alprox->prox;                          //// move alprox para o proximo elemento da lista

        }
    }
    fclose(arq);
    return hash;
}

///printa tabela hash
void f_printa_hash(tabela *hash, int tamhash){
    aluno *alprox;
    for(int i=0;i<tamhash;i++){
        alprox = hash[i];
        while(alprox != NULL){              //// enuanto alprox nao for null faça:
            if(alprox == NULL){break;}      //// se NULL , termina a iteraçao
            printf("%d %s %s %s\n",alprox->indice,alprox->nusp,alprox->nome,alprox->curso);
            alprox = alprox->prox;          //// move alprox para oproximo elememnto
        }
    }

}
/// funcao que devolve os numeros primos mais proximos
int f_numeros_primos(int n){
    int k;
    n = n+1;
    k=2;
        while (k <n ){
            if(n%k ==0){
            n = n+1;
            k=2;
        }
    k++;
    }
return n;
}
///insere na tabela hash

tabela *f_ineserenatabela(char str[MAX_INPUT]){
    char *token,*path,*endptr,*strsave, str2[MAX_INPUT];
    tabela *hash;
    FILE *arq;
    int tamhash,qtd;
    token = strtok_r(str," ",&strsave);     ////main
    token = strtok_r(NULL," ",&strsave);    //// inserir
    path = strtok_r(NULL," ",&strsave);     //// path
    arq = f_carregaarq(path);               //// aloca arquivo
    fgets(str2,MAX_INPUT,arq);
    tamhash = strtol(str2,&endptr,10);      //// tamanho da ta tabela
    fgets(str2,MAX_INPUT,arq);
    qtd = strtol(str2,&endptr,10);          //// quantidade de elementos na tabela

    /*hash = f_criatabela(tamhash);*/
    hash = f_carregatabela(path);           //// aloca tabela hash

        for(int i=0;i<tamhash;i++){
            int qtdelem,chave,aux;
            char *numerousp;
            char *nome;
            char *curso;
            aluno *al,*alprox;
            numerousp = strtok_r(NULL,",\n",&strsave);    // guarda nusp
            if(numerousp == NULL){break;}               // verifica se NULL
            nome = strtok_r(NULL,",\n",&strsave);         // guarda nome
            curso = strtok_r(NULL,",\n",&strsave);     // guarda curso
            chave = f_chave(nome,tamhash);              // obtem a chave
            if(chave > tamhash){return NULL ;}              // verifica se chave a é valida (descesserário pois N mod tamhash é feito)
            al = hash[chave];                           // obtem o elemento do indice

            if(strcmp(al->nome,"(null)")==0){           // verifica se o primeiro elemento esta vazio
                al->indice = chave;
                al->nusp = malloc(MAX_SIZE*sizeof(char));
                strncpy(al->nusp, numerousp, MAX_SIZE);
                al->nome = malloc(MAX_SIZE*sizeof(char));
                strncpy(al->nome,   nome, MAX_SIZE);
                al->curso = malloc(MAX_SIZE*sizeof(char));
                strncpy(al->curso, curso, MAX_SIZE);
            }else{                                               // caso contrario, verifica se ha mais elementos na lista.
                alprox = al;
                while(alprox->prox != NULL){                     // move alprox ao ultimo elemento da lista
                alprox = alprox->prox;
                }
                alprox->prox = (aluno*)malloc(sizeof(aluno));   //insere alprox no final dalista
                alprox = alprox->prox;
                alprox->prox = NULL;
                alprox->indice = chave;
                alprox->nusp = malloc(MAX_SIZE*sizeof(char));
                strncpy(alprox->nusp, numerousp, MAX_SIZE);
                alprox->nome = malloc(MAX_SIZE*sizeof(char));
                strncpy(alprox->nome,   nome, MAX_SIZE);
                alprox->curso = malloc(MAX_SIZE*sizeof(char));
                strncpy(alprox->curso, curso, MAX_SIZE);
            }
            qtd++;
            hash[chave]= al;                                    // insere a lista na tabel hash
        }
    fseek(arq,0,SEEK_SET);
    fprintf(arq,"%d\n",tamhash);                                //atualiza o valor da tabela
    fprintf(arq,"%d\n",qtd);                                    // atualiza o valor dos elelementos na tabela
    fclose(arq);
    return hash;
}


///insere tabela hash no arquivo txt
void f_inserehashnorquivo(tabela *hash,char *path){
    int tamhash, qtde;
    int qtdelem;
    FILE *arq;
    arq = f_carregaarq(path);
    fscanf(arq,"%d",&tamhash);          // coleta o tamanho da tabela
    fscanf(arq,"%d",&qtde);             // coleta a quantidade de elementos na tabela
    fclose(arq);                        // fecha o arquivo
    arq = f_criararq(path);             // cria um arquivo novo com mesmo path
    fprintf(arq,"%d\n",tamhash);        // inserir tamhas
    fprintf(arq,"%d\n",qtde);           // insere qtde
    for(int i=0;i<tamhash;i++){
        aluno *al = (aluno *)malloc(qtdelem * sizeof(aluno));
        al = hash[i];
        fprintf(arq,"%d,",al->indice);  //insere o indice da lista
        while(al != NULL){
                if(al->prox == NULL){   // se alista for de um elemento, insere barra n
                    fprintf(arq,"%s,",al->nusp);
                    fprintf(arq,"%s,",al->nome);
                    fprintf(arq,"%s\n",al->curso);
                    break;
                }else{                  // caso contrario insere ',' para manter cada lista saparada por barra n
                    fprintf(arq,"%s,",al->nusp);
                    fprintf(arq,"%s,",al->nome);
                    fprintf(arq,"%s,",al->curso);
                    }
                al = al->prox;
       }
    }
    fclose(arq);
}
///funcao xor  A B C  0 0 0  0 1 1  1 0 1  1 1 0   A != B entao 1 A == B entao 0
void *XOR(int **vbin,int maxdig){
int *xor = (int*)calloc(16,sizeof(int));
int j,aux;
j = 31;

for(int k=0;k<16;k++){
    xor[k] = vbin[0][k];
    aux = 0;
   /*printf(" %d ",xor[k]);*/
    for(int i=1;i<maxdig;i++){

        if(aux == 0){
            if(xor[k] != vbin[i][j]){
            aux = 1;
            xor[k] = 1;
            }else{xor[k]=0;aux = 1; }
        }else{
            if(xor[k] != vbin[i][k]){
            aux = 0;
            xor[k] = 1;
            }else{xor[k]=0;aux = 0; }
        }
    }
    /*printf("%d\n",xor[k]);*/
    j= j-1;

}
return xor;
}
///funcao hash chave
int f_chave(char nome[MAX_SIZE],int mod){
    char *endptr;
    int h1=0;
    int v[32];
    int v2[32];
    int soma=0;
    char str[MAX_SIZE];
    memcpy(str,nome,MAX_SIZE);          // guarda o nome
    for(int i =0;i<strlen(nome);i++){   // move cada carater 8 posicoes na tabela ascii, e soma em h1
        h1 = h1 + (nome[i]<<(i % 8));
    }
    for(int i=0;i<32;i++){              // transforma h1 em 32 bits
        v[i] = h1%2;
        h1 = h1/2;
    }
    memcpy(v2,v,32*sizeof(int));        // guarda em um vetor auxiliar
    for(int i=0;i<32;i++){              // move cada carater 13 posicoes
        if((i+13) > 31){
              v[i-19] = v2[i];
        }else{v[i+13] = v2[i];}

    }

    for(int i=0;i<32;i++){              // soma v[i] na tabela ascii vezes i^2, i= {1,2,3,..,n}
        soma = soma + (v[i])*(i*i);
    }
    return (soma%mod);                  // retorna soma mod tamamnho da tabela
}

///busca na tabela hash
void f_buscahash(char input[MAX_INPUT]){///feito
    char *token,*path,*endptr,tam[MAX_INPUT],*strsave,str[MAX_INPUT];
    int tamhash,indice,qtdelem;
    tabela *hash;
    FILE *arq;
    token = strtok_r(input," ",&strsave);       //// main
    token = strtok_r(NULL," ",&strsave);        //// buscar
    path = strtok_r(NULL," ",&strsave);         //// path


    arq = f_carregaarq(path);                   //// abre o arquivo
    if(arq == NULL){printf("erro no arquivo");return;}
    fgets(str,MAX_INPUT,arq);                    //// coleta tamanho da tabela
    tamhash = strtol(str,&endptr,10);
    hash = f_criatabela(tamhash);
    if(hash == NULL){printf("erro na tabela");return;}
    fseek(arq,0,SEEK_SET);                      //// reseta o ponteiro no arquivo

    hash = f_carregatabela(path);               //// carrega tabela hash do arquivo
    if(hash == NULL){printf("erro na tabela");return;}
    token = strtok_r(NULL,",\n",&strsave);
    while(token != NULL){
        if(token == NULL){break;}
        indice = f_chave(token,tamhash);        //// obtem a o indice, dada pela chave indicada
        aluno *al = (aluno*)malloc(qtdelem*sizeof(aluno));
        al = hash[indice];                      //// atrbui a al o endereço de hash[indice]
        if(strcmp(al->nome,"(null)")==0){
            token[strcspn(token,"\n")]= 0;
            printf("Busca: %s nao cadastrado\n",token);
        }else{
        while(al != NULL){
            printf("Busca: Nusp:%s, Nome:%s, Curso:%s\n",al->nusp,al->nome,al->curso);
            al = al->prox;
        }
        }

        token = strtok_r(NULL,",\n",&strsave); ////nome
    }

    free(hash);
    fclose(arq);
}
///remove na tabela hash
void f_removehash(char input[MAX_INPUT]){
    char *token,*path,*endptr,*strsave,str[MAX_INPUT];
    int tamhash,indice,qtde;
    tabela *hash;
    FILE *arq;
    token = strtok_r(input," ",&strsave);   //// main
    token = strtok_r(NULL," ",&strsave);    //// buscar
    path = strtok_r(NULL," ",&strsave);     //// path

    arq = f_carregaarq(path);               //// carrega arquivo
    if(arq == NULL){printf("erro no arquivo");return;}
    fgets(str,MAX_INPUT,arq);
    tamhash = strtol(str,&endptr,10);
    hash = f_criatabela(tamhash);
    if(arq == NULL){printf("erro na tabela");return;}
    fgets(str,MAX_INPUT,arq);
    qtde= strtol(str,&endptr,10);
    fseek(arq,0,SEEK_SET);
    hash = f_carregatabela(path);
    if(arq == NULL){printf("erro na tabela");return;}
    token = strtok_r(NULL,",\n",&strsave);
    while(token != NULL){           //// verifica token
        if(token == NULL){break;}
        indice = f_chave(token,tamhash); //// obtem a chave
        aluno *al = (aluno*)malloc(sizeof(aluno));
        al = hash[indice];              //// obtem a lista de de indice "indice"
        if(al->nome != NULL){
            if(strcmp(al->nome,"(null)")!=0){   //// verifica se ha outros elementos na lista, remove o primeiro, e reinsere a lista em hash
                printf("Remover: nome:%s \n",token);
                al->indice = indice;
                al->nome = NULL;
                al->nusp = NULL;
                al->curso = NULL;
                if(al->prox != NULL){
                    hash[indice] = al->prox;
                    free(al);
                    }else{
                        al->indice = indice;
                        al->nome = NULL;
                        al->nusp = NULL;
                        al->curso = NULL;
                        hash[indice] = al;
                        }
                qtde--;
            }else{printf("Remocao: nome:%s nao cadastrado\n",token);}
        }else{printf("Remocao: nome:%s nao cadastrado\n",token);}

        token = strtok_r(NULL,",\n",&strsave); ////nome

    }
    fprintf(arq,"%d\n",tamhash);
    fprintf(arq,"%d\n",qtde);
    fclose(arq);
    f_inserehashnorquivo(hash,path); //// atualiza o estado da tabela
    free(hash);
}
///menu
void menu(tabela *hash, FILE *arq, char str[MAX_INPUT]){
    char str2[MAX_INPUT],*strsave;
    char *token;
    char *path, *endptr;
    int aux;

    memcpy(str2,str,MAX_INPUT);
    token = strtok_r(str," ",&strsave);
    if(strcmp(token,"main")!= 0 ){
        return;

    }
    token = strtok_r(NULL," ",&strsave);
    if(strcmp(token, "criar")==0){

        token = strtok_r(NULL," ",&strsave);
        path = strtok_r(NULL,"  \n",&strsave);
        aux = strtol(token,&endptr,10);
        aux = f_numeros_primos(aux);
        arq = f_criararq(path);
        fprintf(arq,"%d\n",aux);
        fprintf(arq,"%d\n",0);
        fclose(arq);
        hash = f_criatabela(aux);
        f_inserehashnorquivo(hash,path);
        free(hash);

    }

    if(strcmp(token,"inserir")==0){
        path = strtok_r(NULL," ",&strsave);
        hash = f_carregatabela(path);
        arq = f_carregaarq(path);
        if(hash == NULL){printf("erro arquivo");return;}
        if(hash == NULL){printf("erro hash");return;}
        fclose(arq);
        hash = f_ineserenatabela(str2);
        f_inserehashnorquivo(hash,path);
        free(hash);

    }

    if(strcmp(token, "buscar")==0){
       f_buscahash(str2);

    }
    if(strcmp(token, "remover")==0){
        f_removehash(str2);

    }

}
