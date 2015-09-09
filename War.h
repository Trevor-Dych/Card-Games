#ifndef WAR_H
#define WAR_H

#include "Deck.h"

class War
{
private:
	void mainLoop();
	// The main loop of the game

	Deck player, ai;

public:
	void play();
	// Instantiates the game

};

#endif