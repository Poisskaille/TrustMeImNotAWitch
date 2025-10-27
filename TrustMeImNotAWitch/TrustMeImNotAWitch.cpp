#include <iostream>
#include "Game.h"
#include "entityManager.h"

int main()
{
	std::srand(time(nullptr));
	Game* game = new Game;
	game->run();
	delete game;
}
