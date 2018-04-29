#include "arena.h"
#include "battle.h"
#include "pokemon.h"
#include <iostream>
#include <vector>
using namespace std;

//Initialises variables upon new instance
void arena::init() {
	teamAset = 0;
	teamBset = 0;
}

//Checks if teams are ready, and starts battles between two pokemon
void arena::startBattle() {
	if(!teamAset) { //Checks if both teams have been set
		cout << "Team A is not ready for battle!" << endl;
		return;
	} else if(!teamBset) {
		cout << "Team B is not ready for battle!" << endl;
		return;
	}
	cout << "Both teams are ready for battle!" << endl;

	battle battleA;
	battleA.init();
	battleA.setPokeA(teamA[0]);
	battleA.setPokeB(teamB[0]);
	battleA.start();
}

//Sets Team A
void arena::setTeamA(vector<pokemon> t) {
	teamA = t;
	teamAset = 1;
}

//Sets Team B
void arena::setTeamB(vector<pokemon> t) {
	teamB = t;
	teamBset = 1;
}