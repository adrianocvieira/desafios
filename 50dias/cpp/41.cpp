#include <iostream>
#include <list>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

const int c_BytesInMB = 1024 * 1024;
map<string, unsigned long> usuarios;

void LeTextoDoArquivo(
	const string& nomeDoArquivo,
	list<string>& texto)
{
	ifstream inputFile;
	inputFile.open(nomeDoArquivo);

	string linha;
	while (getline(inputFile, linha)) {
		texto.push_back(linha);
	}
	inputFile.close();
}

void EscreveTextoNoArquivo(
	const string& nomeDoArquivo,
	const list<string>& texto)
{
	ofstream outputFile;
	outputFile.open(nomeDoArquivo);

	for (auto linha : texto)
		outputFile << linha << endl;

	outputFile.close();
}

void PreencheInformacoesUsuarios(const list<string>& texto) {
	for (auto linha : texto) {
		string nomeUsuario;
		unsigned long espacoUtilizado;
		stringstream input_stringStream{ linha };

		input_stringStream >> nomeUsuario >> espacoUtilizado;
		usuarios[nomeUsuario] = espacoUtilizado;
	}
}

unsigned long CalculaEspacoTotal() {
	unsigned long espacoTotal = 0;
	for (auto item : usuarios) {
		espacoTotal += item.second;
	}
	return espacoTotal;
}

float ConverteBytesParaMegabytes(unsigned long espacoEmBytes) {
	return float(espacoEmBytes) / c_BytesInMB;
}

list<string> CriaRelatorio() {
	list<string> relatorio{};
	unsigned long espacoTotal = CalculaEspacoTotal();
	float espacoTotalEmMB = ConverteBytesParaMegabytes(espacoTotal);

	relatorio.push_back("ACME Inc.    Uso do espaço em disco pelos usuários");
	relatorio.push_back("----------------------------------------------------");
	relatorio.push_back("Nr.  Usuário        Espaço utilizado     % do uso");

	stringstream linhaDoRelatorio;
	int numero = 1;
	int quantidadeUsuarios = 0;
	for (auto item : usuarios) {
		string nomeUsuario = item.first;
		unsigned long espacoDoUsuario = item.second;
		float espacoEmMB = ConverteBytesParaMegabytes(espacoDoUsuario);
		float porcentagem = espacoEmMB * 100 / espacoTotalEmMB;

		linhaDoRelatorio.str(string());
		linhaDoRelatorio << left << setw(5) << numero;
		linhaDoRelatorio << setw(15) << nomeUsuario;
		linhaDoRelatorio << right << fixed << setprecision(2);
		linhaDoRelatorio << setw(7) << espacoEmMB << " MB";
		linhaDoRelatorio << setw(11) << " ";
		linhaDoRelatorio << setw(6) << porcentagem << "%";

		relatorio.push_back(linhaDoRelatorio.str());
		numero++;
		quantidadeUsuarios++;
	}

	relatorio.push_back("");
	linhaDoRelatorio.str(string());
	linhaDoRelatorio << "Espaco total ocupado : " << espacoTotalEmMB << " MB";
	relatorio.push_back(linhaDoRelatorio.str());

	linhaDoRelatorio.str(string());
	linhaDoRelatorio << "Espaco médio ocupado : " << espacoTotalEmMB / quantidadeUsuarios << " MB";
	relatorio.push_back(linhaDoRelatorio.str());

	return relatorio;
}

int main()
{
	list<string> texto;
	LeTextoDoArquivo("usuarios.txt", texto);

	PreencheInformacoesUsuarios(texto);

	list<string> relatorio = CriaRelatorio();
	EscreveTextoNoArquivo("relatorio.txt", relatorio);
	return 0;
}