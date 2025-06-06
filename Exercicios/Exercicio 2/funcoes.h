#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
int ver_decrescente(int lista[], int esquerda, int direita);
int encontrar_primeira_ocorrencia(int lista[], int esquerda, int direita, int valor, int decrescente);
void buscar_valores_repetidos(int lista[], int tamanho, int valores[], int qtd_valores, int resultado[][2]);
void executar_busca(int lista[], int tamanho, int valores[], int qtd_valores);
int parse_lista(char *str, int arr[]);
#endif // FUNCOES_H_INCLUDED
