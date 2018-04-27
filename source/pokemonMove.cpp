#include "pokemonMove.h"
#include <vector>
using namespace std;

//Constructor
pokemonMove::pokemonMove(string s, int i) {
	name = s;
	damage = i;
}

//Setters
void pokemonMove::setName(string s) {
	name = s;
}

void pokemonMove::setType(string s) {
	type = s;
}

void pokemonMove::setIsSpecAtk(bool b) {
	isSpecAtk = b;
}

void pokemonMove::setDamage(int i) {
	damage = i;
}

void pokemonMove::setAccuracy(double d) {
	accuracy = d;
}

//Getters
string pokemonMove::getName() {
	return name;
}

string pokemonMove::getType() {
	return type;
}

bool pokemonMove::getIsSpecAtk() {
	return isSpecAtk;
}

int pokemonMove::getDamage() {
	return damage;
}

double pokemonMove::getAccuracy() {
	return accuracy;
}