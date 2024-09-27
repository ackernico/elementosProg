#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream arquivo;

    arquivo.open("teste.csv", ios::out);

    arquivo << "isso,eh,um,teste" << "\n" << "silvio,santos,morreu";

    arquivo.close();

    return 0;
}
