#include "gameManagment.h"
#include "teste.h"

gameManagment::gameManagment(sf::RenderWindow* _window, float _updateDeltaTime) 
	: window(_window), _updateClock(sf::Clock()), _updateDeltaTime(_updateDeltaTime), _isGameRunning(true), _isPaused(false)
{
	EntityManager* ent = EntityManager::getInstance();
	Collisions* coll = Collisions::getInstance();

	std::shared_ptr<teste> t = std::make_shared<teste>();

	std::thread tz(t->trythis());

	tCollisions.join();

	while (_isGameRunning)
	{
		while (!_isPaused)
		{

		}
	}
}

gameManagment::~gameManagment() {}