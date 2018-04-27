#include <vector>
#include "game.h"
#include "pokemon.h"
#include "pokemonMove.h"
using namespace std;

int game::gameOver = 1;

extern pokemon bulbasaur;
extern pokemon charmander;
extern pokemon squirtle;

//Initialises variables upon new instance
void game::init() {
	gameOver = 0;

	/*** Declare global objects ***/
	//Declaring moves
	pokemonMove blank("-",0),
		scratch("Scratch",40),
		growl("Growl",0),
		tailwhip("Tail Whip",0),
		tackle("Tackle", 40),
		quickattack("Quick Attack", 30),
		thunderbolt("Thunderbolt", 60),
		psychic("Psychic",80);

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