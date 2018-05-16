#include <iostream>
#include <string>
#include <vector>
#include <utility> //pair
#include <cmath> //round
#include "attack.h"

void attack::init() {
	//Construct type effectiveness chart
	string typesArr[] = {"normal", "fighting", "flying", "poison", "ground", "rock", "bug", "ghost", "steel", "fire", "water", "grass", "electric", "psychic", "ice", "dragon", "dark", "fairy"};
	float effectiveness[][18] = {{1,1,1,1,1,0.5,1,0,0.5,1,1,1,1,1,1,1,1,1}, //normal
								{2,1,0.5,0.5,1,2,0.5,0,2,1,1,1,1,0.5,2,1,2,0.5}, //fighting
								{1,2,1,1,1,0.5,2,1,0.5,1,1,2,0.5,1,1,1,1,1}, //flying
								{1,1,1,0.5,0.5,0.5,1,0.5,0,1,1,2,1,1,1,1,1,2}, //poison
								{1,1,0,2,1,2,0.5,1,2,2,1,0.5,2,1,1,1,1,1}, //ground
								{1,0.5,2,1,0.5,1,2,1,0.5,2,1,1,1,1,2,1,1,1}, //rock
								{1,0.5,0.5,0.5,1,1,1,0.5,0.5,0.5,1,2,1,2,1,1,2,0.5}, //bug
								{0,1,1,1,1,1,1,2,1,1,1,1,1,2,1,1,0.5,1}, //ghost
								{1,1,1,1,1,2,1,1,0.5,0.5,0.5,1,0.5,1,2,1,1,2}, //steel
								{1,1,1,1,1,0.5,2,1,2,0.5,0.5,2,1,1,2,0.5,1,1}, //fire
								{1,1,1,1,2,2,1,1,1,2,0.5,0.5,1,1,1,0.5,1,1}, //water
								{1,1,0.5,0.5,2,2,0.5,1,0.5,0.5,2,0.5,1,1,1,0.5,1,1}, //grass
								{1,1,2,1,0,1,1,1,1,1,2,0.5,0.5,1,1,0.5,1,1}, //electric
								{1,2,1,2,1,1,1,1,0.5,1,1,1,1,0.5,1,1,0,1}, //psychic
								{1,1,2,1,2,1,1,1,0.5,0.5,0.5,2,1,1,0.5,2,1,1}, //ice
								{1,1,1,1,1,1,1,1,0.5,1,1,1,1,1,1,2,1,0}, //dragon
								{1,0.5,1,1,1,1,1,2,1,1,1,1,1,2,1,1,0.5,0.5}, //dark
								{1,2,1,0.5,1,1,1,1,0.5,0.5,1,1,1,1,1,2,2,1}}; //fairy

	for(int i = 0; i < 18; i++) { //construct map
		for(int j = 0; j < 18; j++) {
			typeChart[make_pair(typesArr[i], typesArr[j])] = effectiveness[i][j];
		}
	}
}

//Calculate damage in accordance with the generation VII damage formula
//Source: https://bulbapedia.bulbagarden.net/wiki/Damage_calculation
int attack::calcDamage() {
	float level = 100;
	float power = pMove.getPower();
	string category = pMove.getCategory();
	float attack;
	float defense;

	if(category == "physical") {
		attack = attacker.getAttack();
		defense = defender.getDefense();
	} else if(category == "special") {
		attack = attacker.getSpecAttack();
		defense = defender.getSpecDefense();
	} else if(category == "other") {
		return 0;
	}

	float mod = calcModifier();
	float damage = ((((((2*level)/5) + 2) * power * (attack/defense))/50) + 2) * mod;
	return round(damage);
}

//Calculate damage modifier
float attack::calcModifier() {
	float random = float(randomInt(85, 100))/100;

	float STAB = 1;
	float typeEff = 1;
	vector<string> atkTypes = attacker.getTypes();
	vector<string> defTypes = defender.getTypes();
	for(int i = 0; i < defTypes.size(); i++) {
		if(atkTypes[i] == pMove.getType()) //STAB checking
			STAB = 1.5;
		if(defTypes[i] != "-") //type effectiveness checking
			typeEff *= typeChart[make_pair(pMove.getType(), defTypes[i])];
	}

	float critical = 1;
	if(randomInt(1, 24) == 1) { //critical hit chance: 1/24
		critical = 1.5;
	}

	float other = 1; //for held items, abilities, etc; not implemented

	if(typeEff >= 2) {
		cout << "It was super effective!" << endl;
	} else if(typeEff < 1) {
		cout << "It wasn't very effective!" << endl;
	}

	if(critical > 1) 
		cout << "Critical hit!" << endl;

	return random * STAB * typeEff * critical * other;
}


//Constructors
attack::attack(pokemon atk, pokemonMove mv, pokemon def) {
	attacker = atk;
	pMove = mv;
	defender = def;
}