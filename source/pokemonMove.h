#ifndef POKEMONMOVE_H
#define POKEMONMOVE_H

#include <string>
#include <vector>
using namespace std;

class pokemonMove {
public:
	string name;
	string type;
	bool isSpecAtk;
	int damage;
	double accuracy;

	/*string statFocus;
	double statProb;
	double statMultiplier;*/


	//Constructor
	pokemonMove(string s, int i);


	//Setters
	void setName(string s);
	void setType(string s);
	void setIsSpecAtk(bool b);
	void setDamage(int i);
	void setAccuracy(double d);

	//Getters
	string getName();
	string getType();
	bool getIsSpecAtk();
	int getDamage();
	double getAccuracy();
};

#endif