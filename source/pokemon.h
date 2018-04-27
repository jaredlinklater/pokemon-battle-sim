#ifndef POKEMON_H
#define POKEMON_H

#include <vector>
#include <string>
#include "pokemonMove.h"
using namespace std;

class pokemon {
public:
	int id;
	string name;
	vector<string> types;
	int hp;
	int attack;
	int specAttack;
	int defense;
	int specDefense;
	int speed;
	vector<pokemonMove> moveset;

	void setId(int i);
	void setName(string n);
};

#endif