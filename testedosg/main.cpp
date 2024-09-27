#include <iostream>
#include <fstream>

#define MAX_PALAVRAS 500

using namespace std;

int main()
{
    fstream arquivo;

    string linha;
    string palavras[MAX_PALAVRAS];

    int contaLinha=0;
    int contaVogal=0;
    int contpal=0;

    arquivo.open("ready!.txt", ios::in);

    if(!arquivo.is_open()){
        cerr << "ta dando merda";
        return -1;
    }

    while(getline(arquivo, linha)){
        contaLinha++;
        for(int i=0; linha[i] != '\0' ; i++){
            if(linha[i+1] == ' '){
                palavras[0] = linha.substr(0, i);
                contpal++;
            }
        }
    }

    cout << "Linhas: " << contaLinha << endl;
    cout << "Vogais: " << contaVogal << endl;
    cout << palavras[0] << endl;

    arquivo.close();

    return 0;
}
