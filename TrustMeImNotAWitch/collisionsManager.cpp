#include "collisionsManager.h"

collisionsManager* collisionsManager::getInstance()
{
	if (instance == nullptr) { instance = new collisionsManager(); }
	return instance;
}

collisionsManager::collisionsManager() : isGameRunning(true), isPaused(false) {std::cout << "initialisation" << std::endl;}

void collisionsManager::setGameRunning(bool _isGameRunning) { isGameRunning = _isGameRunning; };

void collisionsManager::setPaused(bool _isPaused) { isPaused = _isPaused; };

void collisionsManager::garbageAdd(std::shared_ptr<Entity> _entityToAdd)
{
	for (auto& EntityGarbage : garbage)
	{
		if (EntityGarbage == _entityToAdd)
		{
			return;
		}
	}
	garbage.push_back(_entityToAdd);
}

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
						switch (EntityCheaked->tag)
						{
						case 'E':
							if (!(std::dynamic_pointer_cast<Ennemy>(EntityCheaked)->getTagEnnemie() == 'P' && Entity->tag == 'B'))
							{
								garbageAdd(EntityCheaked);
								std::cout << managerEntity->getAllEnnemies().size() << '\n';
							}
							else
							{
								//TODO : Panneau renvoie la balle vers le joueur
							}
							break;
						case 'P':
							//garbageAdd(EntityCheaked);
							std::cout << "Player hitted" << '\n';
							break;
						case 'B':
							if (Entity->tag == 'E')
							{
								if (!(std::dynamic_pointer_cast<Ennemy>(Entity)->getTagEnnemie() == 'P'))
								{
									garbageAdd(EntityCheaked);
								}
							}
							else
							{
								garbageAdd(EntityCheaked);
							}
							break;
						default:
							garbageAdd(EntityCheaked);
							break;
						}
					}
				}
			}
			if (managerEntity->getAllPlayers().size() != 0)
			{
				managerEntity->getPlayer()->update();
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