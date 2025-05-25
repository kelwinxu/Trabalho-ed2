#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "exerc3.h"

/// estruttura dos elementos da tabela hash
struct formulario{
    int indice;   // indica a posição na tabela
    char *nusp;
    char *nome;
    char *curso;
    int allocated;  // indica se a posição esta alocada
};

///criar tabela hash
tabela *f_criatabela(int tamanho){
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
void *f_carregaarq(char *path){
    char *path2;
    FILE *arq;
    path2 = strtok(path,"\n");
    arq = fopen(path,"r+");
return arq;
}
///carrega tabela hash do arquivo txt
tabela *f_carregatabela(char path[MAX_SIZE]){ // abre o arquivo, e obtem o tamnaho da tabela e a  quantidade de elementos nela, retornando hash carregada
    char str[MAX_SIZE], *endptr,*endptr2,*token;
    int tam, qtde;
    FILE *arq;
    tabela *hash;

    arq = f_carregaarq(path);       //aloca  a tabela hash

    fgets(str,MAX_SIZE,arq);        //tamanho da hash
    tam = strtol(str,&endptr,10);
    fgets(str,MAX_SIZE,arq);        // qtde de elementos
    qtde = strtol(str,&endptr,10);

    hash = f_criatabela(tam);

    for(int i=0;i<tam;i++){ // carrega cada elemento na hash
    aluno *al = (aluno*)malloc(sizeof(aluno));
    fgets(str,MAX_SIZE,arq);
    token = strtok(str,","); //indice
    al->indice = strtol(token,&endptr,10);
    token = strtok(NULL,","); // nusp
    al->nusp = malloc(MAX_SIZE*sizeof(char));
    memcpy(al->nusp,token,MAX_SIZE);
    token = strtok(NULL,","); // nome
    al->nome = malloc(MAX_SIZE*sizeof(char));
    memcpy(al->nome,token,MAX_SIZE);
    token = strtok(NULL,","); // curso
    al->curso = malloc(MAX_SIZE*sizeof(char));
    memcpy(al->curso,token,MAX_SIZE);
    token = strtok(NULL,",");
    al->allocated = strtol(token,&endptr2,10);

    hash[i] = al;

    /*printf("%d %s %s %s\n",al->indice,al->nusp,al->nome,al->curso);*/
    }
    fclose(arq);
    return hash;
}
///printa tabela hash
void f_printa_hash(tabela *hash, int tamhash){
    char *endptr;
    for(int i=0;i<tamhash;i++){
        printf("%d ",hash[i]->indice);
        printf("%s ",hash[i]->nusp);
        printf("%s ",hash[i]->nome);
        printf("%s ",hash[i]->curso);
        printf("%d\n",hash[i]->allocated);
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
///espahamento quadratico
int f_espalhmamentoquadratico(tabela *hash,unsigned int chave,unsigned int tamhash){
    unsigned int i=0;
    while (hash[chave]->allocated == 1){        //verifica se a a posicao indicada pela chave nao esta ocupada
        i++;
        unsigned int deslocamento = i*i;
        chave = abs((chave + deslocamento)%tamhash) ;
        while(chave >tamhash){
            chave =chave -tamhash;
        }
        /*printf("\n%d %d",chave,tamhash);*/

}
return chave;
}
///esapalhamento duplo
int f_espalhamentoduplo(tabela *hash,unsigned int chave,unsigned int tamhash){ ////////////
unsigned int i=0;
while (hash[chave]->allocated == 1 && i<2000){        //verifica se a a posicao indicada pela chave nao esta ocupada
    i++;
    unsigned int deslocamento = i*i;
    chave = abs((chave + deslocamento)%tamhash) + i*abs(1+i*(chave%(tamhash-1)));
    while(chave>=tamhash){chave = chave - tamhash;}
    /*printf("\nespalhamento duplo%d %d",chave,tamhash);*/

}
return chave;
}
///funcao que aplica re espalhamento da tabela hash
tabela *f_respalhamento(tabela *hash, int *tamhash){ // recebe o endereço de tamhash

    tabela *hash2;
    char *endptr;

    int aux = *tamhash;
    int indice;
    *tamhash = f_numeros_primos(*tamhash);  // obtem o novo tamamanho da hash
    hash2 = f_criatabela(*tamhash);
    for(int i=0;i<aux;i++){
        indice = hash[i]->indice;
        indice = f_espalhamentoduplo(hash2,indice,*tamhash);
        hash2[indice] = hash[i];

    }
    hash = f_criatabela(*tamhash);
    /*for(int i=0;i<tamamnho;i++){
    hash[i] = hash2[i];
    printf("\n   --%d %d  ",i,hash[i]->allocated);
    }*/
    return hash2;
}
///insere na tabela hash
tabela *f_ineserenatabela(char str[MAX_SIZE]){
    char *token,*path,*endptr,*endptr2,*strsave, str2[MAX_SIZE];
    tabela *hash;
    FILE *arq;
    int chave, tamhash,qtd;
    token = strtok_r(str," ",&strsave);     //main
    token = strtok_r(NULL," ",&strsave);    //inseirr
    path = strtok_r(NULL," ",&strsave);     //nome do arquivo path
    arq = f_carregaarq(path);
    fgets(str2,MAX_SIZE,arq);               // obtem o tamamnho da tabela
    tamhash = strtol(str2,&endptr,10);
    fgets(str2,MAX_SIZE,arq);               // qtde de elementos
    qtd = strtol(str2,&endptr,10);


    hash = f_criatabela(tamhash);           // aloca uma nova tabela
    hash = f_carregatabela(path);

        while(token != NULL){
            aluno *al = (aluno*)malloc(sizeof(aluno));      ////aloca strut do aluno
            token = strtok_r(NULL,",",&strsave);            //// nusp
            if(token != NULL){
                al->nusp = malloc(MAX_SIZE*sizeof(char));
                memcpy(al->nusp,token,MAX_SIZE);
                chave = f_chave(token,tamhash);             //// obtem o indice, retornado pela funcao hash f_chave
                al->indice = chave;
                token = strtok_r(NULL,",",&strsave);        //// nome
                al->nome = malloc(MAX_SIZE*sizeof(char));
                memcpy(al->nome,token,MAX_SIZE);
                token = strtok_r(NULL,", \n",&strsave);     //// curso
                al->curso = malloc(MAX_SIZE*sizeof(char));
                memcpy(al->curso,token,MAX_SIZE);
                al->allocated = 1;                          //// verifica se a posiçao ja contem um elemento
                qtd = qtd+1;                                //// aumenta a  quantidade de elementos na tabela

                    if(qtd<=(tamhash*0.7)){                 ////verifica qual funcao de espalhamento usar, e, se for necessario de re espalhamento
                        chave = f_espalhmamentoquadratico(hash,chave,tamhash);
                        /*printf("esaplhamento quadratico: %d\n ",chave);*/
                    }
                    if(qtd>(tamhash*0.7) && qtd<(tamhash*0.9)){
                        chave = f_espalhamentoduplo(hash,chave,tamhash);
                        /*printf("esaplhamento duplo :%d\n",chave);*/
                    }
                    if( qtd>=(tamhash*0.9)){
                        hash =  f_respalhamento(hash,&tamhash); ////recebe o tamanho da tabela hash tamhash, atualizado ao novo valor
                        chave = f_espalhamentoduplo(hash,chave,tamhash);
                }
                al->indice = chave;
                hash[chave] = al;
            /*printf("%d %s %s %s",al->indice,al->nusp,al->nome,al->curso);*/
        }
     }
    fseek(arq,0,SEEK_SET);
    fprintf(arq,"%d\n",tamhash);    //// insere no arquivo o novo tamanho tabela
    fprintf(arq,"%d\n",qtd);        //// insere no arquivo a nova quantidade de elementos
    fclose(arq);
    return hash;
}

///insere tabela hash no arquivo de texto
void f_inserehashnorquivo(tabela *hash,char path[MAX_SIZE]){    //// recebe a tabelha hash pre alocda, e nao necessariamente preenchida, e o nome do arquivo path
    char **endptr;
    int tamhash, qtde;
    FILE *arq;
    aluno *no = (tabela*)malloc(sizeof(tabela));
    arq = f_carregaarq(path);
    fscanf(arq,"%d",&tamhash);
    fscanf(arq,"%d",&qtde);
    fclose(arq);
    arq = f_criararq(path);         //// cria novamente o arquivo para inserir tabela hash, e evitar carateres sobrando ao final da tabela
    fprintf(arq,"%d\n",tamhash);    //// nota, pode haber comflito com o antivirus
    fprintf(arq,"%d\n",qtde);
    if(no == NULL){return;}
    for(int i=0;i<tamhash;i++){
    aluno *aluno = (tabela*)malloc(sizeof(tabela));
    aluno = hash[i];
      fprintf(arq,"%d,",aluno->indice);
      fprintf(arq,"%s,",aluno->nusp);
      fprintf(arq,"%s,",aluno->nome);
      fprintf(arq,"%s,",aluno->curso);
      fprintf(arq,"%d\n",aluno->allocated);
    }
    fclose(arq);
}
///funcao xor  A B C  0 0 0  0 1 1  1 0 1  1 1 0   A != B entao 1 A == B entao 0
void *XOR(int **vbin,int maxdig){                   //// funcao xor, aplicao xor ao primero bit do primeiro digito, com o ultimo bit do segundo digito,
    int *xor = (int*)calloc(16,sizeof(int));        ////e o resultado, aplica xor com o primeiro bit do tercer digito, e assim sequencialmente com todos os digitos

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
int f_chave(char nusp[MAX_SIZE],int mod){   ////recebe o numero usp em string, e o tamamnho da tabela
    char **endptr, **endptr2;
    int N = strtol(nusp,endptr,10);
    int vusp[MAX_SIZE];
    int tam=0;
    int **vbin;
    int *vxor = (int*)malloc(16*sizeof(int));
    int aux=0;
        for(int i=0;;i++){                  ////calcula o a quantidade de digitos apos a conversao string -> inteiro, dava para usar strlen kkkkk, mas calculando manualmente avita-se crashes, caso seja passado um char em nusp[] acidentalmente
            if((int)(N/(pow(10,i))) <= 0){
                break;
            }
            tam++;
        }
        for(int i=0;i<tam;i++){             ////separa os digitos
            char **endptr2;
            int aux;
            aux = strtol(&nusp[i],endptr2,10);
            vusp[i] =  (aux/pow(10,(tam-i-1)));
            /*printf("%d ",vusp[i]);*/
        }
        /*printf("\n");*/
        for(int i=0; i<tam;i++){            //// adiciona 1, e multiplica cada digito por numeros primos sucessivos, começando em 2
            vusp[i] = (vusp[i]+1)*(f_numeros_primos(i));
            /*printf("%d ",vusp[i]);*/
        }
        /*printf("\n");*/
        vbin = (int**)malloc((tam+2)*sizeof(int*));
        for(int i=0;i<(tam+2);i++){
            vbin[i] = (int*)calloc(32,sizeof(int));
        }
        for(int i=0;i<tam;i++){             //// calcula digito em binario de 32 bits, invertendo a posciçao 16 -> 16
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
        vxor = XOR(vbin,tam);               //// aplica a funcao xor
        for(int i=0;i<16;i++){
            aux = aux +(vxor[i])*(pow(2,i));
        }
        /*printf("\n%d",aux);*/
    return (aux%mod);                       //// retorna o resultado final aux mod(tamamnho da tabela)
}

///busca na tabela hash
void f_buscahash(tabela *hash,char input[MAX_SIZE]){    //// recebe hash, e os numeros usp
    char *token,*path,*endptr,tam[MAX_SIZE],*strsave,str[100];
    int tamhash,indice;
    FILE *arq;
    token = strtok_r(input," ",&strsave);   //// main
    token = strtok_r(NULL," ",&strsave);    //// buscar
    path = strtok_r(NULL," ",&strsave);     //// nome do arquivo path

    arq = f_carregaarq(path);               //// carrega o arquivo
    fgets(str,MAX_SIZE,arq);                //// obtem o tamamnho da tabela
    tamhash = strtol(str,&endptr,10);
    fseek(arq,0,SEEK_SET);                  //// reseta a posicao do ponteiro par ao começo do arquivo

    hash = f_carregatabela(path);           //// carrega tabela
    for(;;){                                //// busca na tabela
        token = strtok_r(NULL,", \n",&strsave);
        if(token == NULL){break;}
        /*printf("--%s--",token);*/
        indice = f_chave(token,tamhash);    //// obtem o indice, de f_chave, nota: se houverem colisões, a funcao busca apenas ira encontrar o primeiro elemento que
        if(hash[indice]->allocated == 1){   //// ocupou aquila posiçao, se houver alguma colisão, o segundo elemento apesar de estar na tabela nao sera encontrado.
        printf("Busca   - Nusp:%s, Nome:%s, Curso:%s -\n",hash[indice]->nusp,hash[indice]->nome,hash[indice]->curso);
        }else{printf("Busca   - Nusp:%s nao cadastrado\n",token);}

    }

    fclose(arq);
}
///remove na tabela hash
void f_removehash(tabela *hash,char input[MAX_SIZE]){
    char *token,*path,*endptr,*strsave,str[MAX_SIZE];
    int tamhash,qtde,indice;
    FILE *arq;
    token = strtok_r(input," ",&strsave);   //// main
    token = strtok_r(NULL," ",&strsave);    //// buscar
    path = strtok_r(NULL," ",&strsave);     //// nome do arquivo path
    arq = f_carregaarq(path);               //// carrega o arquivo
    fgets(str,MAX_SIZE,arq);                //// obtem o tamanho da tabela hash
    tamhash = strtol(str,&endptr,10);
    fgets(str,MAX_SIZE,arq);                //// obtem a qtde de elementos
    qtde = strtol(str,&endptr,10);
    fseek(arq,0,SEEK_SET);                  //// reseta a posicao do ponteiro par ao começo do arquivo

    hash = f_carregatabela(path);           //// carrega tabela
    for(;;){                                //// remove o elemento
        token = strtok_r(NULL,", \n",&strsave);
        if(token == NULL){break;}
        /*printf("--%s--",token);*/
        indice = f_chave(token,tamhash);    //// caso houver colisao, acontece o mesmo problema que na busca.
        if(hash[indice]->allocated == 1){
            printf("Remocao - Nusp:%s, Nome:%s, Curso:%s -\n",hash[indice]->nusp,hash[indice]->nome,hash[indice]->curso);
            hash[indice]->nusp= NULL;
            hash[indice]->nome= NULL;
            hash[indice]->curso = NULL;
            hash[indice]->allocated = 0;

            qtde = qtde -1;
        }else{printf("Remocao-Nusp:%s nao cadastrado\n",token);}

    }

    fprintf(arq,"%d\n",tamhash);
    fprintf(arq,"%d\n",qtde);
    f_inserehashnorquivo(hash,path);        //// insere a tabela sapos a remoção do elemento
    fclose(arq);
}
///menu
void menu(tabela *hash, FILE *arq, char str[MAX_SIZE]){ //// recebe un endereço de tabela, um endereço de arquivo, e um input --> str
    char str2[MAX_SIZE],*strsave;
    char *token;
    char *path, *endptr;
    int aux;

    memcpy(str2,str,MAX_SIZE);              //// string de seguraça, pois o strtok e strtok_r, modifican string original
    token = strtok_r(str," ",&strsave);     //// tokeniza o input
    if(strcmp(token,"main")!= 0 ){
        return;

    }
    token = strtok_r(NULL," ",&strsave);
    if(strcmp(token, "criar")==0){          //// caso main criar

        token = strtok_r(NULL," ",&strsave);
        path = strtok_r(NULL,"  \n",&strsave);
        aux = strtol(token,&endptr,10);
        aux = f_numeros_primos(aux);        //// obtem o numero primo mais proximo
        arq = f_criararq(path);             //// criar o arquivo
        fprintf(arq,"%d\n",aux);            //// insere o tamamnho da tabela,e  a qtde de elementos
        fprintf(arq,"%d\n",0);
        fclose(arq);
        hash = f_criatabela(aux);           //// cria tabela
        f_inserehashnorquivo(hash,path);    //// insere tabela no arquivo

    }

    if(strcmp(token,"inserir")==0){         //// caso main inserir
        path = strtok_r(NULL," ",&strsave);
        ///pega tabela do arquivo
        hash = f_carregatabela(path);

        if(hash == NULL){printf("hash vazia");return;}
        ///insira na tabela, usando a funcao hash
        hash = f_ineserenatabela(str2);
        f_inserehashnorquivo(hash,path);

    }

    if(strcmp(token, "buscar")==0){         //// caso main buscar
       f_buscahash(hash,str2);
    }
    if(strcmp(token, "remover")==0){        //// caso main remover
        f_removehash(hash,str2);
    }

}
