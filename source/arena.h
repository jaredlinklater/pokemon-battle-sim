#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include "pokemon.h"
using namespace std;

class arena {
public:
	vector<pokemon> teamA;
	vector<pokemon> teamB;
	bool teamAset;
	bool teamBset;
	int victor;

	void init();
	void startBattle();
	void doTurn();

	//Setters
	void setTeamA(vector<pokemon> tA);
	void setTeamB(vector<pokemon> tB);
};

#endif