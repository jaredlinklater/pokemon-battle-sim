#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include "pokemonMove.h"
using namespace std;

class pokemon {
public:
	int id;
	string name;
	vector<string> types;
	int hp;
	int attack;
	int defense;
	int specAttack;
	int specDefense;
	int speed;
	int currentHp;
	string infliction;
	vector<pokemonMove> moveset;

	void heal();
	void heal(int i);
	void damage(int i);
	void kill();
	string hpFraction();


	//Constructors
	pokemon();
	pokemon(string s, int i, vector<pokemonMove> moves);
	pokemon(string s, string typs, int hitp, int atk, int def, int spatk, int spdef, int spd, vector<pokemonMove> moves);


	//Setters
	void setId(int i);
	void setName(string s);
	void setTypes(vector<string> v);
	void setHp(int i);
	void setAttack(int i);
	void setDefense(int i);
	void setSpecAttack(int i);
	void setSpecDefense(int i);
	void setSpeed(int i);
	void setCurrentHp(int i);
	void setMoveset(vector<pokemonMove> v);

	//Getters
	int getId();
	string getName();
	vector<string> getTypes();
	int getHp();
	int getAttack();
	int getDefense();
	int getSpecAttack();
	int getSpecDefense();
	int getSpeed();
	int getCurrentHp();
	vector<pokemonMove> getMoveset();
};

#endif