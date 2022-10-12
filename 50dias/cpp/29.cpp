#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const vector<char> vogais = { 'a', 'e', 'i', 'o', 'u',
                             'A', 'E', 'I', 'O', 'U' };

string LerTextoUsuario()
{
    cout << "Digite um texto: ";
    string texto;
    getline(cin, texto);
    return texto;
}

bool EhVogal(const char& letra)
{
    auto it = find(vogais.begin(), vogais.end(), letra);
    bool encontrou = it != vogais.end();
    return encontrou;
}

void CensuraTexto(
    const string& texto,
    string& textoCensurado,
    string& vogais
)
{
    for (int i = 0; i < texto.size(); i++) {
        if (EhVogal(texto[i])) {
            textoCensurado += '*';
            vogais += texto[i];
        }
        else {
            textoCensurado += texto[i];
        }
    }
}

int main()
{
    string texto = LerTextoUsuario();

    string textoCensurado, vogais;
    CensuraTexto(texto, textoCensurado, vogais);

    cout << "Texto censurado: " << textoCensurado << endl;
    cout << "Vogais: " << vogais << endl;

    return 0;
}
