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

//Turn loop; loops until a pokemon is knocked out
void battle::start() {
	if(!pokeAset) { //Checks if both teams have been set
		cout << "Pokemon A is not ready for battle!" << endl;
		return;
	} else if(!pokeBset) {
		cout << "Pokemon B is not ready for battle!" << endl;
		return;
	}
	cout << "Both Pokemon are ready for battle!" << endl;

	for(int i = 0; i < 6; i++) { //Determines turn player, attacking pokemon/defending pokemon and conducts turns
		int even = (turnCount % 2 == 0);
		if(even) { //trainerA attacks on even turns
			setTurnPlayer(getTrainerA());
			setAttacker(getPokeA());
			setDefender(getPokeB());
		} else { //trainerB attacks on odd turns
			setTurnPlayer(getTrainerB());
			setAttacker(getPokeB());
			setDefender(getPokeA());
		}

		doTurn();

		if(even) { //Update pokeA/pokeB's states
			setPokeA(attacker);
			setPokeB(defender);
		} else {
			setPokeA(defender);
			setPokeB(attacker);
		}
		turnCount++;
	}
}

//Conducts turn; asks questions, gets input, executes choices
void battle::doTurn() {
	cout << attacker.getName() << "'s turn" << endl;
}


//Setters
void battle::setTrainerA(trainer t) {
	trainerA = t;
}

void battle::setTrainerB(trainer t) {
	trainerB = t;
}

void battle::setPokeA(pokemon p) {
	pokeA = p;
	pokeAset = 1;
}

void battle::setPokeB(pokemon p) {
	pokeB = p;
	pokeBset = 1;
}

void battle::setTurnPlayer(trainer t) {
	turnPlayer = t;
}

void battle::setAttacker(pokemon p) {
	attacker = p;
}

void battle::setDefender(pokemon p) {
	defender = p;
}

//Getters
trainer battle::getTrainerA() {
	return trainerA;
}

trainer battle::getTrainerB() {
	return trainerB;
}

pokemon battle::getPokeA() {
	return pokeA;
}

pokemon battle::getPokeB() {
	return pokeB;
}

trainer battle::getTurnPlayer() {
	return turnPlayer;
}

pokemon battle::getAttacker() {
	return attacker;
}

pokemon battle::getDefender() {
	return defender;
}