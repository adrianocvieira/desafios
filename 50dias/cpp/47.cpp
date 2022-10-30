#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <list>
#include <ctime>
#include <conio.h>

using namespace std;

const int c_tamanhoProduto = 20;
const vector<int> codigos = { 100, 101, 102, 103, 104, 105 };
int codigoGeralPedido = 0;

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


class PedidoUsuario {
public:
	PedidoUsuario(string NomeUsuario, int codigoPedido) :
		m_nomeUsuario(NomeUsuario),
		m_codigoPedido(codigoPedido)
	{
		m_data = time(0);
	}

	void RegistraPedido(int codigo, int quantidade) {
		m_pedido[codigo] += quantidade;
	}

	void ImprimePedido() const {
		cout << "==============================================" << endl;
		cout << "                Seu pedido                    " << endl;
		cout << "==============================================" << endl;
		cout << "  Produto             |  Quant  |  Preco" << endl;
		cout << "----------------------------------------------" << endl;
		float precoTotal = 0;
		for (auto item : m_pedido) {
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

	void ImprimeRelatorioPedido() const {
		char* dataHora = ctime(&m_data);

		cout << endl;
		cout << " Pedido n: " << m_codigoPedido << endl;
		cout << " Cliente: " << m_nomeUsuario << endl;
		cout << " Data: " << dataHora << endl;
		ImprimePedido();
	}

private:
	int m_codigoPedido;
	string m_nomeUsuario;
	time_t m_data;
	map<int, int> m_pedido = { {codigos[0], 0},
								 {codigos[1], 0},
								 {codigos[2], 0},
								 {codigos[3], 0},
								 {codigos[4], 0},
								 {codigos[5], 0} };

};

list<PedidoUsuario> pedidosTotais;

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

void LePedidoDoUsuario() {
	codigoGeralPedido++;
	string nomeUsuario;
	cout << "Digite o seu nome: ";
	getline(cin, nomeUsuario);

	PedidoUsuario pedidoAtual(nomeUsuario, codigoGeralPedido);

	int opcao, quantidade;
	system("cls");
	do {
		ImprimeCardapio();
		pedidoAtual.ImprimePedido();

		LeOpcoesDoUsuario(opcao, quantidade);

		if (opcao != 0) {
			system("cls");
			if (ValidaInformacoes(opcao, quantidade)) {
				pedidoAtual.RegistraPedido(opcao, quantidade);
			}
		}

	} while (opcao != 0);

	pedidosTotais.push_back(pedidoAtual);
	cout << "\n  O seu pedido e o numero:" << codigoGeralPedido << endl;
	cout << "  Efetue o pagamento no caixa." << endl;
	cout << "  Muito obrigado pelo seu pedido!" << endl;
	cout << "\nTecle ENTER para sair!";
	getch();
}

int ImprimeMenuSistema() {
	cout << "==========================================" << endl;
	cout << "        Lancheria do Juquinha             " << endl;
	cout << "==========================================" << endl;
	cout << "  1 - Fazer pedido " << endl;
	cout << "  9 - Sair " << endl;
	cout << "------------------------------------------" << endl;
	int opcaoSistema = 0;
	do {
		cout << "Digite a opcao: ";
		cin >> opcaoSistema;
		cin.ignore();
	} while (opcaoSistema != 1 and opcaoSistema != 9);
	return opcaoSistema;
}

void ImprimePedidosDoDia() {
	for (auto pedido : pedidosTotais) {
		pedido.ImprimeRelatorioPedido();
	}
}

int main()
{
	bool continuarSistema = false;
	int quantidade = 0;
	do {
		system("cls");
		int opcaoSistema = ImprimeMenuSistema();
		continuarSistema = opcaoSistema != 9;
		if (continuarSistema) {
			LePedidoDoUsuario();
		}
	} while (continuarSistema);

	ImprimePedidosDoDia();
	return 0;
}