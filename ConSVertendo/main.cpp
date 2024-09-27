#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

const int MAX_LINHAS = 2057;  // Número máximo de linhas de alocação de matérias
const int LINHAS_TURMA = 20;  // Número de linhas por turma, representando horários
const int COLUNAS_TURMA = 6;  // Número de colunas por turma (Segunda a Sexta + horário)
const int MAX_TURMAS = 100;   // Número máximo de turmas

// Lista de horários para cada linha (índice) da matriz de horários
string horarios[LINHAS_TURMA+2] = {
    "??", "??", "07:30", "08:20", "09:10", "10:20", "11:10", "13:10", "14:00",
    "14:50", "16:00", "16:50", "17:40", "19:00", "19:50", "21:00", "21:50"
};

// Função para mapear o número da turma para o código correspondente
// Essa função utiliza um switch-case para traduzir o número da turma em um código específico
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
        default: return "Turma " + to_string(turmaNum); // Caso não encontre um código, retorna o número da turma
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");  // Configura o idioma para português

    ifstream aqHorario;   // Arquivo de entrada contendo os horários
    ifstream aqAlocacao;  // Arquivo de entrada contendo as alocações de matérias
    ofstream aqSaida;     // Arquivo de saída onde os resultados serão escritos

    string linha;  // Variável usada para armazenar cada linha lida do arquivo
    string materias[MAX_LINHAS];  // Vetor para armazenar as matérias
    string salas[MAX_LINHAS];     // Vetor para armazenar as salas correspondentes às matérias
    string labs[MAX_LINHAS];      // Vetor para armazenar os laboratórios correspondentes às matérias
    string matrizTurmas[MAX_TURMAS][LINHAS_TURMA][COLUNAS_TURMA];  // Matriz tridimensional para armazenar os horários das turmas

    cout << "Abrindo arquivos..." << endl;
    aqHorario.open("Horário.csv");    // Abre o arquivo Horário.csv para leitura
    aqAlocacao.open("Alocacao.csv");  // Abre o arquivo Alocacao.csv para leitura
    aqSaida.open("labs.csv");         // Abre o arquivo labs.csv para escrita

    // Verifica se os arquivos foram abertos corretamente
    if (!aqSaida.is_open() || !aqHorario.is_open() || !aqAlocacao.is_open()) {
        cout << "Erro ao abrir o arquivo. Verifique o nome e tente novamente." << endl;
        return 1;
    }

    // Processa o arquivo Alocacao.csv, lendo as matérias, salas e laboratórios
    int i = 0;
    while (getline(aqAlocacao, linha)) {
        stringstream ss(linha);
        string materia, sala, lab;

        // Lê os campos separados por vírgulas
        getline(ss, materia, ',');
        getline(ss, sala, ',');
        getline(ss, lab, ',');

        // Armazena os valores nas respectivas listas se não estiverem vazios
        if (!materia.empty() && i < MAX_LINHAS) {
            materias[i] = materia;
            salas[i] = sala;
            labs[i] = lab;
            i++;  // Incrementa o índice
        }
    }

    cout << "Arquivo 'Alocacao' processado!" << endl;

    // Processa o arquivo Horario.csv, lendo os horários das turmas
    int turmaIdx = 0;  // Índice da turma atual
    int linhaTurma = 0;  // Índice da linha da turma dentro da matriz

    while (getline(aqHorario, linha)) {
        stringstream ss(linha);
        string campo;

        // Verifica se a linha contém "Turma" para identificar o início de uma nova turma
        if (linha.find("Turma") != string::npos) {
            if (turmaIdx >= MAX_TURMAS) {  // Limite de turmas
                cout << "Número máximo de turmas atingido!" << endl;
                break;
            }
            linhaTurma = 0;  // Reinicia a contagem de linhas para a nova turma
            turmaIdx++;      // Passa para a próxima turma
            continue;
        }

        // Se ainda estiver dentro da linha de horários da turma
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

    // Gera o arquivo de saída, cruzando os dados de horários e laboratórios
    for (int m = 1; m < i; m++) {  // Começa do índice 1 para pular os cabeçalhos
        string materia = materias[m];
        string lab = labs[m];
        bool encontrouMateria = false;  // Flag para indicar se a matéria foi encontrada
        string matrizHorario[LINHAS_TURMA][COLUNAS_TURMA] = {};  // Matriz temporária para armazenar horários da matéria

        // Percorre todas as turmas e busca a matéria
        for (int t = 0; t < turmaIdx; t++) {
            for (int l = 0; l < LINHAS_TURMA; l++) {
                for (int c = 1; c < COLUNAS_TURMA; c++) {  // Ignora a coluna 0 (horários)
                    if (matrizTurmas[t][l][c].find(materia) != string::npos) {
                        // Substitui "Turma X" pelo código correspondente e adiciona o laboratório
                        matrizHorario[l][c] = getCodigoTurma(t + 1) + " " + lab;
                        encontrouMateria = true;
                    }
                }
            }
        }

        // Se encontrou a matéria, escreve no arquivo de saída
        if (encontrouMateria) {
            aqSaida << materia << ",,,,,\n";  // Escreve o nome da matéria como cabeçalho
            aqSaida << "Horário,Segunda,Terça,Quarta,Quinta,Sexta\n";  // Cabeçalho dos dias da semana

            // Escreve os horários e respectivas turmas
            for (int l = 2; l < LINHAS_TURMA - 3; l++) {  // Ajuste para ignorar horários finais
                aqSaida << horarios[l];  // Escreve o horário
                for (int c = 1; c < COLUNAS_TURMA; c++) {
                    // Preenche a célula com o código da turma e laboratório ou "---" se estiver vazio
                    aqSaida << "," << (matrizHorario[l][c].empty() ? "---" : matrizHorario[l][c]);
                }
                aqSaida << "\n";  // Finaliza a linha
            }

            aqSaida << "\n";  // Separador entre matérias
        }
    }

    cout << "Arquivo de saída escrito com sucesso!" << endl;

    // Fecha os arquivos após o processamento
    aqHorario.close();
    aqAlocacao.close();
    aqSaida.close();

    return 0;  // Retorna 0 indicando que o programa terminou corretamente
}
