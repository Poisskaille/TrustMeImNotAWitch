#pragma once
#include "Player.h"
#include "textureManager.h"
#include "Score.h"

class Game {

public:

    Game();
    ~Game();
    void run();
    void init(sf::RenderWindow& window, textureManager& texManager);

private:
	sf::RectangleShape background;
    sf::RenderWindow window;

};
