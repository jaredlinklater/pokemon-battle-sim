#include <iostream>
#include <vector>
#include "player.h"

//Choose pokemon to switch to from team
int player::getInput() {
	int input;
	cin >> input;
	return input;
}

//Choose out of fight (1), items (2), pokemon (3) or run (4)
int player::chooseOption() {
	printOption("1", "Fight"); printOption("2", "Items"); cout << endl;
	printOption("3", "Pokemon"); printOption("4", "Run"); cout << endl;
	int sel = getInput();
	while(!(sel > 0 && sel < 5)) { //Error checking
		cout << "Invalid selection! Please enter a number from 1 to 4." << endl;
		sel = getInput();
	}
	return sel;
}

//Choose out of first move (1), second move (2), third move (3) or fourth move(4)
pokemonMove player::chooseMove() {
	vector<pokemonMove> moveset = attacker.getMoveset();
	printOption("1", moveset[0].getName()); printOption("2", moveset[1].getName()); cout << endl;
	printOption("3", moveset[2].getName()); printOption("4", moveset[3].getName()); cout << endl;
	int sel = getInput();
	while(!(sel > 0 && sel < 5)) { //Error checking
		cout << "Invalid selection! Please enter a number from 1 to 4." << endl;
		sel = getInput();
	}
	return moveset[sel-1];
}

//Choose item to use from list of items
int player::chooseItem() {
	return getInput();
}

//Choose pokemon to switch to from team
int player::choosePokemon() {
	return getInput();
}