#include <stdio.h>
#include <stdlib.h>
#define TAM 6

/*
4. void ordena_c(int *dados, int tam);
Função : Ordena em ordem crescente os valores apontados por dados
Parametros : dados – ponteiro para vetor a ser ordenado
tamanho – numero de itens de dados
DICA : Utilize um algoritmo de ordenação conhecido, como o bubble sort ou o quick-sort
*/

void ordena(int *dados, int tam){
    int aux;

    for(int i=0 ; i<tam ; i++){
        for(int j=0 ; j<tam-i-1 ; j++){
            if(*(dados+j) > *(dados+j+1)){
                aux = *(dados+j);
                *(dados+j) = *(dados+j+1);
                *(dados+j+1) = aux;
            }
        }
    }
}

int main() {
    int nums[TAM] = {0, 69, 14, 25, 10, 2};
    int tamanho = TAM;

    ordena(nums, tamanho);

    for(int i = 0; i < tamanho; i++) {
        printf("num[%i] = %i\n", i, nums[i]);
    }

    return 0;
}
