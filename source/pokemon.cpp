#include "pokemon.h"
#include <vector>
using namespace std;

//Setters
void pokemon::setId(int i) {
	id = i;
}

void pokemon::setName(string s) {
	name = s;
}

void pokemon::setTypes(vector<string> v) {
	types = v;
}

void pokemon::setHp(int i) {
	hp = i;
}

void pokemon::setAttack(int i) {
	attack = i;
}

void pokemon::setSpecAttack(int i) {
	specAttack = i;
}

void pokemon::setDefense(int i) {
	defense = i;
}

void pokemon::setSpecDefense(int i) {
	specDefense = i;
}

void pokemon::setSpeed(int i) {
	speed = i;
}

void pokemon::setMoveset(vector<pokemonMove> v) {
	moveset = v;
}

//Getters
int pokemon::getId() {
	return id;
}

string pokemon::getName() {
	return name;
}

vector<string> pokemon::getTypes() {
	return types;
}

int pokemon::getHp() {
	return hp;
}

int pokemon::getAttack() {
	return attack;
}

int pokemon::getSpecAttack() {
	return specAttack;
}

int pokemon::getDefense() {
	return defense;
}

int pokemon::getSpecDefense() {
	return specDefense;
}

int pokemon::getSpeed() {
	return speed;
}

vector<pokemonMove> pokemon::getMoveset() {
	return moveset;
}