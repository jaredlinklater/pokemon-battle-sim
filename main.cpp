#include <iostream>

using namespace std;

//Main function, containing game state loop.
int main() {
	bool gameOver = 0;
	int temp;

	while(!gameOver) {
		cin >> temp;
		if(temp == 0) {
			gameOver = 1;
		} else {
			cout << "Still playing." << endl;
		}
	}
	cout << "Game Over!" << endl;
	return 0;
}