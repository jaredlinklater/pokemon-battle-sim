#ifndef POKEMONMOVE_H
#define POKEMONMOVE_H

#include <string>
#include <vector>
using namespace std;

class pokemonMove {
public:
	string name;
	string type;
	string category;
	int damage;
	float accuracy;

	/*string statFocus;
	double statProb;
	double statMultiplier;*/


	//Constructor
	pokemonMove();
	pokemonMove(string s, int i);
	pokemonMove(string s, int pwr, int acc, string typ, string cat);


	//Setters
	void setName(string s);
	void setType(string s);
	void setCategory(string s);
	void setDamage(int i);
	void setAccuracy(float f);

	//Getters
	string getName();
	string getType();
	string getCategory();
	int getDamage();
	float getAccuracy();
};

#endif