#include <iostream>
#include <fstream>

/*
ofstream - saida
ifstream - entrada
fstream - flexivel, pode ser entrada ou saida
*/

using namespace std;

int main()
{
    ofstream arquivo; //Objeto do arquivo de SA�DA
    ifstream leitor; // Objeto para ler o arquivo (ENTRADA)
    string linha; // Var�avel para armazenar as linhas lidas;
/*
    arquivo.open("teste.txt"); //Criar o arquivo
    //arquivo.open("teste.txt", ios::app); //Nessa escrita o cursor � posicionado no final do arquivo
    arquivo << "Eu quero terminar isso logo pq quero jogar ds3"; // Do mesmo jeito que o stream cout
    arquivo.close(); //Fechar o arquivo para limpar mem�ria
*/
    leitor.open("teste.txt");

    if(leitor.is_open()){
        while(getline(leitor, linha)){
            cout << linha << endl;
        }
        leitor.close();
    }else{
        cout << "Erro. Nao foi possivel abrir o arquivo." << endl;
    }



    return 0;
}
