#include "War.h"

void War::play()
{
	Deck mainDeck;

	const int WIN_SIZE = mainDeck.size.();

	for (int i = 0; i < WIN_SIZE; i++)
	{
		if (i % 2 == 0)
		{
			player.addCard(mainDeck.draw());
		}

		else
		{
			ai.addCard(mainDeck.draw());
		}
	}
	
	mainLoop();
}

voi War::mainLoop()
{
	
}