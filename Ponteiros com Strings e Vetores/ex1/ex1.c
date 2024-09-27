#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

 /*
 1. void inverte(char *str);
Função : Inverte a ordem dos caracteres na string str
 */

void inverte(char *str){
    int tam = strlen(str)-1;
    char aux;
    char aux1[TAM];

    for(int i=tam ; i>=0 ; i--){
        aux = *(str+i);

        aux1[tam-i] = aux;
    }

    aux1[tam+1] = '\0';

    for(int i=0 ; i<=tam ; i++){
        *str = aux1[i];

        *str++;
    }


}

int main()
{
    char frase[TAM] = {"alagoas"};

    inverte(frase);

    printf("%s", frase);
    return 0;
}
