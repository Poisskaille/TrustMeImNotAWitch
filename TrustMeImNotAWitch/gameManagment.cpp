#include "gameManagment.h"

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
	managerEntity->createEnnemies('W', managerText->test, {-400,-400 }, {10,10});
}

void gameManagment::update(sf::RenderWindow* _window)
{
	managerCollisions->garbageClear();
	_window->clear();
	_window->draw(background);
	for (auto& Ennemy : managerEntity->getAllEntities()) { Ennemy->Draw(*_window); }
	managerMap->draw(_window);

	managerEntity->getPlayer()->Draw(*_window);
	_window->display();
}


gameManagment* gameManagment::instance = nullptr;
gameManagment* managerGame = gameManagment::getInstance();