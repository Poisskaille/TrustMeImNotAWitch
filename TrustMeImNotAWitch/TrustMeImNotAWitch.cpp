#include <iostream>
#include "Game.h"
#include "EntityManager.h"

int main()
{
	Game* game = new Game;
	game->run();
	delete game;
}
