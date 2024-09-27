#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

const int MAX_LINHAS = 2057;  // N�mero m�ximo de linhas de aloca��o de mat�rias
const int LINHAS_TURMA = 20;  // N�mero de linhas por turma, representando hor�rios
const int COLUNAS_TURMA = 6;  // N�mero de colunas por turma (Segunda a Sexta + hor�rio)
const int MAX_TURMAS = 100;   // N�mero m�ximo de turmas

// Lista de hor�rios para cada linha (�ndice) da matriz de hor�rios
string horarios[LINHAS_TURMA+2] = {
    "??", "??", "07:30", "08:20", "09:10", "10:20", "11:10", "13:10", "14:00",
    "14:50", "16:00", "16:50", "17:40", "19:00", "19:50", "21:00", "21:50"
};

// Fun��o para mapear o n�mero da turma para o c�digo correspondente
// Essa fun��o utiliza um switch-case para traduzir o n�mero da turma em um c�digo espec�fico
string getCodigoTurma(int turmaNum) {
    switch (turmaNum) {
        case 2: return "4111";
        case 3: return "4112";
        case 4: return "4123";
        case 5: return "4124";
        case 6: return "4211";
        case 7: return "4212";
        case 8: return "4223";
        case 9: return "4224";
        case 10: return "4311";
        case 11: return "4312";
        case 12: return "4323";
        case 13: return "4324";
        case 14: return "4411";
        case 15: return "4422";
        default: return "Turma " + to_string(turmaNum); // Caso n�o encontre um c�digo, retorna o n�mero da turma
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");  // Configura o idioma para portugu�s

    ifstream aqHorario;   // Arquivo de entrada contendo os hor�rios
    ifstream aqAlocacao;  // Arquivo de entrada contendo as aloca��es de mat�rias
    ofstream aqSaida;     // Arquivo de sa�da onde os resultados ser�o escritos

    string linha;  // Vari�vel usada para armazenar cada linha lida do arquivo
    string materias[MAX_LINHAS];  // Vetor para armazenar as mat�rias
    string salas[MAX_LINHAS];     // Vetor para armazenar as salas correspondentes �s mat�rias
    string labs[MAX_LINHAS];      // Vetor para armazenar os laborat�rios correspondentes �s mat�rias
    string matrizTurmas[MAX_TURMAS][LINHAS_TURMA][COLUNAS_TURMA];  // Matriz tridimensional para armazenar os hor�rios das turmas

    cout << "Abrindo arquivos..." << endl;
    aqHorario.open("Hor�rio.csv");    // Abre o arquivo Hor�rio.csv para leitura
    aqAlocacao.open("Alocacao.csv");  // Abre o arquivo Alocacao.csv para leitura
    aqSaida.open("labs.csv");         // Abre o arquivo labs.csv para escrita

    // Verifica se os arquivos foram abertos corretamente
    if (!aqSaida.is_open() || !aqHorario.is_open() || !aqAlocacao.is_open()) {
        cout << "Erro ao abrir o arquivo. Verifique o nome e tente novamente." << endl;
        return 1;
    }

    // Processa o arquivo Alocacao.csv, lendo as mat�rias, salas e laborat�rios
    int i = 0;
    while (getline(aqAlocacao, linha)) {
        stringstream ss(linha);
        string materia, sala, lab;

        // L� os campos separados por v�rgulas
        getline(ss, materia, ',');
        getline(ss, sala, ',');
        getline(ss, lab, ',');

        // Armazena os valores nas respectivas listas se n�o estiverem vazios
        if (!materia.empty() && i < MAX_LINHAS) {
            materias[i] = materia;
            salas[i] = sala;
            labs[i] = lab;
            i++;  // Incrementa o �ndice
        }
    }

    cout << "Arquivo 'Alocacao' processado!" << endl;

    // Processa o arquivo Horario.csv, lendo os hor�rios das turmas
    int turmaIdx = 0;  // �ndice da turma atual
    int linhaTurma = 0;  // �ndice da linha da turma dentro da matriz

    while (getline(aqHorario, linha)) {
        stringstream ss(linha);
        string campo;

        // Verifica se a linha cont�m "Turma" para identificar o in�cio de uma nova turma
        if (linha.find("Turma") != string::npos) {
            if (turmaIdx >= MAX_TURMAS) {  // Limite de turmas
                cout << "N�mero m�ximo de turmas atingido!" << endl;
                break;
            }
            linhaTurma = 0;  // Reinicia a contagem de linhas para a nova turma
            turmaIdx++;      // Passa para a pr�xima turma
            continue;
        }

        // Se ainda estiver dentro da linha de hor�rios da turma
        if (linhaTurma < LINHAS_TURMA) {
            int coluna = 0;
            while (getline(ss, campo, ',') && coluna < COLUNAS_TURMA) {
                matrizTurmas[turmaIdx][linhaTurma][coluna] = campo;  // Armazena os dados na matriz tridimensional
                coluna++;
            }
            linhaTurma++;
        }
    }

    cout << "Arquivo 'Horario' processado!" << endl;

    // Gera o arquivo de sa�da, cruzando os dados de hor�rios e laborat�rios
    for (int m = 1; m < i; m++) {  // Come�a do �ndice 1 para pular os cabe�alhos
        string materia = materias[m];
        string lab = labs[m];
        bool encontrouMateria = false;  // Flag para indicar se a mat�ria foi encontrada
        string matrizHorario[LINHAS_TURMA][COLUNAS_TURMA] = {};  // Matriz tempor�ria para armazenar hor�rios da mat�ria

        // Percorre todas as turmas e busca a mat�ria
        for (int t = 0; t < turmaIdx; t++) {
            for (int l = 0; l < LINHAS_TURMA; l++) {
                for (int c = 1; c < COLUNAS_TURMA; c++) {  // Ignora a coluna 0 (hor�rios)
                    if (matrizTurmas[t][l][c].find(materia) != string::npos) {
                        // Substitui "Turma X" pelo c�digo correspondente e adiciona o laborat�rio
                        matrizHorario[l][c] = getCodigoTurma(t + 1) + " " + lab;
                        encontrouMateria = true;
                    }
                }
            }
        }

        // Se encontrou a mat�ria, escreve no arquivo de sa�da
        if (encontrouMateria) {
            aqSaida << materia << ",,,,,\n";  // Escreve o nome da mat�ria como cabe�alho
            aqSaida << "Hor�rio,Segunda,Ter�a,Quarta,Quinta,Sexta\n";  // Cabe�alho dos dias da semana

            // Escreve os hor�rios e respectivas turmas
            for (int l = 2; l < LINHAS_TURMA - 3; l++) {  // Ajuste para ignorar hor�rios finais
                aqSaida << horarios[l];  // Escreve o hor�rio
                for (int c = 1; c < COLUNAS_TURMA; c++) {
                    // Preenche a c�lula com o c�digo da turma e laborat�rio ou "---" se estiver vazio
                    aqSaida << "," << (matrizHorario[l][c].empty() ? "---" : matrizHorario[l][c]);
                }
                aqSaida << "\n";  // Finaliza a linha
            }

            aqSaida << "\n";  // Separador entre mat�rias
        }
    }

    cout << "Arquivo de sa�da escrito com sucesso!" << endl;

    // Fecha os arquivos ap�s o processamento
    aqHorario.close();
    aqAlocacao.close();
    aqSaida.close();

    return 0;  // Retorna 0 indicando que o programa terminou corretamente
}
