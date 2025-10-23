#include <iostream>
#include "Game.h"
#include "EntityManager.h"

int main()
{
	Collisions::instance;
	//EntityManager::instance;
	Game* game = new Game;
	game->run();
	delete game;
}
