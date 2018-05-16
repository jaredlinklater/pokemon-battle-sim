#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"
#include "trainer.h"
#include "pokemon.h"
using namespace std;

class player: public trainer {
public:
	int chooseOption(); //Choose out of fight (1), items (2), pokemon (3) or run (4)
	pokemonMove chooseMove(); //Choose out of first move (1), second move (2), third move (3) or fourth move(4)
	int chooseItem(); //Choose item to use from list of items
	int choosePokemon(); //Choose pokemon to switch to from team

	//Constructors
	player();
};

#endif