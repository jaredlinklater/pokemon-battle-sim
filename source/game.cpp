#include <iostream>
#include <sstream>
#include <vector>
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

vector<pokemon> pokemonList; //Pokemon is pushed onto this each time pokemon constructor is called

pokemon bulbasaur;
pokemon charmander;
pokemon squirtle;
pokemon eevee;
pokemon porygon;

//Initialises variables upon new instance
void game::init() {
	cout << "Welcome to the Pokemon Battle Simulator!" << endl;

	/*** Declare global objects ***/
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
	//Set up arena
	cout << "Let's get the arena ready for you." << endl;
	arena arenaA;
	arenaA.init();

	//Create and set trainers
	player playerA;
	playerA.setType("player");
	playerA.setName("RED");

	ai aiA;
	aiA.setType("ai");
	aiA.setName("BLUE");

	trainer *trainerA = &playerA;
	trainer *trainerB = &aiA;

	arenaA.setTrainerA(trainerA);
	arenaA.setTrainerB(trainerB);

	//Create and set pokemon teams
	choosePokemon();

	vector<pokemon> teamA;
	teamA.push_back(pokeA);

	vector<pokemon> teamB;
	teamB.push_back(charmander);

	arenaA.setTeamA(teamA);
	arenaA.setTeamB(teamB);

	//Start battle
	arenaA.startBattle();
}

//Prompts user to select pokemon
void game::choosePokemon() {
	cout << "Please choose which pokemon you would like to battle with." << endl;
	cout << "There are " << pokemonList.size() << " available pokemon, they are:" << endl;
	for(int i = 0; i < pokemonList.size(); i++) {
		cout << i+1 << ": " << pokemonList[i].getName() << endl;
	}

	int sel = getInput(1, pokemonList.size());
	cout << "You chose " << pokemonList[sel-1].getName() << "!" << endl;
	pokeA = pokemonList[sel-1];
}

//Pushes 4 pokemonMoves into a vector and returns the vector
vector<pokemonMove> moveset(pokemonMove a, pokemonMove b, pokemonMove c, pokemonMove d) {
	pokemonMove arr[] = {a, b, c, d};
	vector<pokemonMove> moves(arr, arr + sizeof(arr) / sizeof(arr[0]));
	return moves;
}

//Gets int input from command line and error checks
int getInput(int min, int max) {
	int input;
	string x;

	getline(cin, x);
	stringstream(x) >> input;
	while(!(input >= min && input <= max)) { //Error checking
		cout << "Invalid selection! Please enter a number from " << min << " to " << max << "." << endl;
		getline(cin, x);
		stringstream(x) >> input;
	}

	return input;
}