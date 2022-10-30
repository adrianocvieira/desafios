#include <iostream>
#include <map>
#include <iomanip>
#include <conio.h>

using namespace std;

map<int, string> candidatos = { {19, "Leonardo"},
                                {27, "Luizinho"},
                                {33, "Alfredo"},
                                {42, "Eymael"},
                                {500, "Branco"} };
map<int, int> votacao = { {19, 0},
                          {27, 0},
                          {33, 0},
                          {42, 0},
                          {500, 0} };

int votosNulos = 0;
int votosTotais = 0;

void ImprimeMenu() {
    cout << "---------------------------------------------------" << endl;
    cout << "        Sistema de eleicoes presidenciais          " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Vote em um dos candidatos: " << endl;
    cout << "   19 - Leonardo" << endl;
    cout << "   27 - Luizinho" << endl;
    cout << "   33 - Alfredo" << endl;
    cout << "   42 - Eymael" << endl;
    cout << "  500 - Voto em Branco" << endl;
    cout << "---------------------------------------------------" << endl;
}

bool ConfirmaVoto(int numeroVotado) {
    if (candidatos.find(numeroVotado) != candidatos.end()) {
        cout << "O seu voto e no candidato ";
        cout << candidatos[numeroVotado] << endl;
    }
    else {
        cout << "Candidato invalido!" << endl;
    }
    string confirmacao;
    cout << "Deseja confirmar? [s]im/[n]ao: ";
    cin >> confirmacao;
    return confirmacao == "s";
}

int LeVotoEleitor() {
    int numeroVotado = 0;
    bool votacaoEmAndamento = false;
    do {
        system("cls");
        ImprimeMenu();
        cout << "Digite o numero do candidato: ";
        cin >> numeroVotado;
        bool votoConfirmado = numeroVotado != 0 ? ConfirmaVoto(numeroVotado) : true;
        votacaoEmAndamento = !votoConfirmado;
    } while (votacaoEmAndamento);
    return numeroVotado;
}

void ContabilizaVoto(int numeroVotado) {
    votosTotais++;
    if (votacao.find(numeroVotado) != votacao.end()) {
        votacao[numeroVotado]++;
    }
    else {
        votosNulos++;
    }
}

void ImprimeRelatorioEleicao() {
    if (votosTotais != 0) {
        int votosBrancos = votacao[500];
        int votosInvalidos = votosBrancos + votosNulos;
        int votosValidos = votosTotais - votosInvalidos;
        system("cls");
        cout << "--------------------------------------" << endl;
        cout << "       Votos validos por candidato    " << endl;
        cout << "--------------------------------------" << endl;

        for (auto item : votacao) {
            int numero = item.first;
            if (numero != 500) {
                string nome = candidatos[numero];
                int quant = votacao[numero];
                int porc = float(quant * 100) / votosValidos;
                cout << nome << " - Votos: " << quant;
                cout << " : " << fixed << setprecision(2);
                cout << porc << "%" << endl;
            }
        }

        float porcBranco = float(votosBrancos * 100) / votosTotais;
        float porcNulos = float(votosNulos * 100) / votosTotais;
        cout << "--------------------------------------" << endl;
        cout << "Votos Brancos: " << votosBrancos;
        cout << " - " << porcBranco << "%" << endl;
        cout << "Votos Nulos: " << votosNulos;
        cout << " - " << porcNulos << "%" << endl;
    }
}

int main()
{
    bool continuaVotacao = false;
    do {
        int numeroVotado = LeVotoEleitor();
        continuaVotacao = numeroVotado != 0;
        if (continuaVotacao) {
            ContabilizaVoto(numeroVotado);
            cout << "Voto contabilizado!" << endl;
            cout << "Pressione Enter tecla para continuar!";
            getch();
        }
    } while (continuaVotacao);
    ImprimeRelatorioEleicao();

    return 0;
}