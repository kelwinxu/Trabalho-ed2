#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "exerc3.h"
int main(){
    tabela *hash = NULL;
    FILE *arq;
    char str[100], comp[100], *strsave,*token;
    fgets(str,100,stdin);
    memcpy(comp,str,100);
    token = strtok_r(comp," ",&strsave);
    if(strcmp(token,"main")== 0){
    for(;;){
        menu(hash,arq,str);
        fgets(str,100,stdin);
    }
    }else{
    printf("comando invalido\niniciando caso de teste predefinido...\n");
    char str64[] = {"main criar 100 hash.txt\n"};
    char str128[] = {"main inserir hash.txt 15523483,kelwin zhao xu,engcomp,13314621,joel dutras,bcc,14323324,felipe martinez,arquitetura,12244534,gabriel dias,bci,15533467,gabriela amanda,medicina\n"};
    char str256[] = {"main remover hash.txt 15523483,133146211\n"};

    char str512[] = {"main buscar hash.txt 14323324,1003300\n"};
    menu(hash,arq,str64);
    menu(hash,arq,str128);
    menu(hash,arq,str256);
    menu(hash,arq,str512);
    }



    return 0;
}

