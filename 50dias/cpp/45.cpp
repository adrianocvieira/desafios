#include <iostream>
#include <random>

using namespace std;

void EmbaralhaPalavraMantendoPrimeiraUltimaLetra(
    string& palavra
)
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(++palavra.begin(),
        --palavra.end(),
        g);
}

int main()
{
    string palavra;
    cout << "Digite uma palavra: ";
    cin >> palavra;

    if (palavra.size() > 1) {
        EmbaralhaPalavraMantendoPrimeiraUltimaLetra(palavra);
    }

    cout << endl << palavra << endl;
    return 0;
}