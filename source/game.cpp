#include <iostream>
#include <vector>
#include "game.h"
#include "trainer.h"
#include "player.h"
#include "ai.h"
#include "arena.h"
#include "pokemon.h"
#include "pokemonMove.h"
using namespace std;

pokemon bulbasaur;
pokemon charmander;
pokemon squirtle;

//Initialises variables upon new instance
void game::init() {
	cout << "Welcome to the Pokemon Battle Simulator!" << endl;

	/*** Declare global objects ***/
	//Declaring moves
	pokemonMove blank("-", 0),
		scratch("Scratch", 40),
		growl("Growl", 0),
		tailwhip("Tail Whip", 0),
		tackle("Tackle", 40),
		quickattack("Quick Attack", 30),
		thunderbolt("Thunderbolt", 60),
		psychic("Psychic", 80);

	//Declaring Pokemon
	//Bulbasaur
	vector<pokemonMove> bulbasaurMoves;
	bulbasaurMoves.push_back(tackle);
	bulbasaurMoves.push_back(growl);
	bulbasaurMoves.push_back(blank);
	bulbasaurMoves.push_back(blank);
	bulbasaur = pokemon("Bulbasaur", 100, bulbasaurMoves);

	//Charmander
	vector<pokemonMove> charmanderMoves;
	charmanderMoves.push_back(scratch);
	charmanderMoves.push_back(growl);
	charmanderMoves.push_back(blank);
	charmanderMoves.push_back(blank);
	charmander = pokemon("Charmander", 80, charmanderMoves);

	//Squirtle
	vector<pokemonMove> squirtleMoves;
	squirtleMoves.push_back(tackle);
	squirtleMoves.push_back(tailwhip);
	squirtleMoves.push_back(blank);
	squirtleMoves.push_back(blank);
	squirtle = pokemon("Squirtle", 120, squirtleMoves);
}

void game::start() {
	//Set up arena
	cout << "Let's get the arena ready for you." << endl;
	arena arenaA;
	arenaA.init();

	//Create and set trainers
	player playerA;
	ai aiA;

	playerA.setName("RED");
	aiA.setName("BLUE");

	trainer *trainerA = &playerA;
	trainer *trainerB = &aiA;

	arenaA.setTrainerA(trainerA);
	arenaA.setTrainerB(trainerB);

	//Create and set pokemon teams
	vector<pokemon> teamA;
	teamA.push_back(bulbasaur);

	vector<pokemon> teamB;
	teamB.push_back(charmander);

	arenaA.setTeamA(teamA);
	arenaA.setTeamB(teamB);

	//Start battle
	arenaA.startBattle();
}