#ifndef POKEMONMOVE_H
#define POKEMONMOVE_H

#include <vector>
#include <string>
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