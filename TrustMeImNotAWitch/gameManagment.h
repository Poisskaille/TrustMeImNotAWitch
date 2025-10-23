#pragma once
#include <thread>
#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "Collisions.h"
#include "projectiles.h"
#include "test.h"

class gameManagment
{
private:
	//Reference of the window that contain the game
	sf::RenderWindow* window;

	//Local variables
	sf::Clock _updateClock;
	float _updateDeltaTime;
	bool _isPaused;
	bool _isGameRunning;

	//Threads
	std::thread tCollisions;


public:
	gameManagment(sf::RenderWindow* _window, float _updateDeltaTime);
	~gameManagment();

	void test();

	void update();
};

