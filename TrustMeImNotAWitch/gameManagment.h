#pragma once
#include <thread>
#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "Collisions.h"

class gameManagment
{
private:
	sf::RenderWindow* window;
	sf::Clock updateClock;

	float updateDeltaTime;
	bool isPaused;
	bool isGameRunning;

public:
	gameManagment(sf::RenderWindow* _window, float _updateDeltaTime);
	~gameManagment();

	void update();
};

