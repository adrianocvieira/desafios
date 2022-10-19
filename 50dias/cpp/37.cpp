#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<char, string> morseMap = { {'a', ".-"},
                               {'b', "-..."},
                               {'c', "-.-."},
                               {'d', "-.."},
                               {'e', "."},
                               {'f', "..-."},
                               {'g', "--."},
                               {'h', "...."},
                               {'i', ".."},
                               {'j', ".---"},
                               {'k', "-.-"},
                               {'l', ".-.."},
                               {'m', "--"},
                               {'n', "-."},
                               {'o', "---"},
                               {'p', ".--."},
                               {'q', "--.-"},
                               {'r', ".-."},
                               {'s', "..."},
                               {'t', "-"},
                               {'u', "..-"},
                               {'v', "...-"},
                               {'w', ".--"},
                               {'x', "-..-"},
                               {'y', "-.--"},
                               {'z', "--.."},
                               {'.', ".-.-.-"},
                               {',', "--..--"},
                               {'?', "..--.."},
                               {'!', "-.-.--"},
                               {' ', "/"},
                               {'0', "-----"},
                               {'1', ".----"},
                               {'2', "..---"},
                               {'3', "...--"},
                               {'4', "....-"},
                               {'5', "....."},
                               {'6', "-...."},
                               {'7', "--..."},
                               {'8', "---.."},
                               {'9', "----."} };

int main()
{
    string texto, textoMorse;
    cout << "Digite um texto: ";
    getline(cin, texto);

    std::for_each(texto.begin(), texto.end(), [](char& c) {
        c = ::tolower(c);
        });

    for (auto letra : texto) {
        textoMorse += morseMap[letra] + " ";
    }
    cout << textoMorse << endl;
    return 0;
}