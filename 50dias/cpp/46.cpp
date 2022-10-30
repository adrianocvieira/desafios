#include <iostream>
#include <random>
#include <fstream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

void LerArquivo(
    const string& nomeDoArquivo,
    list<string>& texto)
{
    ifstream inputFile;
    inputFile.open(nomeDoArquivo);

    string linha;
    while (getline(inputFile, linha)) {
        texto.push_back(linha);
    }
    inputFile.close();
}

void EscreveArquivo(
    const string& nomeDoArquivo,
    const list<string> texto
)
{
    ofstream outputFile;
    outputFile.open(nomeDoArquivo);

    for (auto linha : texto) {
        outputFile << linha << endl;
    }
    outputFile.close();
}

void EmbaralhaPalavraMantendoPrimeiraUltimaLetra(
    string& palavra
)
{
    if (palavra.size() > 1) {
        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(++palavra.begin(),
            --palavra.end(),
            g);
    }
}

int main()
{
    list<string> texto;
    LerArquivo("entrada.txt", texto);

    list<string>novoTexto;
    for (auto linha : texto) {
        stringstream ss(linha);
        string palavra;
        string novaLinha;
        while (ss >> palavra) {
            EmbaralhaPalavraMantendoPrimeiraUltimaLetra(palavra);
            novaLinha += palavra + " ";
        }
        novoTexto.push_back(novaLinha);
    }

    EscreveArquivo("saida.txt", novoTexto);
    return 0;
}