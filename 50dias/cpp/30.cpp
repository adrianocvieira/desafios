#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string LerTextoUsuario(const string& mensagem)
{
    cout << mensagem;
    string texto;
    getline(cin, texto);
    return texto;
}

string RemoveCensuraTexto(const string& textoCensurado, const string& vogais)
{
    string textoOriginal;
    int contadorVogais = 0;
    for (int i = 0; i < textoCensurado.size(); i++) {
        if (textoCensurado[i] == '*') {
            textoOriginal += vogais[contadorVogais];
            contadorVogais++;
        }
        else {
            textoOriginal += textoCensurado[i];
        }
    }
    return textoOriginal;
}

int main()
{
    string textoCensurado = LerTextoUsuario("Digite um texto: ");
    string vogais = LerTextoUsuario("Digite as vogais censuradas: ");

    string textoOriginal = RemoveCensuraTexto(textoCensurado, vogais);

    cout << "Texto original: " << textoOriginal << endl;

    return 0;
}
