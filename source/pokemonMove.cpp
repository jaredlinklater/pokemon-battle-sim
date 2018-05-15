#include <vector>
#include "pokemonMove.h"
using namespace std;


//Constructors
pokemonMove::pokemonMove() {
	name = "temp";
	power = 0;
}

pokemonMove::pokemonMove(string s, int i) {
	name = s;
	power = i;
}

pokemonMove::pokemonMove(string s, int pwr, int acc, string typ, string cat) {
	name = s;
	power = pwr;
	accuracy = float(acc)/100;
	type = typ;
	category = cat;
}


//Setters
void pokemonMove::setName(string s) {
	name = s;
}

void pokemonMove::setType(string s) {
	type = s;
}

void pokemonMove::setCategory(string s) {
	category = s;
}

void pokemonMove::setPower(int i) {
	power = i;
}

void pokemonMove::setAccuracy(float f) {
	accuracy = f;
}

//Getters
string pokemonMove::getName() {
	return name;
}

string pokemonMove::getType() {
	return type;
}

string pokemonMove::getCategory() {
	return category;
}

int pokemonMove::getPower() {
	return power;
}

float pokemonMove::getAccuracy() {
	return accuracy;
}