#include <iostream>

using namespace std;

int Fibonacci(int posicao) {
	if (posicao == 0)
		return 0;
	if (posicao == 1)
		return 1;

	return Fibonacci(posicao - 1) + Fibonacci(posicao - 2);
}

int main()
{
	int posicao, valor;
	cout << "Digite o elemento de fibonacci que voce deseja: ";
	cin >> posicao;

	valor = Fibonacci(posicao);

	cout << "O valor de Fibonacci " << posicao << " e ";
	cout << valor << endl;

	return 0;
}