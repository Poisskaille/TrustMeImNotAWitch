#pragma once
#include "entityManager.h"
#include <iostream>

class collisionsManager
{
private:
	collisionsManager();
	static collisionsManager* instance;

	bool isPaused;
	bool isGameRunning;

	std::vector<std::shared_ptr<Entity>> garbage;

	sf::Clock lagClock;

public:
	static collisionsManager* getInstance();

	void checkCollisions();

	void garbageClear();

	void setGameRunning(bool _isGameRunning);
	void setPaused(bool _isPaused);
};

extern collisionsManager* managerCollisions;