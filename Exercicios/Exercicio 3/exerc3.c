#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "exerc3.h"

/// estruttura dos elementos da tabela hash
struct formulario{ ///feito
    int indice;
    char *nusp;
    char *nome;
    char *curso;
};

///criar tabela hash
tabela *f_criatabela(char tam[100]){ ///feito
    char *endptr;
    int tamanho = strtol(tam,&endptr,10);
    tabela *hash = (tabela*)malloc(tamanho*sizeof(tabela));
    for(int i=0;i<tamanho;i++){
        aluno *al = (aluno*)malloc(sizeof(aluno));
        al->indice = i ;
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
tabela *f_carregatabela(FILE *arq,tabela *hash){ ///feito
    char str[1000], aux[100], **endptr,*token;
    int tam;
    fgets(str,100,arq);
    hash = f_criatabela(str);
    tam = strtol(str,endptr,10);
    for(int i=0;i<tam;i++){
    aluno *al = (aluno*)malloc(sizeof(aluno));
    fgets(str,100,arq);
    token = strtok(str,","); //indice
    al->indice = strtol(token,endptr,10);
    token = strtok(NULL,","); // nusp
    al->nusp = malloc(100*sizeof(char));
    memcpy(al->nusp,token,100);
    token = strtok(NULL,","); // nome
    al->nome = malloc(100*sizeof(char));
    memcpy(al->nome,token,100);
    token = strtok(NULL,"\n"); // curso
    al->curso = malloc(100*sizeof(char));
    memcpy(al->curso,token,100);
    hash[i] = al;
    /*printf("%d %s %s %s\n",al->indice,al->nusp,al->nome,al->curso);*/
    }
    return hash;
}

///insere na tabela hash
void f_ineserenatabela(tabela *hash,char str[100]){ ///processo
    char *token,*endptr, *tam;
    FILE *arq;
    int i=0;
    int chave=2;
    str[strcspn(str, "\n")] = 0;
    token = strtok(str," ");
    token = strtok(NULL," ");
    token = strtok(NULL," ");
        while(token != NULL){

            aluno *al = (aluno*)malloc(sizeof(aluno));
            al->indice = chave;

            token = strtok(NULL,",");/// nusp
            if(token != NULL){
            al->nusp = malloc(100*sizeof(char));
            memcpy(al->nusp,token,100);
            token = strtok(NULL,",");/// nome
            al->nome = malloc(100*sizeof(char));
            memcpy(al->nome,token,100);
            token = strtok(NULL,",");/// curso

            al->curso = malloc(100*sizeof(char));
            memcpy(al->curso,token,100);

            hash[chave] = al;
            printf("%d %s %s %s",al->indice,al->nusp,al->nome,al->curso);

            }
     }
}

///insere tabela hash no arquivo txt
void f_inserehashnorquivo(tabela *hash,FILE *arq, char *tam){///feito
    char **endptr;
    int tamanho = strtol(tam,endptr,10);
    aluno *no = (tabela*)malloc(sizeof(tabela));
    tam[strcspn(tam, "\n")] = 0;
    fprintf(arq,"%s\n",tam);
    if(no == NULL){return;}
    for(int i=0;i<tamanho;i++){
    aluno *aluno = (tabela*)malloc(sizeof(tabela));
    aluno = hash[i];
      fprintf(arq,"%d,",aluno->indice);
      fprintf(arq,"%s,",aluno->nusp);
      fprintf(arq,"%s,",aluno->nome);
      fprintf(arq,"%s\n",aluno->curso);
    }
}
///funcao hash chave
void chave(char nusp[100]){
char **endptr
int N = strtol(nusp, endptr,10);
int div =10;
for(int i=0;;i++){

}

}
///busca na tabela hash

///remove na tabela hash

///menu
void menu(tabela *hash, FILE *arq){
    char str[100],str_save[100];
    char *token;
    char *path, *endptr;
    int aux;
    fgets(str,100,stdin);
    memcpy(str_save,str,100);
    token = strtok(str," ");
    if(strcmp(token,"main")!= 0 ){
        return;
    }

    token = strtok(NULL," ");
    if(strcmp(token, "criar")==0){/// feito

        token = strtok(NULL," ");
        path = strtok(NULL," ");
        hash = f_criatabela(token);
        arq = f_criararq(path);
        if(arq == NULL){printf("hash ou arquivo vazio");return;}
        /// insere tamanho da tabela hash no arquivo texto
        /// insere tabela, NULL
        f_inserehashnorquivo(hash,arq,token);
        fclose(arq);
    }

    if(strcmp(token,"inserir")==0){/// processo

        path = strtok(NULL," ");
        arq = f_carregaarq(path);
        ///pega tabela do arquivo
        hash = f_carregatabela(arq,hash);

        fclose(arq);
        if(hash == NULL || arq == NULL){printf("hash ou arquivo vazio");return;}
        ///insira na tabela, usando a funcao hash
        f_ineserenatabela(hash,str_save);

        arq = f_carregaarq(path);

        fgets(str_save,100,arq);
        fseek(arq, 0, SEEK_SET);
        f_inserehashnorquivo(hash,arq,str_save);
        fclose(arq);

    }

    if(strcmp(token, "buscar")==0){

    }
    if(strcmp(token, "remover")==0){

    }
}
