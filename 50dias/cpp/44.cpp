#include <iostream>
#include <iomanip>

using namespace std;

const float c_prop_aumento_taxa_anual = 0.10;

int main()
{
    float salarioInicial;
    int anoContratacao, anoFinal;

    cout << "Digite o salario inicial: R$ ";
    cin >> salarioInicial;
    cout << "Digite o ano de contratacao: ";
    cin >> anoContratacao;
    cout << "Digite o ano que voce quer saber o salario: ";
    cin >> anoFinal;

    int diferencaAnos = anoFinal - anoContratacao;
    float porc_aumento = 0.015;
    float salarioFinal = salarioInicial;
    for (int i = 0; i < diferencaAnos; i++) {
        salarioFinal += salarioFinal * porc_aumento;
        porc_aumento += porc_aumento * c_prop_aumento_taxa_anual;
    }
    cout << "O salario do funcionario em ";
    cout << anoFinal << " sera R$ " << fixed;
    cout << setprecision(2) << salarioFinal << endl << endl;

    return 0;
}