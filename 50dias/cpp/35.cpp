#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

vector<string> nomeDosAlunos;
list<tuple<string, string>> gruposPossiveis;

void LeNomeDosAlunos() {
	int quantidade;
	cout << "Quantos alunos voce tem? ";
	cin >> quantidade;

	for (int i = 1; i <= quantidade; i++) {
		string nome;
		cout << "Digite o nome do aluno " << i << ": ";
		cin >> nome;
		nomeDosAlunos.push_back(nome);
	}
}

void CriaPossiveisGrupos() {
	for (int i = 0; i < nomeDosAlunos.size() - 1; i++) {
		for (int j = i + 1; j < nomeDosAlunos.size(); j++) {
			auto grupo = tuple(nomeDosAlunos[i], nomeDosAlunos[j]);
			gruposPossiveis.push_back(grupo);
		}
	}
}

void ImprimeGrupos() {
	for (auto grupo : gruposPossiveis) {
		cout << "(" << get<0>(grupo);
		cout << ", ";
		cout << get<1>(grupo) << ")";
		cout << endl;
	}
}


int main()
{
	LeNomeDosAlunos();
	CriaPossiveisGrupos();
	ImprimeGrupos();
	return 0;
}