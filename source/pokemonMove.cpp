#include <vector>
#include "pokemonMove.h"
using namespace std;


//Constructor
pokemonMove::pokemonMove() {
	name = "temp";
	damage = 0;
}

pokemonMove::pokemonMove(string s, int i) {
	name = s;
	damage = i;
}

pokemonMove::pokemonMove(string s, int pwr, int acc, string typ, string cat) {
	name = s;
	damage = pwr;
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

void pokemonMove::setDamage(int i) {
	damage = i;
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

int pokemonMove::getDamage() {
	return damage;
}

float pokemonMove::getAccuracy() {
	return accuracy;
}