#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TAMR 2

typedef struct resistor {
    int valor;
    int num1;
    int num2;
    int num3;
    char cor[TAMR];
    char cor2[TAMR];
    char cor3[TAMR];
}resistorT;


int main()
{
    resistorT rst;

    printf("Cor 1:\n");
    gets(rst.cor);

    if(strcmp(rst.cor, "PR") == 0){
        rst.num1 = 0;
    }
    else if(strcmp(rst.cor, "MR") == 0){
        rst.num1 = 1;
    }
    else if(strcmp(rst.cor, "VM") == 0){
        rst.num1 = 2;
    }
    else if(strcmp(rst.cor, "LR") == 0){
        rst.num1 = 3;
    }
    else if(strcmp(rst.cor, "AM") == 0){
        rst.num1 = 4;
    }
    else if(strcmp(rst.cor, "VD") == 0){
        rst.num1 = 5;
    }
    else if(strcmp(rst.cor, "AZ") == 0){
        rst.num1 = 6;
    }
    else if(strcmp(rst.cor, "VI") == 0){
        rst.num1 = 7;
    }
    else if(strcmp(rst.cor, "CZ") == 0){
        rst.num1 = 8;
    }
    else if(strcmp(rst.cor, "BR") == 0){
        rst.num1 = 9;
    }
    else{
        printf("Digite um valor valido\n");
    }

    printf("Cor 2:\n");
    gets(rst.cor2);

    if(strcmp(rst.cor2, "PR") == 0){
        rst.num2 = 0;
    }
    else if(strcmp(rst.cor2, "MR") == 0){
        rst.num2 = 1;
    }
    else if(strcmp(rst.cor2, "VM") == 0){
        rst.num2 = 2;
    }
    else if(strcmp(rst.cor2, "LR") == 0){
        rst.num2 = 3;
    }
    else if(strcmp(rst.cor2, "AM") == 0){
        rst.num2 = 4;
    }
    else if(strcmp(rst.cor2, "VD") == 0){
        rst.num2 = 5;
    }
    else if(strcmp(rst.cor2, "AZ") == 0){
        rst.num2 = 6;
    }
    else if(strcmp(rst.cor2, "VI") == 0){
        rst.num2 = 7;
    }
    else if(strcmp(rst.cor2, "CZ") == 0){
        rst.num2 = 8;
    }
    else if(strcmp(rst.cor2, "BR") == 0){
        rst.num2 = 9;
    }
    else{
        printf("Digite um valor valido\n");
    }

    printf("Cor 3:\n");
    gets(rst.cor3);

    if(strcmp(rst.cor, "PR") == 0){
        rst.num3 = 0;
    }
    else if(strcmp(rst.cor3, "MR") == 0){
        rst.num3 = 1;
    }
    else if(strcmp(rst.cor3, "VM") == 0){
        rst.num3 = 2;
    }
    else if(strcmp(rst.cor3, "LR") == 0){
        rst.num3 = 3;
    }
    else if(strcmp(rst.cor3, "AM") == 0){
        rst.num3 = 4;
    }
    else if(strcmp(rst.cor3, "VD") == 0){
        rst.num3 = 5;
    }
    else if(strcmp(rst.cor3, "AZ") == 0){
        rst.num3 = 6;
    }
    else if(strcmp(rst.cor3, "VI") == 0){
        rst.num3 = 7;
    }
    else if(strcmp(rst.cor3, "CZ") == 0){
        rst.num3 = 8;
    }
    else if(strcmp(rst.cor3, "BR") == 0){
        rst.num3 = 9;
    }
    else{
        printf("Digite um valor valido\n");
    }

    rst.valor = ((pow(10, rst.num3+1) * rst.num1) + (pow(10, rst.num3) * rst.num2));

    printf("Resistor: %i ohms", rst.valor);


    return 0;
}
