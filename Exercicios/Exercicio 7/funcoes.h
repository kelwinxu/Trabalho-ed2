#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#define MAX_N 20
#define MAX_SOLUCOES 100000

typedef struct {
    int posicoes[MAX_N];
} Solucao;

extern Solucao solucoes[MAX_SOLUCOES];
extern int total_solucoes;

void sao_iguais_rec(int *a, int *b, int i, int *flag);
void copiar_identidade_rec(int *original, int *destino, int i);
void rotacao_90_rec(int *original, int *destino, int i);
void rotacao_180_rec(int *original, int *destino, int i);
void rotacao_270_rec(int *original, int *destino, int i);
void reflexo_horizontal_rec(int *original, int *destino, int i);
void reflexo_vertical_rec(int *original, int *destino, int i);
void diagonal_principal_rec(int *original, int *destino, int i);
void diagonal_secundaria_rec(int *original, int *destino, int i);
void gerar_transformacoes(int *original, int transformacoes[8][MAX_N]);
void compara_com_transformacoes(int sol_idx, int t_idx, int transformacoes[8][MAX_N], int *encontrado);
void verifica_solucoes_existentes(int sol_idx, int total, int transformacoes[8][MAX_N], int *achou);
int solucao_e_unica(int *nova);
void exibir_solucao_rec(int *tabuleiro, int i);
void exibir_solucao(int *tabuleiro);
#endif // FUNCOES_H_INCLUDED
