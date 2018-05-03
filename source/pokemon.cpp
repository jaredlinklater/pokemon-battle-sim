#include <sstream>
#include <iterator>
#include <vector>
#include "pokemon.h"
using namespace std;

extern vector<pokemon> pokemonList;

//Heals to full hp
void pokemon::heal() {
	currentHp = hp;
}

//Heals for i HP up to max HP
void pokemon::heal(int i) {
	currentHp += i;
	if(currentHp > hp)
		currentHp = hp;
}

//Damage for i HP
void pokemon::damage(int i) {
	currentHp -= i;
	if(currentHp < 0)
		currentHp = 0;
}

//Sets current HP to 0
void pokemon::kill() {
	currentHp = 0;
}

//Returns HP as a fraction (currentHp/hp)
string pokemon::hpFraction() {
	string temp = to_string(getCurrentHp()) + "/" + to_string(getHp());
	return temp;
}


//Constructors
pokemon::pokemon() {
	name = "missingno";
}

pokemon::pokemon(string s, int i, vector<pokemonMove> moves) {
	name = s;
	hp = i;
	currentHp = hp;
	moveset = moves;
	infliction = "clear";
	pokemonList.push_back(*this);
}

pokemon::pokemon(string s, string typs, int hitp, int atk, int def, int spatk, int spdef, int spd, vector<pokemonMove> moves) {
	name = s;

	stringstream ss(typs); //Splits typs string into two types vector
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> typesVect(begin, end);
	types = typesVect;

	hp = hitp;
	attack = atk;
	defense = def;
	specAttack = spatk;
	specDefense = spdef;
	speed = spd;
	currentHp = hp;
	moveset = moves;
	infliction = "clear";
	pokemonList.push_back(*this);
}


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

void pokemon::setCurrentHp(int i) {
	currentHp = i;
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

int pokemon::getCurrentHp() {
	return currentHp;
}

vector<pokemonMove> pokemon::getMoveset() {
	return moveset;
}