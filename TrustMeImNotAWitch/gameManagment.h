#pragma once
#include "Outils.h"

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

	void init();

	void update(sf::RenderWindow* _window);
};

extern gameManagment* managerGame;