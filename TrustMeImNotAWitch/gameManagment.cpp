#include "gameManagment.h"
#include <iostream>

gameManagment* gameManagment::getInstance()
{
	if (instance == nullptr) { instance = new gameManagment(); }
	return instance;
}

gameManagment::gameManagment() : _updateClock(sf::Clock()) {}

void gameManagment::init(textureManager& texManager)
{
	background.setTexture(&texManager.backgroundTexture);
	background.setSize(sf::Vector2f(1920.f, 1080.f));
}

void gameManagment::update(sf::RenderWindow* _window)
{
	managerCollisions->garbageClear();
	_window->clear();
	_window->draw(background);
	_window->display();
}


gameManagment* gameManagment::instance = nullptr;
gameManagment* managerGame = gameManagment::getInstance();