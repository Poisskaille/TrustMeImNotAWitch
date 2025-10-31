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

	sf::Clock lagClock;

	sf::Clock clock;
	sf::Time deltaTime;

public:
	static collisionsManager* getInstance();

	bool isUsingEntities;
	bool isDeletingEntities;
	bool isDrawingEntities;

	void checkCollisions();

	void garbageClear();

	void garbageAdd(std::shared_ptr<Entity> _entityToAdd);

	void setGameRunning(bool _isGameRunning);
	void setPaused(bool _isPaused);
};

extern collisionsManager* managerCollisions;