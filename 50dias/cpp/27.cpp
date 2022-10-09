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

list<list<int>> ConverteArquivoParaListasInteiros() {
    list<string> linhasDoArquivo = LeArquivoTexto();

    list<list<int>> listasDeInteiros;
    for (string palavra : linhasDoArquivo) {
        list<int> listaInteiros = ConverteListaStringsParaInteiros(palavra);
        listasDeInteiros.push_back(listaInteiros);
    }

    return listasDeInteiros;
}

list<int> OrdenaLista(list<int>& lista) {
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
            i++; j++;
        }
    } while (trocou);
    return listaOrdenada;
}

list<list<int>> OrdenaListas(list<list<int>> listasLidas) {
    list<list<int>> listasOrdenadas;
    for (auto lista : listasLidas) {
        list<int> listaOrdenada = OrdenaLista(lista);
        listasOrdenadas.push_back(listaOrdenada);
    }
    return listasOrdenadas;
}

/*
    Para encontrar o elemento faltante, voce pode ordenar
    a lista, visto que os elementos nao repetem
    exemplo:
        [4, 3, 1, 5, 9, 7, 8, 6, 10]
    ordenada:
        [1, 3, 4, 5, 6, 7, 8, 9, 10]
    O 1 está na primeira posicao.
    Porem o 2 nao está na segunda posicao.
    Entao o numero faltante é o 2.
    Se a lista inteira for percorrida e voce encontrar todos
    significa que o ultimo elemento (no caso do exemplo, o 10)
    é o elemento faltante, pois a lista tem todos os
    elementos de 1 a 9 nas posicoes corretas.
*/

int EncontraElementoFaltante(list<int> lista) {
    int tamanhoLista = lista.size();
    int posicao = 1;
    for (int elemento : lista) {
        if (elemento != posicao)
            return posicao;
        posicao++;
    }
    return tamanhoLista + 1;
}

void EncontraElementoFaltanteNasListas(list<list<int>> listasLidas) {
    for (auto lista : listasLidas) {
        int elemento = EncontraElementoFaltante(lista);
        cout << "Está faltando o numero " << elemento << endl;
    }
}

int main()
{
    list<list<int>> listasLidas = ConverteArquivoParaListasInteiros();
    list<list<int>> listasOrdenadas = OrdenaListas(listasLidas);
    EncontraElementoFaltanteNasListas(listasOrdenadas);

    return 0;
}

















