#include "arena.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> empty (1,0);
vector<int> arena::teamEmpty = empty;

//Initialises variables upon new instance
void arena::init() {
	teamA = teamB = teamEmpty;
}

//Sets Team A
void arena::setTeamA(vector<int> tA) {
	teamA = tA;
}

//Sets Team B
void arena::setTeamB(vector<int> tB) {
	teamB = tB;
}

void arena::battle() {
	if(teamA == teamEmpty) { //Checks if both teams have been set
		cout << "Team A is not ready for battle!" << endl;
		return;
	} else if(teamB == teamEmpty) {
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