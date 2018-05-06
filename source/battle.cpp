#include <iostream>
#include <vector>
#include <unistd.h> //usleep
#include "battle.h"
#include "pokemon.h"
#include "pokemonMove.h"
using namespace std;

unsigned int sleepTime = 1200;

void msleep(unsigned int i);

//Initialises variables upon new instance
void battle::init() {
	pokeAset = false;
	pokeBset = false;
	turnCount = 0;
	battleOver = false;
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

	while(!battleOver) { //Conducts turns
		startTurn();
		doTurn();
		endTurn();
	}

	cout << endl << winner.getName() << " won the battle!" << endl;
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
	system("clear");
	//cout << endl << endl;
	cout << "\033[4m" << turnPlayer->getName() << "'s turn\033[0m" << endl;
	cout << turnPlayer->getName() << "'s " << attacker.getName() << ": " << attacker.hpFraction() << endl;
	cout << "Opponent's " << defender.getName() << ": " << defender.hpFraction() << endl;

	int sel;
	do { //Ensures users can only choose implemented features
		sel = turnPlayer->chooseOption(); //Get choice
		switch(sel) {
			case 1: move = turnPlayer->chooseMove();
					doAttack();
					break;
			case 2: cout << "Sorry, items are not yet implemented." << endl << endl;
					//turnPlayer->chooseItem();
					break;
			case 3: cout << "Sorry, pokemon switching is not yet implemented." << endl << endl;
					//turnPlayer->choosePokemon();
					break;
			case 4: cout << "You surrendered!" << endl << "Thanks for playing." << endl;
					exit(0);
					break;
		}
	} while(sel == 2 || sel == 3);
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
	checkAlive();
	turnCount++;
}

//Conducts attack and determines of battle should end
void battle::doAttack() {
	if(turnPlayer->getType() == "ai")
		msleep(sleepTime);
	cout << attacker.getName() << " used " << move.getName() << "!" << endl;
	msleep(sleepTime);
	int damage = move.getDamage();
	defender.damage(damage);
	cout << defender.getName() << " took " << damage << " points of damage!" << endl;
	msleep(sleepTime);
}

//Checks if both pokemon are still able to fight
void battle::checkAlive() {
	if(pokeA.getCurrentHp() == 0 && pokeB.getCurrentHp() == 0) {
		cout << "Both pokemon were knocked out!" << endl;
		battleOver = true;
	} else if(pokeA.getCurrentHp() == 0) {
		cout << pokeA.getName() << " was knocked out!" << endl;
		winner = pokeB;
		loser = pokeA;
		battleOver = true;
	} else if(pokeB.getCurrentHp() == 0) {
		cout << pokeB.getName() << " was knocked out!" << endl;
		winner = pokeA;
		loser = pokeB;
		battleOver = true;
	}
}

//Sleeps for i milliseconds
void msleep(unsigned int i) {
	usleep(i * 1000);
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
	pokeAset = true;
}

void battle::setPokeB(pokemon p) {
	pokeB = p;
	pokeBset = true;
}

void battle::setWinner(pokemon p) {
	winner = p;
}

void battle::setLoser(pokemon p) {
	loser = p;
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

pokemon battle::getWinner() {
	return winner;
}

pokemon battle::getLoser() {
	return loser;
}