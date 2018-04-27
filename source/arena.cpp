#include "arena.h"
#include "pokemon.h"
#include <iostream>
#include <vector>
using namespace std;

//Initialises variables upon new instance
void arena::init() {
	pokAset = 0;
	pokBset = 0;
}

//Sets Team A
void arena::setTeamA(pokemon tA) {
	pokA = tA;
	pokAset = 1;
}

//Sets Team B
void arena::setTeamB(pokemon tB) {
	pokA = tB;
	pokBset = 1;
}

//Conducts battle between two pokemon
void arena::battle() {
	if(!pokAset) { //Checks if both teams have been set
		cout << "Team A is not ready for battle!" << endl;
		return;
	} else if(!pokBset) {
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