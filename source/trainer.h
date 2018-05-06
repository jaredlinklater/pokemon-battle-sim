#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <string>
#include "pokemon.h"
#include "pokemonMove.h"
using namespace std;

class trainer {
public:
	pokemon attacker;
	string name;
	string type; //player or ai

	virtual int chooseOption() = 0; //Choose out of fight (1), items (2), pokemon (3) or run (4)
	virtual pokemonMove chooseMove() = 0; //Choose out of first move (1), second move (2), third move (3) or fourth move(4)
	virtual int chooseItem() = 0; //Choose item to use from list of items
	virtual int choosePokemon() = 0; //Choose pokemon to switch to from team

	void printOption(string num, string opt); //Prints option with appropriate spacing


	//Setters
	void setAttacker(pokemon p);
	void setName(string s);
	void setType(string s);

	//Getters
	pokemon getAttacker();
	string getName();
	string getType();
};

#endif