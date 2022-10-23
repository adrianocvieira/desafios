#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int QUANTIDADE_PROJETOS = 10;
vector<float> orcamentoProjetos;

void LeCodigoProjeto(int& codigoProjeto) {
	bool codigoProjetoValido = false;
	do {
		cout << "Digite o codigo do projeto [1-";
		cout << QUANTIDADE_PROJETOS << "]: ";
		cin >> codigoProjeto;
		codigoProjetoValido = codigoProjeto >= 0 &&
			codigoProjeto <= QUANTIDADE_PROJETOS;
	} while (!codigoProjetoValido);
}

void LeValor(float& valor) {
	bool valorValido = false;
	do {
		cout << "Digite o valor [>0]: ";
		cin >> valor;
		valorValido = valor > 0.00;
	} while (!valorValido);
}

void LeTipo(char& tipo) {
	bool tipoValido = false;
	do {
		cout << "Digite o tipo de receita [R/D]: ";
		cin >> tipo;

		tipoValido = tipo == 'R' ||
			tipo == 'D';
	} while (!tipoValido);
}

void LeInformacoesDoUsuario(
	int& codigoProjeto,
	float& valor,
	char& tipo)
{
	LeCodigoProjeto(codigoProjeto);
	if (codigoProjeto > 0) {
		LeValor(valor);
		LeTipo(tipo);
	}
}

void RegistraInformacoes(
	int codigoProjeto,
	float valor,
	char tipo)
{
	if (tipo == 'R') {
		orcamentoProjetos[codigoProjeto - 1] += valor;
	}
	else {
		orcamentoProjetos[codigoProjeto - 1] -= valor;
	}
}

void ImprimeInformacoesProjetos() {
	for (int i = 0; i < QUANTIDADE_PROJETOS; i++) {
		cout << "---------------------" << endl;
		cout << "Projeto codigo " << i + 1 << endl;
		cout << "  Saldo: R$ " << fixed << setprecision(2);
		cout << orcamentoProjetos[i] << endl;
		cout << "---------------------" << endl;
	}
}

int main()
{
	orcamentoProjetos.resize(QUANTIDADE_PROJETOS);

	int codigoProjeto{ 0 };
	float valor{ 0.00 };
	char tipo{ ' ' };
	do {
		LeInformacoesDoUsuario(codigoProjeto, valor, tipo);
		if (codigoProjeto > 0) {
			RegistraInformacoes(codigoProjeto, valor, tipo);
		}
	} while (codigoProjeto != 0);

	ImprimeInformacoesProjetos();

	return 0;
}