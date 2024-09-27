#include <stdio.h>
#include <stdlib.h>

char classifica(int *temperaturas){
    int max = 42;
    int min = -3;
    int aux;
    int i;
    int vt;

    for(int i=0 ; i<4 ; i++){
        for(int j=0 ; j<4-i-1 ; j++){
            if(*(temperaturas+j+1) < *(temperaturas+j)){
                aux = *(temperaturas+j+1);
                *(temperaturas+j+1) = *(temperaturas+j);
                *(temperaturas+j) = aux;
            }
        }
    }

    vt=*(temperaturas+3)-*(temperaturas);

    for(i=0 ; i<4 ; i++){
        if(*temperaturas > 42 && *temperaturas < -3){
            max = *temperaturas;
            min = *temperaturas;
        }
        else if(*temperaturas < -3){
            min = *temperaturas;
        }
        else if(*temperaturas > 42){
            max = *temperaturas;
        }

        temperaturas++;

        if(i==3){
            if(max > 42 && min < -3){
                printf("Nova temperatura maxima registrada, %io celcius.\n", max);
                printf("Nova temperatura minima registrada, %io celcicus.\n", min);
            }
            else if(min < -3){
                printf("Nova temperatura minima registrada, %io celcicus.\n", min);
            }
            else if(max > 42){
                printf("Nova temperatura maxima registrada, %io celcius.\n", max);
            }
        }
    }

    if(vt < 2){
        return 'e';
    }
    else if(vt>=2 && vt<5){
        return 'c';
    }
    else if(vt>=5 && vt <10){
        return 'f';
    }
    else if(vt>=10 && vt <20){
        return 'x';
    }
    else if(vt > 20){
        return 'i';
    }
}

int main()
{
    int temps[4];
    char classficacao;

    printf("Digite as quatro temperaturas:\n");
    for(int i=0 ; i<4 ; i++){
        scanf("%i", &temps[i]);
    }

    classficacao = classifica(temps);

    printf("Temperaturas em ordem crescente:\n");
    for(int i=0 ; i<4 ; i++){
        printf("%i\n", temps[i]);
    }

    printf("\n\nClassificacao = %c", classficacao);


    return 0;
}
