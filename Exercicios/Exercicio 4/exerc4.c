#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "exerc4.h"

/// estruttura dos elementos da tabela hash
struct formulario{ ///feito
    int indice;
    int qtdelem;
    char *nusp;
    char *nome;
    char *curso;
};

///criar tabela hash
tabela *f_criatabela(int tamanho){
    tabela *hash = (tabela*)malloc(tamanho*sizeof(tabela));
    for(int i=0;i<tamanho;i++){
        aluno *al = (aluno*)malloc(sizeof(aluno));
        al->indice = i ;
        al->qtdelem = 0;
        al->curso = NULL;
        al->nome = NULL;
        al->nusp = NULL;
        hash[i] = al;
    }
return hash;
}
///criar arquivo txt tabela hash(hash.txt)
void *f_criararq(char *path){ ///feito
    FILE *arq;
    path = strtok(path,"\n");
    arq = fopen(path,"w+");
return arq;
}
///carrega arquivo ntxt na memoria  tabela hash(hash.txt)
void *f_carregaarq(char *path){ ///feito
    char *path2;
    FILE *arq;
    path2 = strtok(path,"\n");
    arq = fopen(path,"r+");
return arq;
}
///carrega tabela hash do arquivo txt
tabela *f_carregatabela(char path[MAX_SIZE]){
    char str[MAX_SIZE],str2[MAX_SIZE], *endptr,*endptr2,*token;///////////////////
    int tam, qtde;
    int qtdelem;
    int indice;
    FILE *arq;
    tabela *hash;

    arq = f_carregaarq(path);

    fgets(str,MAX_SIZE,arq);
    tam = strtol(str,&endptr,10);
    fgets(str,MAX_SIZE,arq);
    qtde = strtol(str,&endptr,10);

    hash = f_criatabela(tam);
   for(int i = 0; i < tam; i++) {
        char *strsave;
        char *aux;
        fgets(str, MAX_SIZE, arq);
        token = strtok_r(str, ",", &strsave); // índice
        indice = strtol(token,&endptr,10);
        token = strtok_r(NULL, ",", &strsave); // quantidade de alunos na posição
        qtdelem = strtol(token, NULL, 10);
        if (qtdelem == 0){qtdelem = 1;}
        aluno *al = (aluno *)malloc(qtdelem * sizeof(aluno));
        al[0].indice = indice;
        al[0].qtdelem = strtol(token, NULL, 10);
        for (int k = 0; k < qtdelem; k++) {
            token = strtok_r(NULL, ",", &strsave); // nusp
            al[k].nusp = malloc(MAX_SIZE*sizeof(char));
            strncpy(al[k].nusp, token, MAX_SIZE);

            token = strtok_r(NULL, ",", &strsave); // nome
            al[k].nome = malloc(MAX_SIZE*sizeof(char));
            strncpy(al[k].nome, token, MAX_SIZE);

            token = strtok_r(NULL, ", \n", &strsave); // curso
            al[k].curso = malloc(MAX_SIZE*sizeof(char));
            strncpy(al[k].curso, token, MAX_SIZE);


        }
        hash[i] = al;
    }
    fclose(arq);
    return hash;
}
///printa tabela hash
void f_printa_hash(tabela *hash, int tamhash){
    char *endptr;
    int qtdelem;
    for(int i=0;i<tamhash;i++){
        qtdelem  = hash[i][0].qtdelem;
        if(qtdelem == 0){qtdelem = 1;}
        aluno *al = (aluno*)malloc(qtdelem*sizeof(aluno));
        al = hash[i];
        printf("%d %d ",al[0].indice,al[0].qtdelem);
        for(int k=0;k<qtdelem;k++){
            printf("%s %s %s \n",al[k].nusp,al[k].nome,al[k].curso);
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
tabela *f_ineserenatabela(char str[MAX_SIZE]){
    char *token,*path,*endptr,*endptr2,*strsave, str2[MAX_SIZE];
    tabela *hash;
    FILE *arq;
    int tamhash,qtd;
    token = strtok_r(str," ",&strsave);     ////main
    token = strtok_r(NULL," ",&strsave);    //// inserir
    path = strtok_r(NULL," ",&strsave);     //// path
    arq = f_carregaarq(path);
    fgets(str2,MAX_SIZE,arq);
    tamhash = strtol(str2,&endptr,10);
    fgets(str2,MAX_SIZE,arq);
    qtd = strtol(str2,&endptr,10);

    hash = f_criatabela(tamhash);
    hash = f_carregatabela(path);

            for(int i=0;i<tamhash;i++){
                int indice,qtdelem,chave,aux;
                char *numerousp;
                char *nome;
                char *curso;
                aluno *al;
                numerousp = strtok_r(NULL,",",&strsave);
                if(numerousp == NULL){break;}
                nome = strtok_r(NULL,",",&strsave);
                curso = strtok_r(NULL,", \n",&strsave);
                chave = f_chave(nome,tamhash);
                if(chave > tamhash){return 1;}
                qtdelem = hash[chave][0].qtdelem;
                al = hash[chave];
                aux = qtdelem;
                if(aux ==0){aux = 1;}
                al = (aluno*)realloc(al,(aux+1)*sizeof(aluno));
                al[qtdelem].nusp = malloc(MAX_SIZE*sizeof(char));
                al[qtdelem].nome = malloc(MAX_SIZE*sizeof(char));
                al[qtdelem].curso = malloc(MAX_SIZE*sizeof(char));
                strncpy(al[qtdelem].nusp, numerousp, MAX_SIZE);
                strncpy(al[qtdelem].nome,   nome, MAX_SIZE);
                strncpy(al[qtdelem].curso, curso, MAX_SIZE);
                qtdelem = qtdelem +1;
                al[0].qtdelem = qtdelem;
                al[0].indice = chave;
                qtd++;
                hash[chave]= al;
            }
    fseek(arq,0,SEEK_SET);
    fprintf(arq,"%d\n",tamhash);
    fprintf(arq,"%d\n",qtd);
    fclose(arq);
    return hash;
}

///insere tabela hash no arquivo txt
void f_inserehashnorquivo(tabela *hash,char path[MAX_SIZE]){///feito
    char **endptr, *endptr2;
    int tamhash, qtde;
    int qtdelem;
    FILE *arq;
    arq = f_carregaarq(path);
    fscanf(arq,"%d",&tamhash);
    fscanf(arq,"%d",&qtde);
    fclose(arq);
    arq = f_criararq(path);
    fprintf(arq,"%d\n",tamhash);
    fprintf(arq,"%d\n",qtde);
    for(int i=0;i<tamhash;i++){
        qtdelem = hash[i][0].qtdelem;
        if(qtdelem ==0){qtdelem = 1;}
        aluno *al = (aluno *)malloc(qtdelem * sizeof(aluno));
        al = hash[i];
        fprintf(arq,"%d,",al[0].indice);
        fprintf(arq,"%d,",al[0].qtdelem);
        for(int k=0;k<qtdelem;k++){
                if((k+1)==qtdelem){
                    fprintf(arq,"%s,",al[k].nusp);
                    fprintf(arq,"%s,",al[k].nome);
                    fprintf(arq,"%s\n",al[k].curso);
                    break;
                }else{
                    fprintf(arq,"%s,",al[k].nusp);
                    fprintf(arq,"%s,",al[k].nome);
                    fprintf(arq,"%s,",al[k].curso);
                    }
        }
    }
    fclose(arq);
}
///funcao xor  A B C  0 0 0  0 1 1  1 0 1  1 1 0   A != B entao 1 A == B entao 0
///                   n digitos
void *XOR(int **vbin,int maxdig){///feito
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
    memcpy(str,nome,MAX_SIZE);
    for(int i =0;i<strlen(nome);i++){
        h1 = h1 + (nome[i]<<(i % 8));
    }
    for(int i=0;i<32;i++){
        v[i] = h1%2;
        h1 = h1/2;
    }
    memcpy(v2,v,32*sizeof(int));
    for(int i=0;i<32;i++){
        if((i+13) > 31){
              v[i-19] = v2[i];
        }else{v[i+13] = v2[i];}

    }

    for(int i=0;i<32;i++){
        soma = soma + (v[i])*(i*i);
    }
    return (soma%mod);
}

///busca na tabela hash
void f_buscahash(tabela *hash,char input[MAX_SIZE]){///feito
    char *token,*path,*endptr,tam[MAX_SIZE],*strsave,str[100];
    int tamhash,indice,qtdelem;
    FILE *arq;
    token = strtok_r(input," ",&strsave);   //// main
    token = strtok_r(NULL," ",&strsave);    //// buscar
    path = strtok_r(NULL," ",&strsave);     //// path

    arq = f_carregaarq(path);
    fgets(str,MAX_SIZE,arq);
    tamhash = strtol(str,&endptr,10);
    fseek(arq,0,SEEK_SET);

    hash = f_carregatabela(path);
    token = strtok_r(NULL,", \n",&strsave);
    while(token != NULL){
        if(token == NULL){break;}
        indice = f_chave(token,tamhash);
        qtdelem  = hash[indice][0].qtdelem;
        if(qtdelem==0){printf("Nome: %s nao cadastrado\n",token);break;}
        aluno *al = (aluno*)malloc(qtdelem*sizeof(aluno));
        al = hash[indice];
        for(int k=0;k<qtdelem;k++){
            printf("%s %s %s \n",al[k].nusp,al[k].nome,al[k].curso);
        }
        token = strtok_r(NULL,", \n",&strsave); ////nome
    }

    fclose(arq);
}
///remove na tabela hash
void f_removehash(tabela *hash,char input[MAX_SIZE]){///feito
    char *token,*path,*endptr,tam[MAX_SIZE],*strsave,str[100];
    int tamhash,indice,qtdelem, qtde;
    FILE *arq;
    token = strtok_r(input," ",&strsave);   //// main
    token = strtok_r(NULL," ",&strsave);    //// buscar
    path = strtok_r(NULL," ",&strsave);     //// path

    arq = f_carregaarq(path);
    fgets(str,MAX_SIZE,arq);
    tamhash = strtol(str,&endptr,10);
    fgets(str,MAX_SIZE,arq);
    qtde= strtol(str,&endptr,10);
    fseek(arq,0,SEEK_SET);

    hash = f_carregatabela(path);
    token = strtok_r(NULL,", \n",&strsave);
    while(token != NULL){
        if(token == NULL){break;}
        indice = f_chave(token,tamhash);
        qtdelem  = hash[indice][0].qtdelem;
        if(qtdelem==0){printf("Nome: %s nao cadastrado\n",token);break;}
        aluno *al = (aluno*)malloc(sizeof(aluno));
        hash[indice] = al;
        token = strtok_r(NULL,", \n",&strsave); ////nome
        qtde--;
    }
    fprintf(arq,"%d\n",tamhash);
    fprintf(arq,"%d\n",qtde);
    fclose(arq);
    f_inserehashnorquivo(hash,path);
}
///menu
void menu(tabela *hash, FILE *arq, char str[MAX_SIZE]){
    char str2[MAX_SIZE],*strsave;
    char *token;
    char *path, *endptr;
    int aux;

    memcpy(str2,str,MAX_SIZE);
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

    }

    if(strcmp(token,"inserir")==0){/// processo
        path = strtok_r(NULL," ",&strsave);
        hash = f_carregatabela(path);
        if(hash == NULL){printf("hash vazia");return;}
        hash = f_ineserenatabela(str2);

        f_inserehashnorquivo(hash,path);

    }

    if(strcmp(token, "buscar")==0){
       f_buscahash(hash,str2);
    }
    if(strcmp(token, "remover")==0){
        f_removehash(hash,str2);
    }

}
