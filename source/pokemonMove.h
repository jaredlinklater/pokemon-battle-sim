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
};

#endif