main: main.o
	g++ -std=c++11 -o $@ $^

clean:
	rm main *.o 