#ifndef AI_H
#define AI_H

#include "trainer.h"
#include "battle.h"
using namespace std;

class ai: public trainer {
public:
	battle currentBattle; //instance of the battle for the AI to make decisions with

	int chooseOption(); //Choose out of fight (1), items (2), pokemon (3) or run (4)
	int chooseMove(); //Choose out of first move (1), second move (2), third move (3) or fourth move(4)
	int chooseItem(); //Choose item to use from list of items
	int choosePokemon(); //Choose pokemon to switch to from team
};

#endif