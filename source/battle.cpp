#include <iostream>
#include <vector>
#include "battle.h"
#include "pokemon.h"
#include "pokemonMove.h"
using namespace std;

//Initialises variables upon new instance
void battle::init() {
	pokeAset = 0;
	pokeBset = 0;
	turnCount = 0;
	pokemonMove temp("battle.initMove", 0);
	move = temp;
}

//Turn loop; loops until a pokemon is knocked out
void battle::start() {
	if(!pokeAset) { //Checks if both pokemon have been set
		cout << "Pokemon A is not ready for battle!" << endl;
		return;
	} else if(!pokeBset) {
		cout << "Pokemon B is not ready for battle!" << endl;
		return;
	}
	cout << "Both Pokemon are ready for battle!" << endl;

	while(turnCount < 6) { //Conducts turns
		startTurn();
		doTurn();
		endTurn();
	}
}

//Sets turn player, attackers and defenders for the turn
void battle::startTurn() {
	if(turnCount % 2 == 0) { //trainerA attacks on even turns
		setTurnPlayer(getTrainerA());
		setAttacker(getPokeA());
		setDefender(getPokeB());
	} else { //trainerB attacks on odd turns
		setTurnPlayer(getTrainerB());
		setAttacker(getPokeB());
		setDefender(getPokeA());
	}
	turnPlayer->setAttacker(getAttacker());
}

//Conducts turn; asks questions, gets input, executes choices
void battle::doTurn() {
	cout << endl << endl << turnPlayer->getName() << "'s turn" << endl;
	cout << attacker.getName() << ": " << attacker.hpFraction() << endl;
	cout << defender.getName() << ": " << defender.hpFraction() << endl;

	int sel = turnPlayer->chooseOption(); //Get choice
	switch(sel) {
		case 1: move = turnPlayer->chooseMove();
				doAttack();
				break;
		case 2: turnPlayer->chooseItem();
				break;
		case 3: turnPlayer->choosePokemon();
				break;
		case 4: exit(0);
				break;
	}
}

//Writes attackers and defenders back to memory
void battle::endTurn() {
	if(turnCount % 2 == 0) { //Update pokeA/pokeB's states
		setPokeA(attacker);
		setPokeB(defender);
	} else {
		setPokeA(defender);
		setPokeB(attacker);
	}
	turnCount++;
}

void battle::doAttack() {
	cout << attacker.getName() << " used " << move.getName() << "!" << endl;
	int damage = move.getDamage();
	defender.damage(damage);
	cout << defender.getName() << " took " << damage << " points of damage!" << endl;
	if(defender.getCurrentHp() == 0) {
		cout << defender.getName() << " was knocked out!" << endl;
	}
}

//Setters
void battle::setTrainerA(trainer *t) {
	trainerA = t;
}

void battle::setTrainerB(trainer *t) {
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

void battle::setTurnPlayer(trainer *t) {
	turnPlayer = t;
}

void battle::setAttacker(pokemon p) {
	attacker = p;
}

void battle::setDefender(pokemon p) {
	defender = p;
}

//Getters
trainer *battle::getTrainerA() {
	return trainerA;
}

trainer *battle::getTrainerB() {
	return trainerB;
}

pokemon battle::getPokeA() {
	return pokeA;
}

pokemon battle::getPokeB() {
	return pokeB;
}

trainer *battle::getTurnPlayer() {
	return turnPlayer;
}

pokemon battle::getAttacker() {
	return attacker;
}

pokemon battle::getDefender() {
	return defender;
}