#include <iostream>
#include <list>

using namespace std;

char perguntarContinuacaoLeitura() {
    char continuar;
    do {
        cout << "Continuar lendo? [s]im/[n]ao: ";
        cin >> continuar;
    } while (continuar != 's' and continuar != 'n');
    return continuar;
}

void lerPalavras(list<string>& palavras) {
    string palavra;
    bool continuarLendo = true;
    do {
        cout << endl << "Digite uma palavra: ";
        cin >> palavra;
        
        palavras.push_back(palavra);
        
        char resposta = perguntarContinuacaoLeitura();
        continuarLendo = resposta == 's';
    } while(continuarLendo);
}

void ordenaPalavrasPorTamanhoEmOrdemDescrescente (
    list<string>& palavras
)
{
    auto ordenador = []
    (const string& first, const string& second) {
        return first.size() > second.size();
    };
    palavras.sort(ordenador);
}

void preencheMaioresPalavras(
    list<string>& palavras,
    list<string>& maioresPalavras
)
{
    int tamanhoMaiorPalavra = palavras.front().size();
    for (auto palavra : palavras) {
        if (palavra.size() == tamanhoMaiorPalavra)
            maioresPalavras.push_back(palavra);
    }
}

void imprimeMaioresPalavras(list<string>& palavras) {
    list<string> maioresPalavras;
    preencheMaioresPalavras(palavras, maioresPalavras);
    
    cout << endl;
    if (maioresPalavras.size() > 1)
        cout << "As maiores palavras são: " << endl;
    else
        cout << "A maior palavra é: ";
    
    for (auto palavra : maioresPalavras)
        cout << palavra << endl;
}

int main()
{
    list<string> palavras;
    
    lerPalavras(palavras);
    ordenaPalavrasPorTamanhoEmOrdemDescrescente(palavras);
    
    imprimeMaioresPalavras(palavras);
    
    return 0;
}