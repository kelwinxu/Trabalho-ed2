#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exerc3.h"
int main(){
    tabela *hash = NULL;
    FILE *arq;
    char str[MAX_INPUT], comp[MAX_INPUT], *strsave,*token, *token2;
    int invalido=0;
    printf("------ excercicio3: implementacao de tabela hash ------\n -->criacao: main criar tamanho_da_tabela <path.txt> \n -->insercao: main inserir <path.txt> nusp,nome,curso,...,curso\n -->remocao:main remover <path.txt> nusp,nusp2,...,nuspn\n -->busca: main buscar <path.txt> nusp1,nusp2,..,nuspn\n ?->caracteristicas:funcao hash,espalhamento quadratico,espalhamento duplo,reespalhamento de tabela\n !->Obs:e possivel o conflito com antivirus, devido a manipulacao de arquivos\n");
    fgets(str,MAX_INPUT,stdin);
    strcpy(comp,str);
    token = NULL;
    token2 = NULL;
    token = strtok_r(comp," ",&strsave);
    token2 = strtok_r(NULL," ",&strsave);
    if(token != NULL && token2 != NULL){////se o input for valido
    if(strcmp(token2,"criar")== 0 || strcmp(token2,"inserir")== 0 || strcmp(token2,"remover")== 0 || strcmp(token2,"buscar")== 0){////se o input for valido
    if(strcmp(token,"main")== 0){
    for(;;){
        menu(hash,arq,str);
        fgets(str,100,stdin);   //// input
    }
    }else{invalido = 1;}
    }else{invalido = 1;}
    }else{invalido = 1;}
    if(invalido == 1){////se o input for invalido
        printf("----- Comando invalido, iniciando caso de teste predefinido... -----\n\n");
        char str64[MAX_INPUT] = {"main criar 11 hash.txt\n"};
        char str128[MAX_INPUT] = {"main inserir hash.txt 155234831,kelwin zhao xu,engcomp,13314621,joel dutras,bcc,14323324,felipe martinez,arquitetura,12244534,gabriel dias,bci,15533467,gabriela amanda,medicina\n"};
        char str256[MAX_INPUT] = {"main remover hash.txt 155234831,13314621\n"};

        char str512[MAX_INPUT] = {"main buscar hash.txt 14323324,1003300\n"};
        printf("Input 1: %s ",str64);
        printf("\n");
        printf("Input 2: %s ",str128);
        printf("\n");
        printf("Input 3: %s ",str256);
        printf("\n");
        printf("Input 4: %s ",str512);
        printf("\n");
        menu(hash,arq,str64);
        menu(hash,arq,str128);
        menu(hash,arq,str256);
        menu(hash,arq,str512);
        printf("\n");
        printf("-----------------------------------------------");
    }

    return 0;
}

