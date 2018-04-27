#include "arena.h"
#include "pokemon.h"
#include <iostream>
#include <vector>
using namespace std;

//Initialises variables upon new instance
void arena::init() {
	pokemon uninit;
	uninit.setId(-1);
	teamEmpty = uninit;
	teamA = teamB = teamEmpty;
}

//Sets Team A
void arena::setTeamA(pokemon tA) {
	teamA = tA;
}

//Sets Team B
void arena::setTeamB(pokemon tB) {
	teamB = tB;
}

void arena::battle() {
	if(teamA.id == teamEmpty.id) { //Checks if both teams have been set
		cout << "Team A is not ready for battle!" << endl;
		return;
	} else if(teamB.id == teamEmpty.id) {
		cout << "Team B is not ready for battle!" << endl;
		return;
	}
	cout << "Both teams are ready for battle!" << endl;

	while(true) {
		if(1) {
			break;
		}
	}
}