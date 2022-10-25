#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

const int c_BytesInMB = 1024 * 1024;
const int c_padrao = 1;
const int c_ordenado = 2;
vector<tuple<string, unsigned long>> usuarios;

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
		usuarios.push_back(make_tuple(nomeUsuario, espacoUtilizado));
	}
}

unsigned long CalculaEspacoTotal() {
	unsigned long espacoTotal = 0;
	for (auto item : usuarios) {
		espacoTotal += get<1>(item);
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
		string nomeUsuario = get<0>(item);
		unsigned long espacoDoUsuario = get<1>(item);
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

void ImprimeMenu() {
	cout << "---------------------------------------------------" << endl;
	cout << " Gerador de relatorio de armazenamento por usuário " << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Escolha uma das opcoes: " << endl;
	cout << "  1) Gerar relatorio padrao." << endl;
	cout << "  2) Gerar relatorio ordenado por utilizacao." << endl;
	cout << "---------------------------------------------------" << endl;
}


int LeOpcaoDoUsuario() {
	int opcao;
	bool opcaoInvalida;
	do {
		ImprimeMenu();
		cout << "Digite a opcao: ";
		cin >> opcao;
		opcaoInvalida = opcao < c_padrao&& opcao > c_ordenado;
		if (opcaoInvalida) {
			system("cls");
			cout << endl << "  OPCAO INVALIDA! " << endl;
		}
	} while (opcaoInvalida);
	return opcao;
}

string LeNomeDoRelatorio() {
	string nomeRelatorio;
	cout << "Digite o nome do relatorio: ";
	cin >> nomeRelatorio;
	return nomeRelatorio + string(".txt");
}

void OrdenaInformacoesPorArmazenamento() {
	sort(usuarios.begin(),
		usuarios.end(),
		[](const tuple<string, unsigned long>& a,
			const tuple<string, unsigned long>& b) {
				return get<1>(a) < get<1>(b);
		});
}

int main()
{
	int opcao = LeOpcaoDoUsuario();
	string nomeRelatorio = LeNomeDoRelatorio();

	list<string> texto;
	LeTextoDoArquivo("usuarios.txt", texto);

	PreencheInformacoesUsuarios(texto);

	if (opcao == c_ordenado) {
		OrdenaInformacoesPorArmazenamento();
	}

	list<string> relatorio = CriaRelatorio();
	EscreveTextoNoArquivo(nomeRelatorio, relatorio);
	return 0;
}