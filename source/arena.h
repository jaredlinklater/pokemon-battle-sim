#ifndef ARENA_H
#define ARENA_H

#include <vector>
using namespace std;

class arena {
public:
	vector<int> teamA;
	vector<int> teamB;
	static vector<int> teamEmpty;
	int victor;

	void init();
	void setTeamA(vector<int> tA);
	void setTeamB(vector<int> tB);
	void battle();
};

#endif