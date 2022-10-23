#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

const int c_tamanhoProduto = 20;
const vector<int> codigos = { 100, 101, 102, 103, 104, 105 };

map<int, float> precos = { {codigos[0], 1.20},
						   {codigos[1], 1.30},
						   {codigos[2], 1.50},
						   {codigos[3], 1.20},
						   {codigos[4], 1.30},
						   {codigos[5], 1.00} };

map<int, string> produtos = { {codigos[0], "Cachorro Quente"},
							  {codigos[1], "Bauru Simples"},
							  {codigos[2], "Bauru com ovo"},
							  {codigos[3], "Hamburguer"},
							  {codigos[4], "Cheesburguer"},
							  {codigos[5], "Refrigerante"} };

map<int, int> pedido = { {codigos[0], 0},
						 {codigos[1], 0},
						 {codigos[2], 0},
						 {codigos[3], 0},
						 {codigos[4], 0},
						 {codigos[5], 0} };

void ImprimeCardapio() {
	cout << "----------------------------------------------" << endl;
	cout << "  Produto             |  Codigo  |  Preco" << endl;
	cout << "----------------------------------------------" << endl;
	for (auto codigo : codigos) {
		string nome = produtos[codigo];
		float preco = precos[codigo];
		cout << "  " << nome << setw(c_tamanhoProduto - nome.size()) << " ";
		cout << "|  " << codigo << "     |  R$ ";
		cout << std::fixed << std::setprecision(2);
		cout << preco << endl;
	}
	cout << "----------------------------------------------" << endl;
}

void ImprimePedido() {
	cout << "==============================================" << endl;
	cout << "                Seu pedido                    " << endl;
	cout << "==============================================" << endl;
	cout << "  Produto             |  Quant  |  Preco" << endl;
	cout << "----------------------------------------------" << endl;
	float precoTotal = 0;
	for (auto item : pedido) {
		int codigo = item.first;
		int quantidade = item.second;
		if (quantidade > 0) {
			string nome = produtos[codigo];
			float preco = precos[codigo];
			cout << "  " << nome << setw(c_tamanhoProduto - nome.size()) << " ";
			cout << "|  " << setw(3) << quantidade << "    |  R$ ";
			cout << std::fixed << std::setprecision(2);
			cout << quantidade * preco << endl;
			precoTotal += quantidade * preco;
		}
	}
	cout << "----------------------------------------------" << endl;
	cout << "  Preco Total: R$ " << precoTotal << endl;
	cout << "----------------------------------------------" << endl;
}

void ImprimeMenu() {
	ImprimeCardapio();
	ImprimePedido();
}

void LeOpcoesDoUsuario(int& opcao, int& quantidade) {
	cout << "Digite o codigo do produto (0 para sair): ";
	cin >> opcao;
	quantidade = -1;
	if (opcao != 0) {
		cout << "Digite a quantidade: ";
		cin >> quantidade;
	}
}

bool ValidaInformacoes(int opcao, int quantidade) {
	bool produtoExiste = produtos.find(opcao) != produtos.end();
	bool quantidadeValida = quantidade > 0;
	if (!produtoExiste) {
		cout << endl << "  Codigo de produto nao encontrado!";
		cout << endl << endl;
	}
	else {
		if (!quantidadeValida) {
			cout << endl << "  Quantidade digitada eh invalida!";
			cout << endl << endl;
		}
	}

	return produtoExiste && quantidadeValida;
}


void RegistraPedido(int codigo, int quantidade) {
	pedido[codigo] += quantidade;
}

int main()
{
	int opcao, quantidade;
	system("cls");
	do {
		ImprimeMenu();

		LeOpcoesDoUsuario(opcao, quantidade);

		if (opcao != 0) {
			system("cls");
			if (ValidaInformacoes(opcao, quantidade)) {
				RegistraPedido(opcao, quantidade);
			}
		}

	} while (opcao != 0);
	return 0;
}