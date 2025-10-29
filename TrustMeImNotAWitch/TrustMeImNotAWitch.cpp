#include "Game.h"

int main()
{
	std::srand(int(time(nullptr)));
	Game* game = new Game;
	game->run();
	delete game;
}
