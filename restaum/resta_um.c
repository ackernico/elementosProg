/**********************************************************
* @brief    Trabalho trimestral - Resta Um
* @author   Marcos Zuccolotto
* @date     abr/2024
* @version  1.0
*
* Fundacao Liberato - Curso de Eletronica
* Elementos de programacao  - prof. Marcos Zuccolotto
*
* Trabalho trimestral - Struct / enum / ponteiros
*
* Implemente as funcoes abaixo comforme especificacao,
*  respeitando os parâmetros e tipos de dados definidos,
*  seguindo as orientacoes dadas
*
* - qualJogada()
* - movimenta()
* - confereJogo()
*
* Equipe : Nicolas Acker de Souza e Lucas Menegotto Dias

**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "resta_um.h"
#include <ctype.h>

#define MAXMSG 100  //tamanho maximo mensagens

int main()
{
 // Variaveis
    char tabRestaUm[NLIN][NCOL]; // tabuleiro
    status_t estado=OK;         // resultado da função
    movimento_t jogada;         // movimento a realizar
    char msg[MAXMSG];           // mensagem para usuario
    unsigned int numJogadas=0;  // Numero de jogadas realizadas

// Inicializacao
    setlocale(LC_ALL,"");        // caracteres da lingua portuguesa
    inicTab(tabRestaUm);         // Preenche tabuleiro inicial
    showTab(tabRestaUm);         // Exibe o tabulero
// Laco principal
    do{
      estado=qualJogada(&jogada);
      if(estado!=DERROTA){ // Se não pedir para sair, segue o jogo
        estado=movimenta(tabRestaUm,&jogada);
        switch(estado)
        {
        case    INVALIDO:
                strncpy(msg, "Movimento inválido\n",MAXMSG);
                break;
        case    VAZIO:
                strncpy(msg, "Sem peças a mover\n",MAXMSG);
                break;
        case    OCUPADO:
                strncpy(msg, "Posição destino ocupada\n",MAXMSG);
                break;
        default:
                numJogadas++;
                msg[0]='\0';
                showTab(tabRestaUm);
                estado=confereJogo(tabRestaUm);
                switch(estado)
                {
                case VITORIA:
                    strncpy(msg,"Parabéns, sobrou só um !\n",MAXMSG);
                    break;
                case DERROTA:
                    strncpy(msg,"Acabaram as jogadas !\n",MAXMSG);
                    break;
                default:
                    strncpy(msg,"jogo continua...\n",MAXMSG);
            }
        }
        printf("%s\n",msg);
     }
    }while(estado!= VITORIA && estado!= DERROTA);

    printf("Fim de jogo com %d rodadas!\n",numJogadas);

    return 0;
}// fim main

void inicTab(char *tab);
/**
@brief Exibe o tabuleiro
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

int verificaTam(int valor) { // Função para verificar se o valor está dentro do tabuleiro
    int aux;

    do {
        if (valor > 7 || valor < 1) {
            printf("Movimento fora do tabuleiro, digite novamente:\n");
            aux = FORA;
        }
        else {
            aux = OK;
        }
    } while (aux != OK);

    return valor;
}

int transformaLetra(char letra){ // função para transformar a letra da coluna em numero

    int aux=0;
    scanf(" %c", &letra);

    if(letra == 'a' || letra == 'A'){
        return 1;
    }
    else if(letra == 'b' || letra == 'B'){
        return 2;
    }
    else if(letra == 'c' || letra == 'C'){
        return 3;
    }
    else if(letra == 'd' || letra == 'D'){
        return 4;
    }
    else if(letra == 'e' || letra == 'E'){
        return 5;
    }
    else if(letra == 'f' || letra == 'F'){
        return 6;
    }
    else if(letra == 'g' || letra == 'G'){
        return 7;
    }
    else{
        aux=1;
    }
}
status_t qualJogada(movimento_t* jog) {

    int aux;
    char verif;
    char colOrg;
    char colDest;

    do{

        printf("Linha de origem: ");
        scanf("%d", &(jog->origem.lin));
        jog->origem.lin = verificaTam(jog->origem.lin);

        printf("Coluna de origem: ");
        jog->origem.col = transformaLetra(colOrg);
        jog->origem.col = verificaTam(jog->origem.col);

        if (jog->origem.col < 3 && jog->origem.lin < 3) {
            printf("Movimento fora do tabuleiro, digite novamente:\n");
            aux = FORA;
        }
        else if (jog->origem.col > 5 && jog->origem.lin > 5) {
            printf("Movimento fora do tabuleiro, digite novamente:\n");
            aux = FORA;
        }
        else if (jog->origem.col < 3 && jog->origem.lin > 5) {
            printf("Movimento fora do tabuleiro, digite novamente:\n");
            aux = FORA;
        }
        else if (jog->origem.col > 5 && jog->origem.lin < 3) {
            printf("Movimento fora do tabuleiro, digite novamente:\n");
            aux = FORA;
        }
        else {
            aux = OK;
        }
    } while (aux != OK); // Verificação para ver se o movimento de origem está dentro do tabuleiro

    do{
        do{
            printf("\nLinha de destino: ");
            scanf("%i", &(jog->destino.lin));
            jog->destino.lin = verificaTam(jog->destino.lin);

            printf("Coluna de destino: ");
            jog->destino.col = transformaLetra(colDest);
            jog->destino.col = verificaTam(jog->destino.col);

            if (jog->destino.col < 3 && jog->destino.lin < 3) {
                printf("Movimento fora do tabuleiro, digite novamente:\n");
                aux = FORA;
            }
            else if (jog->destino.col > 5 && jog->destino.lin > 5) {
                printf("Movimento fora do tabuleiro, digite novamente:\n");
                aux = FORA;
            }
            else if (jog->destino.col < 3 && jog->destino.lin > 5) {
                printf("Movimento fora do tabuleiro, digite novamente:\n");
                aux = FORA;
            }
            else if (jog->destino.col > 5 && jog->destino.lin < 3) {
                printf("Movimento fora do tabuleiro, digite novamente:\n");
                aux = FORA;
            }
            else {
                aux = OK;
            }
        } while (aux != OK);  // Verificação para ver se o movimento de destino está dentro do tabuleiro

            if (jog->destino.col - jog->origem.col > 2 || jog->destino.lin - jog->origem.lin > 2) {
                printf("Movimento longo demais, digite novamente:\n");
                aux = NP;
            }
            else if ( (jog->destino.col - jog->origem.col < 2 && jog->destino.col - jog->origem.col > 0) || (jog->destino.lin - jog->origem.lin < 2 && jog->destino.lin - jog->origem.lin > 0) ) {
                printf("Movimento curto demais, digite novamente:\n");
                aux = NP;
            }
            else if ((jog->origem.lin == jog->destino.lin) && (jog->origem.col == jog->destino.col)) {
                printf("Movimentos iguais, digite novamente:\n");
                aux = NP;
            }
            else if ((jog->origem.lin != jog->destino.lin) && (jog->origem.col != jog->destino.col)) {
                printf("Movimento em diagonal, digite novamente:\n");
                aux = NP;
            }
            else{
                aux = OK;
            }

    } while (aux != OK); // Verificação para ver se o movimento de destino não é o mesmo que o de origem,se o movimento não é longo ou curto demais e se não é na diagonal

    fflush(stdin);

    printf("\nPressione qualquer tecla para continuar ou N para sair: ");
    scanf("%c", &verif);

    if(verif == 'n' || verif == 'N'){
        return DERROTA;
    }
    else{
        return OK;
    }
}

/**
@brief Executa a movimentacao solicitada
@param tabuleiro
@param movimentacao a realizar
@retval OK - movimento executado, segue o jogo
        INVALIDO - movimento invalido
        OCUPADO - posicao destino ocupada
        VAZIO  posicao destino ocupada
*/
status_t movimenta(char *tab, movimento_t *jog) {
    int auxOrg;
    int auxDest;

    auxOrg = ((jog->origem.lin - 1) * 7) + jog->origem.col-1; // Variaveis auxiliares para saber a posição de origem e destino
    auxDest = ((jog->destino.lin - 1) * 7) + jog->destino.col-1;

    if(*(tab+auxOrg) == VZ){
        return VAZIO;
    }
    else if(*(tab+auxOrg) == NU || *(tab+auxDest) == NU){
        return INVALIDO;
    }
    else if(*(tab+auxDest) == OC){
        return OCUPADO;
    }
    else if(*(tab+auxDest) == OC && *(tab+auxOrg) == OC){
        return OCUPADO;
    }
    else{

        if(jog->origem.col == jog->destino.col){ // movimento vertical
            *(tab+auxDest) = OC;
            *(tab+auxOrg) = VZ;

            if(jog->origem.lin > jog->destino.lin){ // De baixo pra cima
                *(tab+auxOrg - 7) = VZ;
            }
            else if(jog->origem.lin < jog->destino.lin){ // De cima pra baixo
                *(tab+auxOrg + 7) = VZ;
            }
        }
        else if(jog->origem.lin == jog->destino.lin){ // movimento horizontal
            *(tab+auxDest) = OC;
            *(tab+auxOrg) = VZ;

            if(jog->origem.col > jog->destino.col){ // Da direita pra esquerda
                *(tab+auxOrg - 1) = VZ;
            }
            else if(jog->origem.col < jog->destino.col){ // Da esquerda pra direita
                *(tab+auxOrg + 1) = VZ;
            }
        }
        return OK;
    }


}

/**
@brief Confere possibilidades de continuacao
@param tabuleiro
@retval OK -  segue o jogo
        VITORIA - restou um, acabou
        DERROTA - nada mais a fazer, fim de jogo
*/
status_t confereJogo(char *tab) {
    int contVZ = 0;
    int i, j;

    // Contar quantas casas vazias (VZ) existem no tabuleiro
    for (i = 0; i < NLIN; i++) {
        for (j = 0; j < NCOL; j++) {
            if (*(tab + NCOL * i + j) == VZ || *(tab + NCOL * i + j) == NU) {
                contVZ++;
            }
        }
    }

    // Verificar se o jogo está ganho (apenas uma peça restante)
    if (contVZ == 48) {  // 49 posições no tabuleiro, 1 peça restante = 48 posições vazias
        return VITORIA;
    }

    // Verificar se ainda há movimentos possíveis
    for (i = 0; i < NLIN; i++) {
        for (j = 0; j < NCOL; j++) {
            char elem_atual = *(tab + NCOL * i + j);

            if (elem_atual == OC) {
                // Verificar movimento possível para a direita
                if (j + 2 < NCOL && *(tab + NCOL * i + (j + 1)) == OC && *(tab + NCOL * i + (j + 2)) == VZ) {
                    return OK;
                }
                // Verificar movimento possível para a esquerda
                if (j - 2 >= 0 && *(tab + NCOL * i + (j - 1)) == OC && *(tab + NCOL * i + (j - 2)) == VZ) {
                    return OK;
                }
                // Verificar movimento possível para baixo
                if (i + 2 < NLIN && *(tab + NCOL * (i + 1) + j) == OC && *(tab + NCOL * (i + 2) + j) == VZ) {
                    return OK;
                }
                // Verificar movimento possível para cima
                if (i - 2 >= 0 && *(tab + NCOL * (i - 1) + j) == OC && *(tab + NCOL * (i - 2) + j) == VZ) {
                    return OK;
                }
            }
        }
    }

    // Se não há movimentos possíveis, é derrota
    return DERROTA;
}

