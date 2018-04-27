#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include "pokemon.h"
using namespace std;

class arena {
public:
	pokemon pokeA;
	pokemon pokeB;
	bool pokeAset;
	bool pokeBset;
	int turnCount;
	int victor;

	//Setters
	void setPokeA(pokemon tA);
	void setPokeB(pokemon tB);

	void init();
	void battle();
	void doTurn();
};

#endif