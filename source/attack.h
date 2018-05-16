#ifndef ATTACK_H
#define ATTACK_H
#include <map>
#include "global.h"
#include "pokemon.h"
#include "pokemonMove.h"

using namespace std;

class attack {
public:
	pokemon attacker;
	pokemonMove pMove;
	pokemon defender;

	int finalDamage;
	map<pair<string, string>, float> typeChart; //called as typeChart[make_pair("attacking type", "defending type")]

	void init();
	int calcDamage();
	float calcModifier();

	//Constructors
	attack(pokemon atk, pokemonMove mv, pokemon def);

};

#endif