#include <iostream>
#include <vector>
#include "game.h"
#include "arena.h"
#include "pokemon.h"
#include "pokemonMove.h"
using namespace std;

/*** Declare global objects ***/
//Declaring Pokemon
pokemon bulbasaur;
pokemon charmander;
pokemon squirtle;

//Main function, containing game state loop
int main() {
	game GameA;
	GameA.init();

	//Introduction, set up arena
	cout << "Welcome to the Pokemon Battle Simulator!" << endl;
	cout << "Lets get the arena ready for you." << endl;
	arena ArenaA;
	ArenaA.init();

	//Create and set pokemon teams
	vector<pokemon> teamA;
	teamA.push_back(bulbasaur);

	vector<pokemon> teamB;
	teamB.push_back(charmander);

	ArenaA.setTeamA(teamA);
	ArenaA.setTeamB(teamB);

	//Start battle
	ArenaA.startBattle();

	int temp;
	while(!GameA.gameOver) {
		cin >> temp;
		if(temp == 0) {
			GameA.gameOver = 1;
		} else {
			cout << "Still playing." << endl;
		}
	}
	cout << "Game over, thanks for playing!" << endl;
	return 0;
}
