#include <iostream>
#include "game.h"
#include "arena.h"
using namespace std;

//Main function, containing game state loop
int main() {
	game GameA;
	GameA.init();

	cout << "Welcome to the Pokemon Battle Simulator!" << endl;
	cout << "Lets get the arena ready for you." << endl;
	arena ArenaA;
	ArenaA.init();

	int arrA[] = {8,5,3,1};
	vector<int> teamA (arrA, arrA + sizeof(arrA)/sizeof(int));
	int arrB[] = {7,2,4,9};
	vector<int> teamB (arrB, arrB + sizeof(arrB)/sizeof(int));

	ArenaA.setTeamA(teamA);
	ArenaA.setTeamB(teamB);
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