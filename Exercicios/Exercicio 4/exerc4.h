#ifndef EXERC4_H_INCLUDED
#define EXERC4_H_INCLUDED
#define MAX_SIZE 1000
/// estrutura da tabela
typedef struct formulario* tabela;
typedef struct formulario aluno;

////criar arquivo txt tabela hash(hash.txt)
void *f_criararq(char *path);
////qcarrega arquivo ntxt na memoria  tabela hash(hash.txt)
void *f_carregaarq(char *path);
////retorna o numero primo mais proximo
int f_numeros_primos(int n);
////funcao XOR
void *XOR(int **vbin,int maxdig);
//// printa tabela hash
void f_printa_hash(tabela *Hash, int tamhash);
////criar tabela hash
tabela *f_criatabela(int tamanho);
//// carrega a tabela na memoria
tabela *f_carregatabela(char path[100]);
////insere na tabela hash que esta na memmoria
tabela *f_ineserenatabela(char str[100]);
////insere tabela hash no arquivo txt
void f_inserehashnorquivo(tabela *Hash,char path[100]);
//// funcao hash
int f_chave(char nusp[MAX_SIZE],int mod);
//// busca na tabela hash
void f_buscahash(tabela *Hash,char input[MAX_SIZE]);
////remove um elemento da tabela
void f_removehash(tabela *Hash,char input[MAX_SIZE]);
//// menu
void menu(tabela *Hash, FILE *arq, char str[100]);
#endif // EXERC4_H_INCLUDED
