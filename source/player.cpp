#include <iostream>
#include "player.h"

//Choose pokemon to switch to from team
int player::getInput() {
	int input;
	cin >> input;
	return input;
}

//Choose out of fight (1), items (2), pokemon (3) or run (4)
int player::chooseOption() {
	return getInput();
}

//Choose out of first move (1), second move (2), third move (3) or fourth move(4)
int player::chooseMove() {
	return getInput();
}

//Choose item to use from list of items
int player::chooseItem() {
	return getInput();
}

//Choose pokemon to switch to from team
int player::choosePokemon() {
	return getInput();
}