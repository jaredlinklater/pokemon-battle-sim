CXXFLAGS = -std=c++11 -Wall -pedantic

main: main.o game.o arena.o battle.o pokemon.o pokemonMove.o trainer.o player.o ai.o
	g++ -o $@ $^

clean:
	rm *.o 