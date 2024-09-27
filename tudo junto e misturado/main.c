#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 4
/*
3. int m_identidade(matriz_t *mat_t, matriz_t *mat );
Função : obtem a transposta de matrizes
Parametros : mat – matriz origem
mat_t – matriz transposta

Retorno : 0 – função executada, -1 : tamanhos incompativeis
*/

typedef struct {
    int lin; // posição na linha
    int col; // posição na coluna
}pos2d_t; // posição em sistema de coordenadas 2d
typedef struct {
    int *d; // area de dados
    int t; // tamanho do campo de dados
}vetor_t; // representa um vetor de dados tipo inteiros
    typedef struct {
    int *d; // area de dados
    pos2d_t t; // tamanho do campo de dados
}matriz_t; // representa uma matriz de dados tipo inteiros

void v_maior(vetor_t *vet, int *maior, int *pos ){
    *maior = vet->d[0];
    *pos = 0;

    for(int i=0 ; i<vet->t ; i++){
        if(vet->d[i] > *maior){
            *maior = vet->d[i];
            *pos = i;
        }
    }
}

int mat_vetor(matriz_t *mat, vetor_t *vet, int lin){
    if(mat->t.col < vet->t){
        return -1;
    }
    else{

        for(int i=0 ; i<mat->t.col ; i++){
            *((mat->d)+ (mat->t.col * (lin-1)) + i ) = vet->d[i];
        }

        return 0;
    }

}

int m_identidade(matriz_t *mat_t, matriz_t *mat ){
    if(mat->t.col != mat_t->t.lin || mat->t.lin != mat_t->t.col){
        return -1;
    }
    else{
        for (int x = 0; x < mat_t->t.lin; x++) {
            for (int y = 0; y < mat_t->t.col; y++) {
                *((mat_t->d) + (mat_t->t.col * x) + y) = *((mat->d) + (mat->t.col * y) + x);
            }
        }
        return 0;
    }
}

int main()
{
    srand(time(NULL));

    vetor_t veto;
    matriz_t mtr;
    matriz_t trans;


    int posicao;
    int maiorNum;
    int dados[TAM];

    int linha = 3;
    int coluna = 4;
    int matri[linha][coluna];
    int verif;
    int verifT;

    veto.d = dados;
    veto.t = TAM;

    mtr.t.col = coluna;
    mtr.t.lin = linha;
    mtr.d = matri;

    trans.t.lin = 4;
    trans.t.col = 3;

    int matT[trans.t.lin][trans.t.col];
    trans.d = matT;

    for(int i=0 ; i<veto.t ; i++){
        dados[i] = rand() % 10;

        if(i > 0){
            for(int j=0 ; j<i ; j++){
                if(dados[j] == dados[i]){
                    i--;
                }
            }
        }
    }

    printf("------------FUNCAO 1----------------\n\n");
    for(int i=0 ; i<veto.t ; i++){
        printf("Vetor[%i] = %i\n", i, dados[i]);
    }

    v_maior(&veto, &maiorNum, &posicao);

    printf("\nMaior: %i\nPosicao: %i", maiorNum, posicao);

    printf("\n\n------------FUNCAO 2----------------\n\n");

    for(int x=0 ; x<mtr.t.lin ; x++){
        for(int y=0 ; y<mtr.t.col ; y++){
            matri[x][y] = rand() % 4;
        }
    }

    printf("Matriz:\n\n");
    for(int x=0 ; x<mtr.t.lin ; x++){
        for(int y=0 ; y<mtr.t.col ; y++){
            printf("%i ", matri[x][y]);
        }
        printf("\n");
    }

    verif = mat_vetor(&mtr, &veto, 2);

    printf("\n");
    switch(verif){
    case -1:
        printf("Tamanho de vetor maior que numero de colunas.\n");
        break;
    default:
    case 0:
        printf("\nMatriz com o vetor inserido:\n");
        for(int x=0 ; x<mtr.t.lin ; x++){
            for(int y=0 ; y<mtr.t.col ; y++){
                printf("%i ", matri[x][y]);
            }
        printf("\n");
        }
    break;
    }

    printf("\n------------FUNCAO 3----------------\n\n");

    verifT = m_identidade(&trans, &mtr);

    if(verifT == -1){
        printf("Tamanho incompativel.\n");
    }
    else{
        for(int x=0 ; x<trans.t.lin ; x++){
            for(int y=0 ; y<trans.t.col ; y++){
                printf("%i ", matT[x][y]);
            }
        printf("\n");
        }
    }




    return 0;
}
