#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
public:
    Pokemon(const std::string& _name, int _level);

    bool Compare(const Pokemon& otherPokemon, char compareFilter, char compareType);

    void print();

private:
    bool Less(const Pokemon& otherPokemon, char compareFilter);

    bool Greater(const Pokemon& otherPokemon, char compareFilter);

    std::string name;
    int level;

};

#endif // POKEMON_H
