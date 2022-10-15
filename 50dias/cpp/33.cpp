#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

const vector<char> vogais = { 'a', 'e', 'i', 'o', 'u',
							 'A', 'E', 'I', 'O', 'U' };

void LerArquivo(const string& nomeDoArquivo, list<string>& texto) {
	ifstream inputFile;
	inputFile.open(nomeDoArquivo);

	string linha;
	while (getline(inputFile, linha)) {
		texto.push_back(linha);
	}
	inputFile.close();
}

void EscreveArquivo(const string& nomeDoArquivo, const list<string>& texto) {
	ofstream outputFile;
	outputFile.open(nomeDoArquivo);

	for (auto linha : texto)
		outputFile << linha << endl;

	outputFile.close();
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

string RemoveCensuraTexto(
	const string& textoCensurado,
	const string& vogais,
	int& contadorVogais)
{
	string textoOriginal;
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

string CodificaTexto(const string& textoOriginal)
{
	string textoCodificado = "";
	for (auto letra : textoOriginal) {
		textoCodificado += letra + 3;
	}

	return textoCodificado;
}

string DecodificaTexto(const string& textoCodificado)
{
	string textoOriginal = "";
	for (auto letra : textoCodificado)
	{
		textoOriginal += letra - 3;
	}
	return textoOriginal;
}

void CodificaTextoCompleto(const list<string>& textoCompleto, list<string>& textoCodificado) {
	for (auto linha : textoCompleto) {
		textoCodificado.push_back(CodificaTexto(linha));
	}
}

void DecodificaTextoCompleto(const list<string>& textoCompleto, list<string>& textoDecodificado) {
	for (auto linha : textoCompleto) {
		textoDecodificado.push_back(DecodificaTexto(linha));
	}
}

void CensuraTextoCompleto(
	const list<string>& textoCompleto,
	list<string>& textoCensurado,
	string& vogais
)
{
	for (auto linha : textoCompleto) {
		string linhaCensurada;
		CensuraTexto(linha, linhaCensurada, vogais);
		textoCensurado.push_back(linhaCensurada);
	}
}

void RemoveCensuraTextoCompleto(
	const list<string>& textoCensurado,
	list<string>& textoCompleto,
	string& vogais
)
{
	int contadorVogais = 0;
	for (auto linhaCensurada : textoCensurado) {
		string linha = RemoveCensuraTexto(linhaCensurada, vogais, contadorVogais);
		textoCompleto.push_back(linha);
	}
}

void CodificaArquivoTexto() {
	list<string> texto, textoCensurado, textoCodificado, chave;
	string vogais;

	LerArquivo("entrada.txt", texto);
	CodificaTextoCompleto(texto, textoCodificado);
	CensuraTextoCompleto(textoCodificado, textoCensurado, vogais);
	chave.push_back(vogais);

	EscreveArquivo("cod.txt", textoCodificado);
	EscreveArquivo("chave.txt", chave);
}

void DecodificaArquivoTexto() {
	list<string> texto, textoCensurado, textoCodificado, chave;
	string vogais;
	LerArquivo("cod.txt", textoCensurado);
	LerArquivo("chave.txt", chave);

	vogais = chave.front();

	RemoveCensuraTextoCompleto(textoCensurado, textoCodificado, vogais);
	DecodificaTextoCompleto(textoCodificado, texto);

	EscreveArquivo("saida.txt", texto);
}

int main()
{
	CodificaArquivoTexto();

	DecodificaArquivoTexto();
	return 0;
}