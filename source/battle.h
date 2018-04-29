#ifndef BATTLE_H
#define BATTLE_H

#include "pokemon.h"
using namespace std;

class battle {
public:
	//
	pokemon pokeA;
	pokemon pokeB;
	int pokeAset;
	int pokeBset;
	int turnCount;

	void init();
	void start();
	void doTurn();

	//Setters
	void setPokeA(pokemon p);
	void setPokeB(pokemon p);
};

#endif