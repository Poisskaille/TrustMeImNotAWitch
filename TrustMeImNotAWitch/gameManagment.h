#pragma once
#include <thread>
#include <iostream>
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
	sf::Clock _clock;
	sf::RectangleShape background;

public:

	static gameManagment* getInstance();

	void init();

	void update(sf::RenderWindow* _window);
};

extern gameManagment* managerGame;