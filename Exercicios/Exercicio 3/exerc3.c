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
    int allocated;
};

///criar tabela hash
tabela *f_criatabela(char *tam){ ///feito
    char *endptr;
    int tamanho = strtol(tam,&endptr,10);
    sprintf(tam,"%d",tamanho);
    tabela *hash = (tabela*)malloc(tamanho*sizeof(tabela));
    for(int i=0;i<tamanho;i++){
        aluno *al = (aluno*)malloc(sizeof(aluno));
        al->indice = i ;
        al->curso = NULL;
        al->nome = NULL;
        al->nusp = NULL;
        al->allocated = 0;
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
    char str[1000],str2[100], aux[100], **endptr,**endptr2,*token;///////////////////
    int tam;
    fgets(str,100,arq);
    fgets(str2,100,arq);///////////////////
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
    token = strtok(NULL,","); // curso
    al->curso = malloc(100*sizeof(char));
    memcpy(al->curso,token,100);
    token = strtok(NULL,"\n");
    al->allocated = strtol(token,endptr2,10);
    hash[i] = al;
    /*printf("%d %s %s %s\n",al->indice,al->nusp,al->nome,al->curso);*/
    }

    return hash;
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
///espahamento quadratico
int f_espalhmamentoquadratico(tabela *hash,int chave,char tam[100]){///feito

char *endptr;
int tamhash = strtol(tam,&endptr,10);
int i=0;
while (hash[chave]->allocated == 1){
    i++;
    int deslocamento = i*i;
    chave = abs((chave + deslocamento)%tamhash) ;
    /*printf("\n%d %d",chave,tamhash);*/

}
return chave;
}
///esapalhamento duplo
void f_espalhamentoduplo(){




}
///insere na tabela hash
void f_ineserenatabela(tabela *hash,char str[100],char tam[100], char *qtd_elem){ ///processo precisa alguma condicao caso a tabela esteja cheia///////////////////
    char *token,*endptr,*endptr2;
    FILE *arq;
    int i=0;
    int chave, hashtam,qtd;
    str[strcspn(str, "\n")] = 0;
    token = strtok(str," ");
    token = strtok(NULL," ");
    token = strtok(NULL," ");
    hashtam = strtol(tam,endptr,10);
    qtd = strtol(qtd_elem,endptr,10);
            while(token != NULL){

            aluno *al = (aluno*)malloc(sizeof(aluno));


            token = strtok(NULL,",");/// nusp
            if(token != NULL){
            al->nusp = malloc(100*sizeof(char));
            memcpy(al->nusp,token,100);
            chave = f_chave(token,tam);
            al->indice = chave;
            token = strtok(NULL,",");/// nome
            al->nome = malloc(100*sizeof(char));
            memcpy(al->nome,token,100);
            token = strtok(NULL,",");/// curso
            al->curso = malloc(100*sizeof(char));
            memcpy(al->curso,token,100);
            al->allocated = 1;
            qtd++;
            if(qtd> (hashtam*0.7)){
                printf("70 ocupado %d",qtd);
            }
            chave = f_espalhmamentoquadratico(hash,chave,tam);
            al->indice = chave;
            hash[chave] = al;

            /*printf("%d %s %s %s",al->indice,al->nusp,al->nome,al->curso);*/

            }
     }
     sprintf(qtd_elem,"%d",qtd);
}

///insere tabela hash no arquivo txt
void f_inserehashnorquivo(tabela *hash,FILE *arq, char *tam,char qtd_elem[100]){///feito///////////////////
    char **endptr;
    int tamanho = strtol(tam,endptr,10);
    aluno *no = (tabela*)malloc(sizeof(tabela));
    tam[strcspn(tam,"\n")] = 0;
    fprintf(arq,"%s\n",tam);

    fprintf(arq,"%s\n",qtd_elem);///////////////////
    if(no == NULL){return;}
    for(int i=0;i<tamanho;i++){
    aluno *aluno = (tabela*)malloc(sizeof(tabela));
    aluno = hash[i];
      fprintf(arq,"%d,",aluno->indice);
      fprintf(arq,"%s,",aluno->nusp);
      fprintf(arq,"%s,",aluno->nome);
      fprintf(arq,"%s,",aluno->curso);
      fprintf(arq,"%d\n",aluno->allocated);
    }
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
int f_chave(char nusp[100],char tamanho_hash[100]){
char **endptr, **endptr2;
int N = strtol(nusp,endptr,10);
int vusp[100];
int tam=0;
int **vbin;
int *vxor = (int*)malloc(16*sizeof(int));
int aux=0;
int mod = strtol(tamanho_hash,endptr2,10);
    for(int i=0;;i++){

        if((int)(N/(pow(10,i))) <= 0){
            break;
        }
        tam++;

    }
    for(int i=0;i<tam;i++){
        char **endptr2;
        int aux;
        aux = strtol(&nusp[i],endptr2,10);
        vusp[i] =  (aux/pow(10,(tam-i-1)));
        /*printf("%d ",vusp[i]);*/
    }
    /*printf("\n");*/
    for(int i=0; i<tam;i++){
        vusp[i] = (vusp[i]+1)*(f_numeros_primos(i));
        /*printf("%d ",vusp[i]);*/
    }
    /*printf("\n");*/
    vbin = (int**)malloc((tam+2)*sizeof(int*));
    for(int i=0;i<(tam+2);i++){
        vbin[i] = (int*)calloc(32,sizeof(int));
    }
    for(int i=0;i<tam;i++){ /// calcula o binario de 32 bits invertido
        int *digito,aux;
        digito = vbin[i];
        aux = vusp[i];
        /*printf("%d  ",aux);*/
        for(int k=0;k<32;k++){
            digito[31-k] = (aux)%2;
            if(aux>0){aux = aux/2;}
            /*printf("%d",digito[k]);*/
        }
       /*printf("\n");*/

    }
    vxor = XOR(vbin,tam);
    for(int i=0;i<16;i++){
        aux = aux +(vxor[i])*(pow(2,i));
    }
    /*printf("\n%d",aux);*/
    return (aux%mod);
}
///busca na tabela hash

///remove na tabela hash

///menu
void menu(tabela *hash, FILE *arq){
    char str[100],str_save[100],str3[100];
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
        aux = strtol(token,endptr,10);
        aux = f_numeros_primos(aux);
        sprintf(token,"%d",aux);
        hash = f_criatabela(token);
        arq = f_criararq(path);
        if(arq == NULL){printf("hash ou arquivo vazio");return;}
        /// insere tamanho da tabela hash no arquivo texto
        /// insere tabela, NULL

        f_inserehashnorquivo(hash,arq,token,"0");///////////////////
        fclose(arq);
    }

    if(strcmp(token,"inserir")==0){/// processo

        path = strtok(NULL," ");
        arq = f_carregaarq(path);
        ///pega tabela do arquivo
        hash = f_carregatabela(arq,hash);
        fseek(arq, 0, SEEK_SET);
        if(hash == NULL || arq == NULL){printf("hash ou arquivo vazio");return;}
        ///insira na tabela, usando a funcao hash
        char str4[100];///////////////////
        fscanf(arq,"%s",str3);
        fscanf(arq,"%s",str4);
        f_ineserenatabela(hash,str_save,str3,&str4);///////////////////
        fclose(arq);
        arq = f_criararq(path);
        fseek(arq, 0, SEEK_SET);
        f_inserehashnorquivo(hash,arq,str3,str4);///////////////////
        fclose(arq);

    }

    if(strcmp(token, "buscar")==0){
    }
    if(strcmp(token, "remover")==0){

    }
}
