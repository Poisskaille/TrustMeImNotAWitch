#include "collisionsManager.h"

collisionsManager* collisionsManager::getInstance()
{
	if (instance == nullptr) { instance = new collisionsManager(); }
	return instance;
}

collisionsManager::collisionsManager() : isGameRunning(true), isPaused(false) {std::cout << "initialisation" << std::endl;}

void collisionsManager::setGameRunning(bool _isGameRunning) { isGameRunning = _isGameRunning; };

void collisionsManager::setPaused(bool _isPaused) { isPaused = _isPaused; };

void collisionsManager::checkCollisions()
{
	unsigned long long iterations = 0;
	lagClock.restart();
	while (isGameRunning)
	{
		if (!isPaused)
		{
			for (auto& Entity : managerEntity->getAllEntities())
			{
				for (auto& EntityCheaked : managerEntity->getAllEntities())
				{
					if (Entity->tag != EntityCheaked->tag && Entity->isColliding(EntityCheaked.get()))
					{
						/*if (EntityCheaked->tag == 'E')
						{
							if (!std::dynamic_pointer_cast<Ennemy>(EntityCheaked)->tagSpecial == 'P')
							{
								garbage.push_back(EntityCheaked);
							}
						}
						else
						{
							garbage.push_back(EntityCheaked);
						}*/
					}
				}
			}
			if (lagClock.getElapsedTime().asMilliseconds() >= 1000.f)
			{
				std::cout << iterations << " TPS" << std::endl;
				iterations = 0;
				lagClock.restart();
			}
			else
			{
				iterations++;
			}
		}
	}
}

void collisionsManager::garbageClear()
{
	for (auto& Entity : garbage)
	{
		managerEntity->deleteEntity(Entity);
	}
	garbage.clear();
};

collisionsManager* collisionsManager::instance = nullptr;
collisionsManager* managerCollisions = collisionsManager::getInstance();