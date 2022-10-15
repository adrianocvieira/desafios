#include <iostream>
#include <string>

using namespace std;

string LerTextoUsuario(const string& mensagem)
{
	cout << mensagem;
	string texto;
	getline(cin, texto);
	return texto;
}

string DecodificaTexto(const string& textoCodificado)
{
	string textoOriginal = "";
	for (auto letra : textoCodificado) {
		textoOriginal += letra - 3;
	}
	return textoOriginal;
}

int main()
{
	string textoCodificado = LerTextoUsuario("Digite um texto codificado: ");

	string textoOriginal = DecodificaTexto(textoCodificado);

	cout << "Texto decodificado: " << textoOriginal << endl;
	return 0;
}