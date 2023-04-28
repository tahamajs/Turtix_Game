CC = g++
CFLAGS = -Wall -Werror
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: a.out

a.out: main.o Player.o Enemi.o Game.o Score.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

Player.o: Player.cpp Player.hpp
	$(CC) $(CFLAGS) -c $< -o $@

Enemi.o: Enemi.cpp Enemi.hpp
	$(CC) $(CFLAGS) -c $< -o $@

Game.o: Game.cpp Game.hpp
	$(CC) $(CFLAGS) -c $< -o $@

Score.o: Score.cpp Score.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o a.out
