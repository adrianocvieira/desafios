#include <iostream>
#include <string>

using namespace std;

int tamanho_matriz = 0;
char** matriz = NULL;
string palavra = "";
int linha_inicial = -1;
int coluna_inicial = -1;
int linha_final = -1;
int coluna_final = -1;

void imprime_matriz() {
    for (int indice_linha=0; indice_linha<tamanho_matriz; indice_linha++) {
        for (int indice_coluna=0; indice_coluna<tamanho_matriz; indice_coluna++) {
            cout << matriz[indice_linha][indice_coluna] << " ";
        }
        cout << endl;
    }
}

void cria_matriz()
{
    matriz = new char*[tamanho_matriz];
    for (int i=0; i<tamanho_matriz; i++) {
        matriz[i] = new char[tamanho_matriz];
    }

}

void destroi_matriz() {
    for (int i=0; i<tamanho_matriz; i++) {
        delete [] matriz[i];
    }
    delete [] matriz;
}

void preenche_linha_matriz(int indice_linha, const string & texto) {
    int posicao_string = 0;
    for (int indice_coluna=0; indice_coluna<tamanho_matriz; indice_coluna++) {
        matriz[indice_linha][indice_coluna] = texto[posicao_string];
        posicao_string += 2;
    }
}

void le_matriz() {
    string conteudo_linha;
    for (int i=0; i<tamanho_matriz; i++) {
        getline(cin, conteudo_linha);
        preenche_linha_matriz(i, conteudo_linha);
    }
}

void le_dados_entrada()
{
    cin >> tamanho_matriz;
    cin.ignore();

    cria_matriz();

    le_matriz();

    cin >> palavra;
}

bool procura_resto_palavra(int linha_segunda_letra, int coluna_segunda_letra) {
    int delta_linha = linha_segunda_letra - linha_inicial;
    int delta_coluna = coluna_segunda_letra - coluna_inicial;

    int linha_atual = linha_segunda_letra;
    int coluna_atual = coluna_segunda_letra;
    for (unsigned int indice_palavra = 2; indice_palavra < palavra.length(); indice_palavra++) {
        linha_atual += delta_linha;
        coluna_atual += delta_coluna;
        bool linha_valida = linha_atual >= 0 && linha_atual < tamanho_matriz;
        bool coluna_valida = coluna_atual >= 0 && coluna_atual < tamanho_matriz;
        if (linha_valida && coluna_valida) {
            if (palavra[indice_palavra] != matriz[linha_atual][coluna_atual])
                return false;
        }
        else
            return false;
    }

    linha_final = linha_atual;
    coluna_final = coluna_atual;
    return true;
}

bool procura_continuacao_palavra() {
    bool encontrou_continuacao = false;
    for (int i = linha_inicial-1; i<=linha_inicial+1 && !encontrou_continuacao; i++) {
        for (int j = coluna_inicial-1; j<=coluna_inicial+1 && !encontrou_continuacao; j++) {
            bool posicao_valida = i >=0 && j>=0;
            if (posicao_valida) {
                bool encontrou_segunda_letra = palavra[1] == matriz[i][j];
                if (encontrou_segunda_letra) {
                    encontrou_continuacao = procura_resto_palavra(i, j);
                }

            }
        }
    }

    return encontrou_continuacao;
}

void procura_palavra_na_matriz()
{
    bool encontrou = false;
    for (int indice_linha=0; indice_linha < tamanho_matriz && !encontrou; indice_linha++) {
        for (int indice_coluna=0; indice_coluna < tamanho_matriz && !encontrou; indice_coluna++) {
            bool encontrou_primeira_letra = palavra[0] == matriz[indice_linha][indice_coluna];
            if (encontrou_primeira_letra) {
                linha_inicial = indice_linha;
                coluna_inicial = indice_coluna;
                encontrou = procura_continuacao_palavra();
            }
        }
    }

    if (!encontrou) {
        linha_inicial = -1;
        coluna_inicial = -1;
        linha_final = -1;
        coluna_final = -1;
    }
}

void imprime_resultado()
{
    cout << linha_inicial << " " << coluna_inicial << " ";
    cout << linha_final << " " << coluna_final << endl;
}

int main()
{
    le_dados_entrada();

    procura_palavra_na_matriz();

    destroi_matriz();

    imprime_resultado();

    return 0;
}
