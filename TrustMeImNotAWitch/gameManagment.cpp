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
	managerMap->init();

	sf::Clock clock;
	managerMap->loadAllSections();
	managerMap->generate();

	background.setTexture(&managerText->backgroundTexture);
	background.setSize(sf::Vector2f(1920.f, 1080.f));

	managerEntity->createPlayer(managerText->test);
}

void gameManagment::update(sf::RenderWindow* _window)
{
	if (managerEntity->getAllPlayers().size() != 0){ managerEntity->getPlayer()->Update(managerMap->getSolidTiles()); }
	managerCollisions->garbageClear();
	_window->clear();
	_window->draw(background);
	managerEntity->getPlayer()->Draw(*_window);
	_window->display();
}


gameManagment* gameManagment::instance = nullptr;
gameManagment* managerGame = gameManagment::getInstance();