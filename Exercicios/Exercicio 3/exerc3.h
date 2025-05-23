#ifndef EXERC3_H_INCLUDED
#define EXERC3_H_INCLUDED
/// estrutura da tabela
typedef struct formulario* tabela;
typedef struct formulario aluno;

///criar arquivo txt tabela hash(hash.txt)
void *f_criararq(char *path);
///carrega arquivo ntxt na memoria  tabela hash(hash.txt)
void *f_carregaarq(char *path);
///criar tabela hash
tabela *f_criatabela(char tam[100]);
/// carrega a tabela na memoria
tabela *f_carregatabela(FILE *arq,tabela *Hash);
///insere na tabela hash que esta na memmoria
void f_ineserenatabela(tabela *Hash, char str[100],char tam[100]);
///insere tabela hash no arquivo txt
void f_inserehashnorquivo(tabela *Hash,FILE *arq, char *tam);
/// menu
void menu(tabela *Hash, FILE *arq);
#endif // EXERC3_H_INCLUDED
