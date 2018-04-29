#ifndef BATTLE_H
#define BATTLE_H

#include "trainer.h"
#include "pokemon.h"
using namespace std;

class battle {
public:
	//
	trainer trainerA;
	trainer trainerB;
	pokemon pokeA;
	pokemon pokeB;
	int pokeAset;
	int pokeBset;
	int turnCount;

	void init();
	void start();
	void doTurn(trainer t);

	//Setters
	void setPokeA(pokemon p);
	void setPokeB(pokemon p);

	//Getters
	pokemon getPokeA();
	pokemon getPokeB();
};

#endif