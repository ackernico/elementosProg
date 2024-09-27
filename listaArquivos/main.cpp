#include <iostream>
#include <fstream>
#include <cstdlib>
/*
1. Abra um arquivo no formato txt contendo um texto. Analise o conteúdo e gere o seguinte relatório (na tela) . O nome do arquivo é fixo no código.
Quantidade de caracteres espaço.
Quantidade de linhas do texto.
Quantidade de vogais.
Quantidade de artigos definidos.

2. Modifique o exercício 1, para permitir que o usuário escolha o arquivo a ser analisado.

3. Modifique o exercício 2 para gerar um arquivo de relatório, cujo nome é o nome do arquivo aberto acrescido de _rel, mantendo a extensão .txt.
*/

using namespace std;

struct contador{
    int espacos=0;
    int linhas=0;
    int vogais=0;
    int artigos=0; //O, A, OS, AS
};

int main()
{
    contador contador;

    fstream arquivo;
    fstream saida;

    string nomeArquivo_i;
    string nomeArquivo_o;
    string linha;

    cout << "Digite o nome do arquivo a ser analisado" << endl;
    cout << "(Cole o arquivo .txt na pasta onde o .c esta)" << "\n\n";
    cin >> nomeArquivo_i;

    nomeArquivo_i.append(".txt");

    arquivo.open(nomeArquivo_i, ios::in);

    while(!arquivo.is_open()){
        system("CLS");
        cout << "Erro. O arquivo nao pode ser aberto. Digite o nome do arquivo novamente." << endl;
        cin >> nomeArquivo_i;
        nomeArquivo_i.append(".txt");
        arquivo.open(nomeArquivo_i, ios::in);
    }
        while(getline(arquivo, linha)){
            contador.linhas++;
            for(int i=0 ; linha[i] != '\0' ; i++){
                if(linha[i] == 'a' && isalpha(linha[i-1]) == 0 && linha[i+1] == ' '){
                    contador.vogais++;
                    contador.artigos++;
                }
                else if(linha[i] == 'o' && isalpha(linha[i-1]) == 0 && linha[i+1] == ' '){
                    contador.vogais++;
                    contador.artigos++;
                }
                else if(linha[i] == 'a' && linha[i+1] == 's' && isalpha(linha[i-1]) == 0){
                    contador.artigos++;
                }
                else if(linha[i] == 'A' && linha[i+1] == 'S' && isalpha(linha[i-1]) == 0){
                    contador.artigos++;
                }
                else if(linha[i] == 'o' && linha[i+1] == 's' && isalpha(linha[i-1]) == 0){
                    contador.artigos++;
                }
                else if(linha[i] == 'O' && linha[i+1] == 'S' && isalpha(linha[i-1]) == 0){
                    contador.artigos++;
                }
                else if(linha[i] == 'A' && linha[i-1] == ' ' && isalpha(linha[i-1]) == 0){
                    contador.vogais++;
                    contador.artigos++;
                }
                else if(linha[i] == 'O' && linha[i-1] == ' ' && linha[i+1] == ' '){
                    contador.vogais++;
                    contador.artigos++;
                }
                else if(linha[i] == 'e' || linha[i] == 'E' || linha[i] == 'i' || linha[i] == 'I' || linha[i] == 'u' || linha[i] == 'U'){
                    contador.vogais++;
                }
                else if(linha[i] == ' '){
                    contador.espacos++;
                }
            }
        }
        arquivo.close();

        nomeArquivo_i.erase(nomeArquivo_i.end()-4,nomeArquivo_i.end());
        nomeArquivo_o = nomeArquivo_i.append("_rel.txt");

        saida.open(nomeArquivo_o, ios::out);

        if(!saida.is_open()){
            cout << "Erro ao gerar o arquivo de saida.";
            return 1;
        }
        else{
            system("CLS");
            cout << "Arquivo de relatorio gerado!" << endl << "Localize-o na pasta onde o .c esta." << endl;
        }

        saida << "Vogais: " << contador.vogais << endl;
        saida << "Artigos: " << contador.artigos << endl;
        saida << "Espacos: " << contador.espacos << endl;
        saida << "Linhas: " << contador.linhas << endl;

        saida.close();
    return 0;
}
