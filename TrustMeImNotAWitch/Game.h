#pragma once
#include "Outils.h"

class Game {

public:

    Game();
    ~Game();
    void run();

private:
    sf::RenderWindow window;
};
