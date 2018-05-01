#include "arena.h"
#include "battle.h"
#include "trainer.h"
#include "player.h"
#include "ai.h"
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

	player playerA;
	ai aiA;

	trainer *trainerA = &playerA;
	trainer *trainerB = &aiA;

	battle battleA;
	battleA.init();
	battleA.setTrainerA(trainerA);
	battleA.setTrainerB(trainerB);
	battleA.setPokeA(teamA[0]);
	battleA.setPokeB(teamB[0]);
	battleA.start();
}


//Setters
void arena::setTrainerA(trainer *t) {
	trainerA = t;
	trainerAset = 1;
}

void arena::setTrainerB(trainer *t) {
	trainerB = t;
	trainerBset = 1;
}

void arena::setTeamA(vector<pokemon> t) {
	teamA = t;
	teamAset = 1;
}

void arena::setTeamB(vector<pokemon> t) {
	teamB = t;
	teamBset = 1;
}


//Getters
trainer *arena::getTrainerA() {
	return trainerA;
}

trainer *arena::getTrainerB() {
	return trainerB;
}

vector<pokemon> arena::getTeamA() {
	return teamA;
}

vector<pokemon> arena::getTeamB() {
	return teamB;
}