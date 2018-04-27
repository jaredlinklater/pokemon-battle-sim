#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include "pokemon.h"
using namespace std;

class arena {
public:
	pokemon teamA;
	pokemon teamB;
	pokemon teamEmpty;
	int victor;

	void setTeamA(pokemon tA);
	void setTeamB(pokemon tB);

	void init();
	void battle();
};

#endif