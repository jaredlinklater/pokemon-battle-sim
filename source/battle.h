#ifndef BATTLE_H
#define BATTLE_H

#include "trainer.h"
#include "pokemon.h"
#include "pokemonMove.h"
using namespace std;

class battle {
public:
	trainer *trainerA; //Trainers in the battle
	trainer *trainerB;
	pokemon pokeA; //Pokemon in the battle (main memory)
	pokemon pokeB;
	int pokeAset;
	int pokeBset;
	int turnCount;

	trainer *turnPlayer; //Used to keep track of turn player (controller for that turn)
	pokemon attacker; //Copies of pokeA & pokeB that are copied to, altered and wrote back each turn (temp memory)
	pokemon defender;
	pokemonMove move; //Selected move for the turn

	void init();
	void start();
	void startTurn();
	void doTurn();
	void endTurn();

	void doAttack();


	//Setters
	void setTrainerA(trainer *t);
	void setTrainerB(trainer *t);
	void setPokeA(pokemon p);
	void setPokeB(pokemon p);
	void setTurnPlayer(trainer *t);
	void setAttacker(pokemon p);
	void setDefender(pokemon p);

	//Getters
	trainer *getTrainerA();
	trainer *getTrainerB();
	pokemon getPokeA();
	pokemon getPokeB();
	trainer *getTurnPlayer();
	pokemon getAttacker();
	pokemon getDefender();
};

#endif