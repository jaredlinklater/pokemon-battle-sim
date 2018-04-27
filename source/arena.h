#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include "pokemon.h"
using namespace std;

class arena {
public:
	pokemon pokA;
	pokemon pokB;
	bool pokAset;
	bool pokBset;
	int victor;

	void setTeamA(pokemon tA);
	void setTeamB(pokemon tB);

	void init();
	void battle();
};

#endif