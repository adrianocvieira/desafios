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

string CodificaTexto(const string& textoOriginal)
{
	string textoCodificado = "";
	for (auto letra : textoOriginal) {
		textoCodificado += letra + 3;
	}

	return textoCodificado;
}

int main()
{
	string textoOriginal = LerTextoUsuario("Digite um texto: ");
	string textoCodificado = CodificaTexto(textoOriginal);

	cout << "Texto codificado: " << textoCodificado << endl;
	return 0;
}