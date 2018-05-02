#include "ai.h"

//Choose out of fight (1), items (2), pokemon (3) or run (4)
int ai::chooseOption() {
	return 1;
}

//Choose out of first move (1), second move (2), third move (3) or fourth move(4)
pokemonMove ai::chooseMove() {
	pokemonMove temp("temp", 0);
	return temp;
}

//Choose item to use from list of items
int ai::chooseItem() {
	return 1;
}

//Choose pokemon to switch to from team
int ai::choosePokemon() {
	return 1;
}