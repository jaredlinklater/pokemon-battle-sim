#include <iostream>
#include "game.h"
using namespace std;

//Main function, containing game state loop
int main() {
	game GameA;
	GameA.init();

	cout << "Welcome to the Pokemon Battle Simulator!" << endl;

	int temp;
	while(!GameA.gameOver) {
		cin >> temp;
		if(temp == 0) {
			GameA.gameOver = 1;
		} else {
			cout << "Still playing." << endl;
		}
	}
	cout << "Game Over!" << endl;
	return 0;
}