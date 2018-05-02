#include <iostream>
#include "game.h"
using namespace std;

//Main function, initialises and starts game
int main() {
	game gameA;
	gameA.init();
	gameA.start();

	cout << endl << "Thanks for playing!" << endl;

	return 0;
}