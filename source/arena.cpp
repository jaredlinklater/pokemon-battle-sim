#include "arena.h"
#include "pokemon.h"
#include <iostream>
#include <vector>
using namespace std;

//Initialises variables upon new instance
void arena::init() {
	pokeAset = 0;
	pokeBset = 0;
	turnCount = 0;
}

//Sets Team A
void arena::setPokeA(pokemon tA) {
	pokeA = tA;
	pokeAset = 1;
}

//Sets Team B
void arena::setPokeB(pokemon tB) {
	pokeB = tB;
	pokeBset = 1;
}

//Conducts battle between two pokemon
void arena::battle() {
	if(!pokeAset) { //Checks if both teams have been set
		cout << "Team A is not ready for battle!" << endl;
		return;
	} else if(!pokeBset) {
		cout << "Team B is not ready for battle!" << endl;
		return;
	}
	cout << "Both teams are ready for battle!" << endl;

	int i = 0;
	while(i++ < 5) {
		doTurn();
	}
}

void arena::doTurn() {
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
	turnCount++;
}