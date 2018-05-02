#include <cstdlib>
#include <vector>
#include "ai.h"
#include "pokemonMove.h"

//Generates random int betweek min and max inclusively
int ai::getRandom(int min, int max) {
	return rand() % (max+1) + min;
}

//Choose out of fight (1), items (2), pokemon (3) or run (4)
int ai::chooseOption() {
	return 1;
}

//Choose out of first move (1), second move (2), third move (3) or fourth move(4)
pokemonMove ai::chooseMove() {
	return attacker.getMoveset()[getRandom(0,1)];
}

//Choose item to use from list of items
int ai::chooseItem() {
	return 1;
}

//Choose pokemon to switch to from team
int ai::choosePokemon() {
	return 1;
}