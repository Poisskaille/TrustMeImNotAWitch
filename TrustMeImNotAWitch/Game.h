#pragma once
#include "Player.h"
#include "textureManager.h"
#include "gameManagment.h"

class Game {

public:

    Game();
    ~Game();
    void run();

private:
    sf::RenderWindow window;
};
