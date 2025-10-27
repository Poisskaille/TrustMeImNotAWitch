#include "gameManagment.h"
#include <iostream>

gameManagment* gameManagment::getInstance()
{
	if (instance == nullptr) { instance = new gameManagment(); }
	return instance;
}

gameManagment::gameManagment() : _updateClock(sf::Clock()) {}

void gameManagment::init()
{
	managerText->loadAll();
	managerMap->initMap();

	sf::Clock clock;

	background.setTexture(&managerText->backgroundTexture);
	background.setSize(sf::Vector2f(1920.f, 1080.f));

	managerEntity->createPlayer(managerText->test);
}

void gameManagment::update(sf::RenderWindow* _window)
{
	if (managerEntity->getAllPlayers().size() != 0){ managerEntity->getPlayer()->Update(); }
	managerCollisions->garbageClear();
	_window->clear();
	_window->draw(background);
	managerMap->draw(_window);
	managerEntity->getPlayer()->Draw(*_window);
	_window->display();
}


gameManagment* gameManagment::instance = nullptr;
gameManagment* managerGame = gameManagment::getInstance();