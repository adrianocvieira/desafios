#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PONTUACAO_BASE = 3;

int placar = 0;
int mult_pontos = 1;
int multiplicando = 0;
int multiplicador = 0;


void InicializaPlacar() {
    mult_pontos = 1;
    placar = 0;
}

void AtualizaPontos(int nivel) {
    placar += mult_pontos * PONTUACAO_BASE;
    if ((nivel % 5) == 0)
        mult_pontos++;
}

int GeraNumeroEntre1e10() {
    // rand() % 10 gera um numero entre 0 e 9
    return (rand() % 10) + 1;
}

bool EfetuaQuestao(int multiplicando, int multiplicador) {
    int resposta;
    cout << "\t";
    cout << multiplicando << "x" << multiplicador << " = ";
    cin >> resposta;

    return resposta == multiplicador * multiplicando;
}

void ImprimeCabecalho(int nivel) {
    system("cls");
    cout << "-------------------------------------------------" << endl;
    cout << " Nivel: " << nivel << "   |   Placar: " << placar;
    cout << "   |   Multiplicador: " << mult_pontos << endl;
    cout << "-------------------------------------------------" << endl;
}

void EfetuaQuestoes() {
    int nivel = 0;
    bool continuar = true;
    do {
        nivel++;

        multiplicando = GeraNumeroEntre1e10();
        multiplicador = GeraNumeroEntre1e10();

        ImprimeCabecalho(nivel);
        continuar = EfetuaQuestao(multiplicando,
            multiplicador);
        if (continuar)
            AtualizaPontos(nivel);
    } while (continuar);
}

void UsuarioErrou() {
    cout << "Infelizmente voce errou!" << endl;
    cout << "O resultado de " << multiplicando << "x";
    cout << multiplicador << " = " << multiplicando * multiplicador;
    cout << endl << endl;
}

bool UsuarioQuerContinuar() {
    char tentarNovamente;
    cout << "Voce quer tentar novamente? [s]im/[n]ao : ";
    cin >> tentarNovamente;
    return tentarNovamente == 's';
}

int main()
{
    srand(time(0));
    do {
        InicializaPlacar();
        EfetuaQuestoes();
        UsuarioErrou();
    } while (UsuarioQuerContinuar());

    return 0;
}