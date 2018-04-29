#include "battle.h"
#include "pokemon.h"
#include <iostream>
#include <vector>
using namespace std;

//Initialises variables upon new instance
void battle::init() {
	//
	pokeAset = 0;
	pokeBset = 0;
	turnCount = 0;
}

//
void battle::start() {
	/*int i = 0;
	while(teamA.getHp() != 0 || teamB.getHp() != 0) {
		doTurn();
	}*/
}

//
void battle::doTurn() {
	pokemon attacker;
	pokemon defender;
	if(turnCount % 2 == 0) { //pokA attacks on even turns
		attacker = pokeA;
		defender = pokeB;
	} else { //pokB attacks on odd turns
		attacker = pokeB;
		defender = pokeA;
	}
	cout << attacker.getName() << "'s turn" << endl;
	attacker.setHp(attacker.getHp()-20);



	if(turnCount % 2 == 0) { //pokA attacks on even turns
		pokeA = attacker;
		pokeB = defender;
	} else { //pokB attacks on odd turns
		pokeB = attacker;
		pokeA = defender;
	}
	pokeA = attacker;
	turnCount++;
}

//Sets Team A
void battle::setPokeA(pokemon p) {
	pokeA = p;
	pokeAset = 1;
}

//Sets Team B
void battle::setPokeB(pokemon p) {
	pokeB = p;
	pokeBset = 1;
}