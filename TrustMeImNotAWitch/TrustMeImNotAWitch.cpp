#include "Game.h"
#include <cstdlib>
#include <ctime>

int main()
{
	Game* game = new Game;
	game = new Game;
	srand(static_cast<unsigned>(time(0)));
	game->run();
	delete game;
}
