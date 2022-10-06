#include <iostream>
#include <list>
#include <sstream>
#include <cmath>

using namespace std;

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

string LeiaEntradaUsuario() {
    string entrada;

    cout << "O formato da entrada deve ser o seguinte:" << endl;
    cout << "[1, 2, 3, 4, 5, 6]" << endl;
    cout << "Digite uma lista de inteiros: ";
    getline(cin, entrada);

    return entrada;
}

bool EhQuadradoPerfeito(int i) {
    int raizTruncada = sqrt(i);

    return raizTruncada * raizTruncada == i;
}

void EfetuaOperacoes(list<int> inteirosEntrada) {
    int tamanhoLista = inteirosEntrada.size();
    if (tamanhoLista > 0) {
        list<int> quadradosPerfeitos;
        for (int i : inteirosEntrada) {
            if (EhQuadradoPerfeito(i))
                quadradosPerfeitos.push_back(i);
        }

        cout << "Os valores da lista que são ";
        cout << "quadrado perfeito: " << endl;
        cout << "[ ";
        for (int i : quadradosPerfeitos) {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
    else
        cout << "A lista está vazia!";
}

int main()
{
    string entrada = LeiaEntradaUsuario();

    list<int> inteirosEntrada;
    inteirosEntrada = ConverteListaStringsParaInteiros(entrada);

    EfetuaOperacoes(inteirosEntrada);
    return 0;
}