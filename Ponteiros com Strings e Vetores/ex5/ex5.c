#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 5

/*
5. void ordena(int *dados, int tam, char ordem);
Função : Ordena em ordem crescente os valores apontados por dados
Parametros : dados – ponteiro para vetor a ser ordenado
tamanho – numero de itens de dados

ordem – ‘c’ para ordenamento crescente, ‘d’ para ordenamento decrescente.
Case insensitive – não importa se é maiuscula ou minuscula
Padrão é ordenamento crescente.

DICA : Utilize um algoritmo de ordenação conhecido, como o bubble sort ou o quick-sort
*/

void ordena(int *dados, int tam, char ordem){
    int aux;

    ordem = toupper(ordem);

    switch(ordem){
    case 'D' :
        for(int i=0 ; i<tam ; i++){
        for(int j=0 ; j<tam-i-1 ; j++){
            if(*(dados+j) < *(dados+j+1)){
                aux = *(dados+j);
                *(dados+j) = *(dados+j+1);
                *(dados+j+1) = aux;
            }
        }
    }
    break;
    case 'C':
    default:
        for(int i=0 ; i<tam ; i++){
        for(int j=0 ; j<tam-i-1 ; j++){
            if(*(dados+j) > *(dados+j+1)){
                aux = *(dados+j);
                *(dados+j) = *(dados+j+1);
                *(dados+j+1) = aux;
            }
        }
    }
    break;

    }
}

int main()
{
    int vet[TAM] = {14,22,17,0,140};
    int tamanho = 5;
    int coud = 'q';

    ordena(vet, tamanho, coud);

    for(int i=0 ; i<tamanho ; i++){
        printf("vet[%i] = %i\n", i, vet[i]);
    }
    return 0;
}
