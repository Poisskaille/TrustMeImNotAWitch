#include "gameManagment.h"

gameManagment::gameManagment(sf::RenderWindow* _window, float _updateDeltaTime) 
	: window(_window), updateClock(sf::Clock()), updateDeltaTime(_updateDeltaTime), isGameRunning(true), isPaused(false)
{
	while (isGameRunning)
	{
		while (!isPaused)
		{

		}
	}
}