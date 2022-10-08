#include <iostream>
#include <fstream>
#include <list>
#include <sstream>

using namespace std;

list<string> LeArquivoTexto() {
    list<string> linhasDoArquivo;
    ifstream inputFile;
    inputFile.open("input.txt");

    string linha;
    while (getline(inputFile, linha))
        linhasDoArquivo.push_back(linha);
    inputFile.close();

    return linhasDoArquivo;
}

void RemoveColchetesEspacosDaString(string& entrada) {
    erase(entrada, '[');
    erase(entrada, ']');
    erase(entrada, ' ');
}

list<int> ConverteListaStringsParaInteiros(string entrada) {
    RemoveColchetesEspacosDaString(entrada);

    list<int> inteirosEntrada;
    if (entrada.size() > 0) {
        stringstream sstr(entrada);
        while (sstr.good()) {
            string substring;
            getline(sstr, substring, ',');
            inteirosEntrada.push_back(stoi(substring));
        }
    }

    return inteirosEntrada;
}

void EscreveListaNoArquivo(list<int> lista) {
    ofstream outputFile;
    outputFile.open("input.txt", std::ios_base::app);

    outputFile << "--------------------" << endl;
    outputFile << "[ ";
    for (int i : lista) {
        outputFile << i << " ";
    }
    outputFile << "]" << endl;

    outputFile << "--------------------" << endl;

}

list<list<int>> ConverteArquivoParaListasInteiros() {
    list<string> linhasDoArquivo = LeArquivoTexto();

    list<list<int>> listasDeInteiros;
    for (string palavra : linhasDoArquivo) {
        list<int> listaInteiros = ConverteListaStringsParaInteiros(palavra);
        listasDeInteiros.push_back(listaInteiros);
    }

    return listasDeInteiros;
}

list<int> OrdenaLista(list<int> lista) {

    bool trocou;
    list<int> listaOrdenada = lista;
    do {
        trocou = false;
        auto j = listaOrdenada.begin();
        auto i = j++;
        auto end = listaOrdenada.end();
        while (j != end) {
            if (*i > *j) {
                std::swap(*i, *j);
                trocou = true;
            }
            i++;
            j++;
        }
    } while (trocou);

    return listaOrdenada;
}

void OrdenaListas(list<list<int>> listasLidas) {

    for (auto lista : listasLidas) {
        list<int> listaOrdenada = OrdenaLista(lista);
        EscreveListaNoArquivo(listaOrdenada);
    }
}

int main()
{
    list<list<int>> listasLidas = ConverteArquivoParaListasInteiros();

    OrdenaListas(listasLidas);

    return 0;
}