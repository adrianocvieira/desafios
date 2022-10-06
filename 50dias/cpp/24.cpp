#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int GeraNumeroEntre1e10() {
    // rand() % 10 gera um numero entre 0 e 9
    return (rand() % 10) + 1;
}

bool EfetuaQuestao(int multiplicando, int multiplicador) {
    int resposta;
    cout << multiplicando << "x" << multiplicador << " = ";
    cin >> resposta;

    return resposta == multiplicador * multiplicando;
}

void UsuarioErrou(int multiplicando, int multiplicador) {
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
    bool continuar = true;
    int multiplicando = 0;
    int multiplicador = 0;
    do {
        while (continuar) {
            multiplicando = GeraNumeroEntre1e10();
            multiplicador = GeraNumeroEntre1e10();

            continuar = EfetuaQuestao(multiplicando,
                multiplicador);
        }

        UsuarioErrou(multiplicando, multiplicador);
        continuar = UsuarioQuerContinuar();
    } while (continuar);

    return 0;
}