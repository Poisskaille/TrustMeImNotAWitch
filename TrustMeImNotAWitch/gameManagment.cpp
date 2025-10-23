#include "gameManagment.h"
#include "test.h"

gameManagment::gameManagment(sf::RenderWindow* _window, float _updateDeltaTime) 
	: window(_window), _updateClock(sf::Clock()), _updateDeltaTime(_updateDeltaTime), _isGameRunning(true), _isPaused(false)
{
	EntityManager* ent = EntityManager::getInstance();
	Collisions* coll = Collisions::getInstance();

	//std::thread t(test::trythis);
	//tCollisions.join();

	while (_isGameRunning)
	{
		while (!_isPaused)
		{

		}
	}
}