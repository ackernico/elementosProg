/**********************************************************
* @file     resta_um.h
* @brief    Resta Um - defines, tipos dados e prototipos
* @author   Marcos Zuccolotto
* @date     abr/2024
* @version  1.0
*
*
**********************************************************/

#ifndef _RESTA_UM_H_   // Declaracao de guarda
#define _RESTA_UM_H_

// Dimensoes da matriz que guarda o tabuleiro
#define NCOL 7
#define NLIN 7

// Marcadores do tabuleiro-
#define  NU 'X'  // Ponto invalido/proibido
#define  OC '*'  // Ponto ocupado
#define  VZ 'O'  // Ponto livre/vazio

/* Tipos de dados */

// Posicao peca no tabuleiro
typedef struct
    {
    int lin; // Posicao linha
    int col; // Posicao destino
    }posTab_t;
// Movimento a ser realizado
typedef struct
    {
        posTab_t origem;   // Posicao inicio/origem
        posTab_t destino; // Posicao fim/
    }movimento_t;

typedef enum { OK=0 ,    // movimento executado, segue o jogo
               INVALIDO, // não existe peca a pular sobre/retira
               FORA,     // fora tabuleiro
               NP,       // movimento longo, curto ou em diagonal
               OCUPADO,  // posicao destino ocupada
               VAZIO,    // posicao origem vazia
               VITORIA,  // vitoria - fim jogo
               DERROTA   // nao tem mais o que fazer
             } status_t;
/* Prototipos */
void inicTab(char *tab);
/**
@brief Inicializa tabuleiro
@param tabuleiro
@retval none
*/
void showTab(char *tab);

/**
@brief Entrada dados da jogada
@param movimentacao a realizar
@retval OK - jogador definiu a movimentacao
        DERROTA - jogador desistiu do jogo
*/
int verificaTam(int valor);

status_t qualJogada(movimento_t* jog);

status_t movimenta(char *tab, movimento_t *jog);

status_t confereJogo(char *tab);

#endif // _RESTA_UM_H_
