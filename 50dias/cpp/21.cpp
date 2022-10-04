#include <iostream>
#include <fstream>
#include <list>

using namespace std;

void lerPalavras(list<string>& palavras) {
    ifstream inputFile;
    inputFile.open("input.txt");
    
    string palavra;
    while (inputFile >> palavra)
        palavras.push_back(palavra);
    inputFile.close();
}

void ordenaPalavrasPorTamanhoEmOrdemDescrescente (
    list<string>& palavras
)
{
    auto ordenador = []
    (const string& first, const string& second) {
        return first.size() > second.size();
    };
    palavras.sort(ordenador);
}

void preencheMaioresPalavras(
    list<string>& palavras,
    list<string>& maioresPalavras
)
{
    int tamanhoMaiorPalavra = palavras.front().size();
    for (auto palavra : palavras) {
        if (palavra.size() == tamanhoMaiorPalavra)
            maioresPalavras.push_back(palavra);
    }
}

void escreveMaioresPalavrasNoArquivo(list<string>& palavras) {
    list<string> maioresPalavras;
    preencheMaioresPalavras(palavras, maioresPalavras);
    
    ofstream outputFile;
    outputFile.open("output.txt");
    
    if (maioresPalavras.size() > 1)
        outputFile << "As maiores palavras são: " << endl;
    else
        outputFile << "A maior palavra é: ";
    
    for (auto palavra : maioresPalavras)
        outputFile << palavra << endl;
    
    outputFile.close();
}

int main()
{
    list<string> palavras;
    
    lerPalavras(palavras);
    ordenaPalavrasPorTamanhoEmOrdemDescrescente(palavras);
    
    escreveMaioresPalavrasNoArquivo(palavras);
    
    return 0;
}