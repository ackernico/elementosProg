#include <iostream>
#include <fstream>
#include <cstdlib>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"portuguese");

    fstream arquivo;
    string linha;
    int contadorK = 0;

    arquivo.open("texto.txt", ios::in);

    if(!arquivo.is_open()){
        cout << "Erro. Nao foi possivel abrir o arquivo.";
    }else{
        while(getline(arquivo, linha)){
              for(int i=0 ; linha[i] != '\0' ; i++){
                if(linha[i] == 'k' || linha[i] == 'K'){
                    contadorK++;
                }
              }
        }
    }
    arquivo.close();

    cout << "Contador: " << contadorK << endl;


    return 0;
}
