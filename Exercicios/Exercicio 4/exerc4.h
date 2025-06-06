#ifndef EXERC4_H_INCLUDED
#define EXERC4_H_INCLUDED
#define MAX_SIZE 100000
#define MAX_INPUT 100000
/// estrutura da tabela
typedef struct formulario* tabela;
typedef struct formulario aluno;


void *f_criararq(char *path);                       ////criar arquivo txt tabela hash(hash.txt)
void *f_carregaarq(char *path);                     ////qcarrega arquivo ntxt na memoria  tabela hash(hash.txt)
int f_numeros_primos(int n);                        ////retorna o numero primo mais proximo
void *XOR(int **vbin,int maxdig);                   ////funcao XOR
void f_printa_hash(tabela *Hash, int tamhash);      //// printa tabela hash
tabela *f_criatabela(int tamanho);                  ////criar tabela hash
tabela *f_carregatabela(char *path);                //// carrega a tabela na memoria
tabela *f_ineserenatabela(char str[MAX_INPUT]);     ////insere na tabela hash que esta na memmoria
void f_inserehashnorquivo(tabela *Hash,char *path); ////insere tabela hash no arquivo txt
int f_chave(char nusp[MAX_SIZE],int mod);           //// funcao hash
void f_buscahash(char input[MAX_SIZE]);             //// busca na tabela hash
void f_removehash(char input[MAX_SIZE]);            ////remove um elemento da tabela
//// menu
void menu(tabela *Hash, FILE *arq, char str[MAX_INPUT]);

#endif // EXERC4_H_INCLUDED
