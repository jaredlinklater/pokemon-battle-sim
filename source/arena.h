#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include "trainer.h"
#include "pokemon.h"
using namespace std;

class arena {
public:
	trainer *trainerA; //Trainers in the arena
	trainer *trainerB;
	vector<pokemon> teamA; //Teams in the arena
	vector<pokemon> teamB;
	bool trainerAset;
	bool trainerBset;
	bool teamAset;
	bool teamBset;

	void init();
	void startBattle();


	//Setters
	void setTrainerA(trainer *t);
	void setTrainerB(trainer *t);
	void setTeamA(vector<pokemon> tA);
	void setTeamB(vector<pokemon> tB);

	//Getters
	trainer *getTrainerA();
	trainer *getTrainerB();
	vector<pokemon> getTeamA();
	vector<pokemon> getTeamB();
};

#endif