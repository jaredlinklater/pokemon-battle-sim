#ifndef TRAINER_H
#define TRAINER_H

using namespace std;

class trainer {
public:
	virtual int chooseOption() = 0; //Choose out of fight (1), items (2), pokemon (3) or run (4)
	virtual int chooseMove() = 0; //Choose out of first move (1), second move (2), third move (3) or fourth move(4)
	virtual int chooseItem() = 0; //Choose item to use from list of items
	virtual int choosePokemon() = 0; //Choose pokemon to switch to from team
};

#endif