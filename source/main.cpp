#include <iostream>
#include <vector>
#include "game.h"
#include "player.h"
#include "ai.h"
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
	game gameA;
	gameA.init();

	//Introduction, set up arena
	cout << "Welcome to the Pokemon Battle Simulator!" << endl;
	cout << "Let's get the arena ready for you." << endl;
	arena arenaA;
	arenaA.init();

	//Create and set trainers
	player playerA;
	ai aiA;

	trainer *trainerA = &playerA;
	trainer *trainerB = &aiA;

	arenaA.setTrainerA(trainerA);
	arenaA.setTrainerB(trainerB);

	//Create and set pokemon teams
	vector<pokemon> teamA;
	teamA.push_back(bulbasaur);

	vector<pokemon> teamB;
	teamB.push_back(charmander);

	arenaA.setTeamA(teamA);
	arenaA.setTeamB(teamB);

	//Start battle
	arenaA.startBattle();


	/*player playerA;
	trainer trainerA = playerA;
	cout << "input: " << playerA.chooseMove() << "." << endl;*/

	int temp;
	while(!gameA.gameOver) {
		cin >> temp;
		if(temp == 0) {
			gameA.gameOver = 1;
		} else {
			cout << "Still playing." << endl;
		}
	}
	cout << "Game over, thanks for playing!" << endl;
	return 0;
}
