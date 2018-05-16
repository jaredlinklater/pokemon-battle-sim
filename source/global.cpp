#include "global.h"

//Clears terminal screen
void clearScreen() {
	system("clear");
}

//Gets int input from command line and error checks
int getInput(int min, int max) {
	int input;
	string x;

	getline(cin, x);
	stringstream(x) >> input;
	while(!(input >= min && input <= max)) { //Error checking
		cout << "Invalid selection! Please enter a number from " << min << " to " << max << "." << endl;
		getline(cin, x);
		stringstream(x) >> input;
	}

	return input;
}

//Gets string input from command line and error checks
string getInputString(int max) {
	string input;
	string x;

	getline(cin, x);
	stringstream(x) >> input;
	while(!(input.size() > 0 && input.size() <= max)) { //Error checking
		cout << "Invalid selection! Please use more than 0 and " << max << " or less characters." << endl;
		getline(cin, x);
		stringstream(x) >> input;
	}

	return input;
}

//Generates random int between min and max inclusively
int randomInt(int min, int max) {
	return rand()%(max-min+1) + min;
}