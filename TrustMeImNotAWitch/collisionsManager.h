#pragma once
#include "entityManager.h"

class collisionsManager
{
private:
	collisionsManager();
	static collisionsManager* instance;

	bool isPaused;
	bool isGameRunning;

	std::vector<std::shared_ptr<Entity>> garbage;

	void garbageAdd(std::shared_ptr<Entity> _entityToAdd);

	sf::Clock lagClock;

public:
	static collisionsManager* getInstance();

	void checkCollisions();

	void garbageClear();

	void setGameRunning(bool _isGameRunning);
	void setPaused(bool _isPaused);
};

extern collisionsManager* managerCollisions;