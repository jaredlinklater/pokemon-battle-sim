#include "trainer.h"

void trainer::printOption(string num, string opt) {
	string output = num + ": " + opt;
	while(output.length() < 18) {
		output += " ";
	}
	cout << output;
}


//Setters
void trainer::setAttacker(pokemon p) {
	attacker = p;
}

void trainer::setName(string s) {
	name = s;
}

void trainer::setType(string s) {
	type = s;
}

//Getters
pokemon trainer::getAttacker() {
	return attacker;
}

string trainer::getName() {
	return name;
}

string trainer::getType() {
	return type;
}