#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void LeTexto(string& texto) {
	cout << "Digite um texto: ";
	getline(cin, texto);
}

void NormalizaTexto(string& texto) {
	erase(texto, ' ');
	erase(texto, '.');
	erase(texto, ',');
	erase(texto, '!');
	erase(texto, '?');
	erase(texto, ':');
	erase(texto, ';');
	erase(texto, '-');
	std::for_each(texto.begin(), texto.end(), [](char& c) {
		c = ::tolower(c);
		});
}

bool EhPalindromo(string texto) {
	int inicioTexto = 0;
	int fimTexto = texto.size() - 1;

	while (inicioTexto < fimTexto) {
		if (texto[inicioTexto] != texto[fimTexto])
			return false;
		inicioTexto++;
		fimTexto--;
	}

	return true;
}

int main() {
	string texto, textoEditado;

	LeTexto(texto);
	textoEditado = texto;
	NormalizaTexto(textoEditado);
	bool palindromo = EhPalindromo(textoEditado);

	cout << "-------------------------" << endl;
	cout << "    " << texto << endl;
	cout << "-------------------------" << endl;
	cout << "Texto ";
	if (!palindromo)
		cout << "nao ";
	cout << "e palindromo!" << endl << endl;

	return 0;
}