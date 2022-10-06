#include <iostream>
#include <list>
#include <sstream>

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

void EfetuaOperacoes(list<int> inteirosEntrada) {
    int tamanhoLista = inteirosEntrada.size();
    if (tamanhoLista > 0) {
        float soma = 0;
        int menor = inteirosEntrada.front();
        int maior = menor;

        for (int i : inteirosEntrada) {
            soma += i;
            if (i < menor)
                menor = i;
            if (i > maior)
                maior = i;
        }

        float media = soma / tamanhoLista;
        cout << "O maior valor é " << maior << endl;
        cout << "O menor valor é " << menor << endl;
        cout << "A média dos valores é " << media << endl;

    }
    else
        cout << "Lista está vazia!" << endl;
}

int main()
{
    string entrada = LeiaEntradaUsuario();

    list<int> inteirosEntrada;
    inteirosEntrada = ConverteListaStringsParaInteiros(entrada);

    EfetuaOperacoes(inteirosEntrada);
    return 0;
}