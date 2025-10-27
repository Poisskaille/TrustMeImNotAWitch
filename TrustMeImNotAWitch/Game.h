#pragma once
#include "memory.h"
#include "map.h"
#include "Menu.h"
#include "Player.h"
#include "textureManager.h"
#include "Score.h"
#include "gameManagment.h"

class Game {

public:

    Game();
    ~Game();
    void run();

private:
    sf::RenderWindow window;
};
