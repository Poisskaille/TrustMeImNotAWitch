#include <iostream>
#include "Game.h"
#include "entityManager.h"

int main()
{
	Game* game = new Game;
	game->run();
	delete game;
}
