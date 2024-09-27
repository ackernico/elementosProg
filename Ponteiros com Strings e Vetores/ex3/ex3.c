    #include <stdio.h>
    #include <stdlib.h>

    #define TAM 10

    /*
    3. void par_impar(int *vetor, int tamanho, int *par, int *npar, int *impar, int *nimpar);
    Função : Copia os valores pares de vetor para par e valores impares para impar
    Parametros : vetor – ponteiro para variavel de entrada de dados
    tamanho – numero de itens de vetor

    par – ponteiro para vetor que armazena valores pares
    *npar – numero de valores copiados para par
    impar – ponteiro para vetor que armazena valores impares
    *nimpar – numero de valores copiados para par
    */

    void par_impar(int *vetor, int tamanho, int *par, int *impar, int *npar, int *nimpar){

        for(int i=0 ; i<tamanho ; i++){
            if(*vetor %2 != 0){
                *impar = *vetor;
                impar++;
                 *nimpar=*nimpar+1;
            }
            else if(*vetor %2 == 0){
                *par = *vetor;
                par++;
                *npar=*npar+1;
            }
            vetor++;
        }
    }

    int main()
    {
        int vet[TAM] = {1,2,3,4,5,6,7,8,9,10};
        int tam = TAM;

        int pares[TAM];
        int impares[TAM];

        int qntPares=0;
        int qntImpares=0;

        par_impar(vet, tam, pares, impares, &qntPares, &qntImpares);

        for(int i=0 ; i<tam ; i++){
            printf("Vetor[%i] = %i\n", i, vet[i]);
        }

        printf("%i\n", qntPares);
        printf("%i\n", qntImpares);

        return 0;
    }
