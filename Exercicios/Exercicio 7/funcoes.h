#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#define MAX_N 20 ///O programa simplemente da overflow entre 13-15
#define MAX_SOLUCOES 10000000
///Struct
typedef struct {
    int posicoes[MAX_N]; // Cada �ndice representa a linha e o valor representa a coluna da rainha
} Solucao;
///-------------FIM------------------
///------Variaveis Externas----------
extern int n; // Dimens�o do tabuleiro (NxN)
extern Solucao solucoes[MAX_SOLUCOES]; // Armazena solu��es �nicas
extern int total_solucoes; // Contador de solu��es �nicas encontradas
extern int chamadas_recursivas; // Contador de chamadas para estat�sticas
///-------------FIM------------------
///-------------Funcoes--------------
void sao_iguais_rec(int *a, int *b, int i, int *flag);
void copiar_identidade_rec(int *original, int *destino, int i);
/// Transforma��es geom�tricas do tabuleiro aplicadas por divis�o e conquista
void rotacao_90_divide_conquista(int *original, int *destino, int inicio, int fim);
void rotacao_180_divide_conquista(int *original, int *destino, int inicio, int fim);
void rotacao_270_divide_conquista(int *original, int *destino, int inicio, int fim);
void reflexo_horizontal_divide_conquista(int *original, int *destino, int inicio, int fim);
void reflexo_vertical_divide_conquista(int *original, int *destino, int inicio, int fim);
void diagonal_principal_divide_conquista(int *original, int *destino, int inicio, int fim);
void diagonal_secundaria_divide_conquista(int *original, int *destino, int inicio, int fim);
void gerar_transformacoes(int *original, int transformacoes[8][MAX_N]);
void compara_com_transformacoes(int sol_idx, int t_idx, int transformacoes[8][MAX_N], int *encontrado);
///============
void verifica_solucoes_existentes(int sol_idx, int total, int transformacoes[8][MAX_N], int *achou);
int solucao_e_unica(int *nova);
void exibir_solucao_rec(int *tabuleiro, int i);
void exibir_solucao(int *tabuleiro);
void resolver(int linha, int *tabuleiro);
int solucao_parcial_rec(int *tabuleiro, int linha, int k);
void tentar_colunas(int linha, int *tabuleiro, int coluna);
///-------------------------FIM----------------------------
#endif // FUNCOES_H_INCLUDED
