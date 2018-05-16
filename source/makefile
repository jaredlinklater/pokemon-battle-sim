CXXFLAGS = -std=c++11 -Wall -pedantic

main:  main.o global.o game.o arena.o battle.o attack.o pokemon.o pokemonMove.o trainer.o player.o ai.o
	g++ -o $@ $^

clean:
	rm *.o 