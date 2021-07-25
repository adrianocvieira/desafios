#include <iostream>
#include <string>

#include "pokemon.h"

using namespace std;

Pokemon** pokemonList = nullptr;
int pokemonNumber = 0;
char orderFilter = ' ';
char orderType = ' ';

void readFirstInputLine()
{
    std::string lineData;
    getline(cin, lineData);

    std::string pokemonNumberStr = "";
    int iterator = 0;
    while(lineData[iterator] != ' ') {
        pokemonNumberStr += lineData[iterator];
        iterator++;
    }

    pokemonNumber = std::stoi(pokemonNumberStr);
    orderFilter = lineData[iterator+1];
    orderType = lineData[iterator+3];
}

void createPokemonList()
{
    pokemonList = new Pokemon*[pokemonNumber];
}

Pokemon* readPokemonLine()
{
    std::string pokemonName = "";
    int pokemonLevel = 0;

    std::string lineData;
    getline(cin, lineData);
    int iterator = 0;
    while(lineData[iterator] != ' ') {
        pokemonName += lineData[iterator];
        iterator++;
    }

    iterator += 1;
    std::string pokemonLevelStr = "";
    while(lineData[iterator] != '\0') {
        pokemonLevelStr += lineData[iterator];
        iterator++;
    }

    pokemonLevel = std::stoi(pokemonLevelStr);

    return new Pokemon(pokemonName, pokemonLevel);;
}

void readInputData()
{
    readFirstInputLine();

    createPokemonList();

    for(int i=0; i<pokemonNumber; i++) {
        pokemonList[i] = readPokemonLine();
    }
}

void swap(int firstPos, int secPos)
{
    Pokemon* aux = pokemonList[firstPos];
    pokemonList[firstPos] = pokemonList[secPos];
    pokemonList[secPos] = aux;
}

void orderPokemonList()
{
    for(int i=0; i<pokemonNumber-1; i++) {
        for(int j=0; j<pokemonNumber-1; j++) {
            if (pokemonList[j]->Compare(*pokemonList[j+1], orderFilter, orderType)) {
                swap(j, j+1);
            }
        }
    }
}

void printPokemonList()
{
    cout << endl << "----------------------------------------" << endl;
    for(int i=0; i<pokemonNumber; i++) {
        pokemonList[i]->print();
    }
}

void destroyPokemonList()
{
    for(int i=0; i<pokemonNumber; i++) {
        delete pokemonList[i];
    }

    delete [] pokemonList;
}


int main()
{
    readInputData();

    orderPokemonList();

    printPokemonList();

    destroyPokemonList();
    return 0;
}
