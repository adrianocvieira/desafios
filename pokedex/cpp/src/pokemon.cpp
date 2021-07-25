#include "pokemon.h"

#include <iostream>

using namespace std;

Pokemon::Pokemon(const std::string& _name, int _level):
    name(_name),
    level(_level)
{

}

bool Pokemon::Compare(const Pokemon& otherPokemon, char compareFilter, char compareType)
{
    if (compareType == 'C') {
        return Greater(otherPokemon, compareFilter);
    }
    else if (compareType = 'D') {
        return Less(otherPokemon, compareFilter);
    }
}

bool Pokemon::Less(const Pokemon& otherPokemon, char compareFilter)
{
    if (compareFilter == 'N') {
        return name < otherPokemon.name;
    }
    else if (compareFilter == 'L') {
        return level < otherPokemon.level;
    }
    return false;
}

bool Pokemon::Greater(const Pokemon& otherPokemon, char compareFilter)
{
    if (compareFilter == 'N') {
        return name > otherPokemon.name;
    }
    else if (compareFilter == 'L') {
        return level > otherPokemon.level;
    }
    return false;
}

void Pokemon::print()
{
    cout << name << " " << level << endl;
}
