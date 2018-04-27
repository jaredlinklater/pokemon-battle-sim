#ifndef POKEMON_H
#define POKEMON_H

#include <vector>
#include <string>
#include "pokemonMove.h"
using namespace std;

class pokemon {
public:
	int id;
	string name;
	vector<string> types;
	int hp;
	int attack;
	int specAttack;
	int defense;
	int specDefense;
	int speed;
	vector<pokemonMove> moveset;

	//Setters
	void setId(int i);
	void setName(string s);
	void setTypes(vector<string> v);
	void setHp(int i);
	void setAttack(int i);
	void setSpecAttack(int i);
	void setDefense(int i);
	void setSpecDefense(int i);
	void setSpeed(int i);
	void setMoveset(vector<pokemonMove> v);

	//Getters
	int getId();
	string getName();
	vector<string> getTypes();
	int getHp();
	int getAttack();
	int getSpecAttack();
	int getDefense();
	int getSpecDefense();
	int getSpeed();
	vector<pokemonMove> getMoveset();
};

#endif