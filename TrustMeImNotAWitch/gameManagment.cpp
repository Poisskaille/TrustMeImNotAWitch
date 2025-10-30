#include "gameManagment.h"

gameManagment* gameManagment::getInstance()
{
	if (instance == nullptr) { instance = new gameManagment(); }
	return instance;
}

gameManagment::gameManagment() : _clock(sf::Clock()) {}

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
	_clock.restart();
	managerCollisions->garbageClear();
	_window->clear();
	_window->draw(background);
	for (auto& Ennemy : managerEntity->getAllEntities()) { Ennemy->Draw(*_window); }
	managerMap->draw(_window);


	for (auto& ennemy : managerEntity->getAllEnnemies()) 
	{ 
		if (managerEntity->getPlayer()->getPos().x - std::dynamic_pointer_cast<Ennemy>(ennemy)->getPos().x > 500.f)
		{
			managerCollisions->garbageAdd(ennemy);
		}
		else
		{
			std::dynamic_pointer_cast<Ennemy>(ennemy)->update(_clock.getElapsedTime().asSeconds());
		}
		ennemy->Draw(*_window);
	}

	for (auto& projectiles : managerEntity->getAllProjectiles())
	{
		if (managerEntity->getPlayer()->getPos().x - std::dynamic_pointer_cast<Projectiles>(projectiles)->getPos().x > 500.f)
		{
			managerCollisions->garbageAdd(projectiles);
		}
		else
		{
			std::dynamic_pointer_cast<Projectiles>(projectiles)->update(_clock.getElapsedTime().asSeconds());
		}
		projectiles->Draw(*_window);
	}

	managerMap->draw(_window);
	managerEntity->getPlayer()->Draw(*_window);
	_window->display();
}


gameManagment* gameManagment::instance = nullptr;
gameManagment* managerGame = gameManagment::getInstance();