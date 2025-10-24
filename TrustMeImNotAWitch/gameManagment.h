#pragma once
#include <thread>
#include <SFML/Graphics.hpp>
#include "entityManager.h"
#include "collisionsManager.h"
#include "map.h"

class gameManagment
{
private:
	static gameManagment* instance;
	gameManagment();

	//Local variables
	sf::Clock _updateClock;
	sf::RectangleShape background;

public:

	static gameManagment* getInstance();

	void init(textureManager& texManager);

	void update(sf::RenderWindow* _window);
};

extern gameManagment* managerGame;