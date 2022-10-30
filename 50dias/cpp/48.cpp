#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <list>
#include <ctime>
#include <conio.h>
#include <sstream>
#include <fstream>

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

class Pedido {
public:
	Pedido operator+(Pedido& outro_pedido) {
		Pedido novoPedido;
		for (auto item : m_pedido) {
			int codigo = item.first;
			novoPedido.m_pedido[codigo] = m_pedido[codigo] + outro_pedido.m_pedido[codigo];
		}
		return novoPedido;
	}

	string CriaTextoPedido() const {
		stringstream stringPedido;
		stringPedido << "==============================================" << endl;
		stringPedido << "                   Pedido                     " << endl;
		stringPedido << "==============================================" << endl;
		stringPedido << "  Produto             |  Quant  |  Preco" << endl;
		stringPedido << "----------------------------------------------" << endl;
		float precoTotal = 0;
		for (auto item : m_pedido) {
			int codigo = item.first;
			int quantidade = item.second;
			if (quantidade > 0) {
				string nome = produtos[codigo];
				float preco = precos[codigo];
				stringPedido << "  " << nome << setw(c_tamanhoProduto - nome.size()) << " ";
				stringPedido << "|  " << setw(3) << quantidade << "    |  R$ ";
				stringPedido << std::fixed << std::setprecision(2);
				stringPedido << quantidade * preco << endl;
				precoTotal += quantidade * preco;
			}
		}
		stringPedido << "----------------------------------------------" << endl;
		stringPedido << "  Preco Total: R$ " << precoTotal << endl;
		stringPedido << "----------------------------------------------" << endl;
		return stringPedido.str();
	}

	void ImprimePedido() const {
		cout << CriaTextoPedido();
	}

protected:
	map<int, int> m_pedido = { {codigos[0], 0},
							   {codigos[1], 0},
							   {codigos[2], 0},
							   {codigos[3], 0},
							   {codigos[4], 0},
							   {codigos[5], 0} };
};

class PedidoUsuario : public Pedido {
public:
	PedidoUsuario(string nomeUsuario, int codigoPedido) :
		Pedido(),
		m_nomeUsuario(nomeUsuario),
		m_codigoPedido(codigoPedido)
	{
		m_data = time(0);
	}

	void RegistraPedido(int codigo, int quantidade) {
		m_pedido[codigo] += quantidade;
	}

	string CriaTextoRelatorio() const {
		stringstream stringRelatorio;

		char* dataHora = ctime(&m_data);

		stringRelatorio << endl;
		stringRelatorio << " Pedido n: " << m_codigoPedido << endl;
		stringRelatorio << " Cliente: " << m_nomeUsuario << endl;
		stringRelatorio << " Data: " << dataHora << endl;
		stringRelatorio << CriaTextoPedido();
		return stringRelatorio.str();

	}

	void ImprimeRelatorioPedido() const {
		cout << CriaTextoRelatorio();
	}

private:
	int m_codigoPedido;
	string m_nomeUsuario;
	time_t m_data;

};

list<PedidoUsuario> pedidosTotais;

void EscreveTextoNoArquivo(
	const string& nomeDoArquivo,
	const list<string>& texto)
{
	ofstream outputFile;
	outputFile.open(nomeDoArquivo, std::ios_base::app);

	for (auto linha : texto)
		outputFile << linha << endl;

	outputFile.close();
}

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


void ImprimeMenu(const PedidoUsuario& pedidoAtual) {
	ImprimeCardapio();
	pedidoAtual.ImprimePedido();
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
		ImprimeMenu(pedidoAtual);

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
	int opcaoSistema;
	do {
		cout << "Digite a opcao: ";
		cin >> opcaoSistema;
		cin.ignore();
	} while (opcaoSistema != 1 and opcaoSistema != 9);
	return opcaoSistema;
}

string GeraCabecalhoRelatorio(string tituloCabecalho) {
	time_t agora = time(0);
	char* dataHora = ctime(&agora);
	stringstream cabecalhoRelatorio;
	cabecalhoRelatorio << "==============================================" << endl;
	cabecalhoRelatorio << "         " << tituloCabecalho << "          " << endl;
	cabecalhoRelatorio << "   " << dataHora << endl;
	cabecalhoRelatorio << "==============================================" << endl;
	return cabecalhoRelatorio.str();
}

void ImprimePedidosDoDia() {
	list<string> textoRelatorioPedidosDoDia;
	textoRelatorioPedidosDoDia.push_back(GeraCabecalhoRelatorio("RELATORIO DE PEDIDOS DO DIA"));
	for (auto pedido : pedidosTotais) {
		textoRelatorioPedidosDoDia.push_back(pedido.CriaTextoRelatorio());
	}

	EscreveTextoNoArquivo("pedidos.txt", textoRelatorioPedidosDoDia);
}

void ImprimeRelatorioVendasDia() {
	Pedido todosPedidosDoDia;
	for (auto pedido : pedidosTotais) {
		todosPedidosDoDia = todosPedidosDoDia + pedido;
	}

	list<string> textoRelatorioVendasDoDia;
	textoRelatorioVendasDoDia.push_back(GeraCabecalhoRelatorio("RELATORIO VENDAS DO DIA"));
	textoRelatorioVendasDoDia.push_back(todosPedidosDoDia.CriaTextoPedido());
	EscreveTextoNoArquivo("relatorio.txt", textoRelatorioVendasDoDia);
}

void ImprimeRelatoriosDoDia() {
	ImprimePedidosDoDia();
	ImprimeRelatorioVendasDia();
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

	ImprimeRelatoriosDoDia();
	return 0;
}