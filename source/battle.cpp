#include "battle.h"
#include "pokemon.h"
#include <iostream>
#include <vector>
using namespace std;

//Initialises variables upon new instance
void battle::init() {
	pokeAset = 0;
	pokeBset = 0;
	turnCount = 0;
}

//Loop turns until a pokemon is knocked out
void battle::start() {
	for(int i = 0; i < 5; i++) {
		trainer turnPlayer;
		if(turnCount % 2 == 0) { //trainerA attacks on even turns
			turnPlayer = trainerA;
		} else { //trainerB attacks on odd turns
			turnPlayer = trainerB;
		}
		doTurn(turnPlayer);
	}
}

//
void battle::doTurn(trainer t) {
	pokemon attacker;
	pokemon defender;
	
	if(turnCount % 2 == 0) { //pokeA attacks on even turns
		attacker = getPokeA();
		defender = getPokeB();
	} else { //pokB attacks on odd turns
		attacker = getPokeB();
		defender = getPokeA();
	}

	if(turnCount % 2 == 0) { 
		setPokeA(attacker);
		setPokeB(defender);
	} else {
		setPokeA(defender);
		setPokeB(attacker);
	}
	turnCount++;
}

//Setters
void battle::setPokeA(pokemon p) {
	pokeA = p;
	pokeAset = 1;
}

void battle::setPokeB(pokemon p) {
	pokeB = p;
	pokeBset = 1;
}


//Getters
pokemon battle::getPokeA() {
	return pokeA;
}

pokemon battle::getPokeB() {
	return pokeB;
}