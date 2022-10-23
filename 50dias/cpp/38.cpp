#include <iostream>

using namespace std;

bool EhBissexto(int ano) {
	bool divisivelPor4 = (ano % 4) == 0;
	bool divisivelPor100 = (ano % 100) == 0;
	bool divisivelPor400 = (ano % 400) == 0;

	bool divisivelPor4ENaoPor100 = divisivelPor4 &&
		!divisivelPor100;
	bool divisivelPorTudo = divisivelPor4 &&
		divisivelPor100 &&
		divisivelPor400;

	return divisivelPor4ENaoPor100 || divisivelPorTudo;
}

bool ContinuarLendo() {
	string continuar;
	cout << "Quer continuar? [s]im/[n]ao: ";
	cin >> continuar;
	cout << endl << endl;
	return continuar == "s";
}

void ImprimeResultado(bool ehBissexto, int ano) {
	cout << "O ano " << ano << " ";
	if (!ehBissexto) {
		cout << "nao ";
	}
	cout << "e bissexto!" << endl;
}

int main()
{
	do {
		int ano;
		cout << "Digite um ano: ";
		cin >> ano;

		ImprimeResultado(EhBissexto(ano), ano);
	} while (ContinuarLendo());

	return 0;
}