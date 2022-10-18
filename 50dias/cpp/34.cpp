#include <iostream>
#include <list>
#include <numeric>
#include <iomanip>

using namespace std;

class Aluno {
public:
	Aluno(string _nome) {
		nome = _nome;
		media = 0;
	};

	bool operator<(const Aluno& outroAluno) {
		return media < outroAluno.media;
	}

	void PreencheNotas(list<float> novasNotas) {
		notas = novasNotas;
	};

	void CalculaMedia() {
		media = accumulate(notas.begin(), notas.end(), 0);
		media /= notas.size();
	}

	float GetMedia() {
		return media;
	}

	string GetNome() {
		return nome;
	}

private:
	string nome;
	list<float> notas;
	float media;
};

list<Aluno> alunos;

bool DesejaContinuar() {
	string resposta;
	cout << "Deseja continuar? [s]im/[n]ao : ";
	cin >> resposta;
	return resposta == "s";
}

void LeNomeAlunos() {
	do {
		string nome;
		cout << "Digite o nome do aluno: ";
		cin >> nome;
		auto aluno = Aluno(nome);
		alunos.push_back(aluno);
	} while (DesejaContinuar());
}

void LeNotasAlunos() {
	for (auto& aluno : alunos) {
		cout << endl << endl;
		cout << "Digite as notas do " << aluno.GetNome() << endl;
		list<float> notas;
		for (int i = 1; i <= 4; i++) {
			float nota;
			cout << "Digite a nota " << i << " : ";
			cin >> nota;
			notas.push_back(nota);
		}
		aluno.PreencheNotas(notas);
		aluno.CalculaMedia();
	}
}

void ImprimeAlunos() {
	cout << endl << "---------------------------------" << endl;
	cout << std::fixed << std::setprecision(1);
	for (auto aluno : alunos) {
		cout << aluno.GetNome() << " - " << aluno.GetMedia() << endl;
	}
}

int main()
{
	LeNomeAlunos();
	LeNotasAlunos();

	alunos.sort();
	alunos.reverse();

	ImprimeAlunos();
	return 0;
}