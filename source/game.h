#ifndef GAME_H
#define GAME_H

#include "pokemon.h"

class game {
public:
	pokemon pokeA;
	pokemon pokeB;

	void init();
	void start();

	pokemon choosePokemon();
};

#endif