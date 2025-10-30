#include "Game.h"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(static_cast<unsigned>(time(0)));
	Game* game = new Game;
	game->run();
	delete game;
}
