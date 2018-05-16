#include <iostream>
#include <vector>
#include "global.h"
#include "game.h"
#include "trainer.h"
#include "player.h"
#include "ai.h"
#include "arena.h"
#include "pokemon.h"
#include "pokemonMove.h"
using namespace std;

vector<pokemonMove> moveset(pokemonMove a, pokemonMove b, pokemonMove c, pokemonMove d);
int getInput(int min, int max);

vector<pokemon> pokemonList; //Pokemon object is pushed onto this each time pokemon constructor is called

pokemon bulbasaur;
pokemon charmander;
pokemon squirtle;
pokemon eevee;
pokemon porygon;

//Initialises variables upon new instance
void game::init() {
	clearScreen();
	cout << "Welcome to the Pokemon Battle Simulator!" << endl;

	//Initialise random seed
	srand(time(NULL));

	//Declaring moves
	pokemonMove blank("-", 0),
		scratch("Scratch", 40, 100, "normal", "physical"),
		growl("Growl", 0, 100, "normal", "other"),
		tackle("Tackle", 40, 100, "normal", "physical"),
		quick_attack("Quick Attack", 40, 100, "normal", "physical"),
		ember("Ember", 40, 100, "fire", "special"),
		water_gun("Water Gun", 40, 100, "water", "special"),
		vine_whip("Vine Whip", 45, 100, "grass", "physical"),
		razor_leaf("Razor Leaf", 45, 95, "grass", "physical"),
		swift("Swift", 60, 1000, "normal", "special"),
		bite("Bite", 60, 100, "dark", "physical"),
		psybeam("Psybeam", 65, 100, "psychic", "special"),
		slash("Slash", 70, 100, "normal", "physical"),
		thunderbolt("Thunderbolt", 90, 100, "electric", "special"),
		psychic("Psychic", 90, 100, "psychic", "special"),
		tailwhip("Tail Whip", 0, 100, "normal", "other"),
		recover("Recover", 0, 1000, "normal", "other");

	/*** Declare global objects ***/
	//Declaring Pokemon
	//Bulbasaur
	bulbasaur = pokemon("Bulbasaur", "grass -", 294, 197, 229, 197, 229, 189, moveset(tackle, growl, vine_whip, razor_leaf));

	//Charmander
	charmander = pokemon("Charmander", "fire -", 282, 203, 185, 219, 199, 229, moveset(scratch, growl, ember, slash));

	//Squirtle
	squirtle = pokemon("Squirtle", "water -", 292, 195, 229, 199, 227, 185, moveset(tackle, tailwhip, water_gun, bite));

	//Eevee
	eevee = pokemon("Eevee", "normal -", 314, 209, 199, 189, 229, 209, moveset(tackle, quick_attack, bite, swift));

	//Porygon
	porygon = pokemon("Porygon", "normal -", 334, 219, 239, 269, 249, 179, moveset(tackle, psybeam, bite, swift));
}

//Sets up initial game state
void game::start() {
	//Used for game setup
	player playerMain;

	//Possible trainers
	player playerA;
	player playerB;
	ai aiA;
	ai aiB;

	trainer *trainerA;
	trainer *trainerB;

	//Arena setup
	arena arenaA;
	arenaA.init();
	vector<pokemon> teamA;
	vector<pokemon> teamB;

	//Game setup choice
	cout << "Would you like to use express settings (play against AI with random pokemon) or with custom settings?" << endl;
	cout << "1: Express settings" << endl;
	cout << "2: Custom settings" << endl;

	int sel = getInput(1,2);
	if(sel == 1) { //Express settings
		trainerA = &playerA;
		trainerB = &aiA;
		trainerA->setName("RED");
		trainerB->setName("BLUE");

		cout << "Please choose which pokemon you would like to battle with." << endl;
		teamA.push_back(choosePokemon());
		teamB.push_back(pokemonList[randomInt(0,pokemonList.size()-1)]);
	} else if(sel == 2) { //Custom settings
		//Get gamemode
		cout << "Please choose which gamemode you would like:" << endl;
		cout << "1. Player vs AI" << endl;
		cout << "2. Player vs Player" << endl;
		cout << "3. AI vs AI" << endl;

		sel = getInput(1,3);
		switch(sel) {
			case 1: trainerA = &playerA;
					trainerB = &aiA;
					break;
			case 2: trainerA = &playerA;
					trainerB = &playerB;
					break;
			case 3: trainerA = &aiA;
					trainerB = &aiB;
					break;
		}

		//Get trainer names
		cout << "What is " << trainerA->getType() << " 1's name?" << endl;
		trainerA->setName(getInputString(15));
		cout << "What is " << trainerB->getType() << " 2's name?" << endl;
		trainerB->setName(getInputString(15));

		//Get pokemon
		cout << "Please choose which pokemon " << trainerA->getName() << " will battle with." << endl;
		teamA.push_back(choosePokemon());
		cout << "Please choose which pokemon " << trainerB->getName() << " will battle with." << endl;
		teamB.push_back(choosePokemon());
	}

	//Set chosen settings
	arenaA.setTrainerA(trainerA);
	arenaA.setTrainerB(trainerB);
	arenaA.setTeamA(teamA);
	arenaA.setTeamB(teamB);

	//Start battle
	arenaA.startBattle();
}

//Prompts user to select pokemon
pokemon game::choosePokemon() {
	cout << "There are " << pokemonList.size() << " available pokemon, they are:" << endl;
	for(int i = 0; i < pokemonList.size(); i++) {
		cout << i+1 << ": " << pokemonList[i].getName() << endl;
	}

	int sel = getInput(1, pokemonList.size());
	cout << "You chose " << pokemonList[sel-1].getName() << "!" << endl;
	return pokemonList[sel-1];
}

//Pushes 4 pokemonMoves into a vector and returns the vector
vector<pokemonMove> moveset(pokemonMove a, pokemonMove b, pokemonMove c, pokemonMove d) {
	pokemonMove arr[] = {a, b, c, d};
	vector<pokemonMove> moves(arr, arr + sizeof(arr) / sizeof(arr[0]));
	return moves;
}