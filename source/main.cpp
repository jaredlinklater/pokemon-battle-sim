#include <iostream>
#include "game.h"
#include "arena.h"
#include "pokemon.h"
#include "pokemonMove.h"
#include "pokemonList.cpp"
using namespace std;

//Main function, containing game state loop
int main() {
	game GameA;
	GameA.init();

	cout << "Welcome to the Pokemon Battle Simulator!" << endl;
	cout << "Lets get the arena ready for you." << endl;
	arena ArenaA;
	ArenaA.init();

	pokemon pokA;
	pokemon pokB;

	ArenaA.setTeamA(pokA);
	ArenaA.setTeamB(pokB);
	ArenaA.battle();

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