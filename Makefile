CC = g++
CFLAGS = -std=c++11
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

all: graphics

graphics: graphics.cpp
	$(CC) $(CFLAGS) $< -o $@ $(SFML_LIBS)

clean:
	rm -f graphics
