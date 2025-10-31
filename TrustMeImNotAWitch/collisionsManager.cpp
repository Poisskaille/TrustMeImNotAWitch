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
	clock.restart();
	unsigned long long iterations = 0;
	lagClock.restart();
	while (isGameRunning)
	{
		if (!isPaused)
		{

			deltaTime = clock.getElapsedTime();
			clock.restart();
			isUsingEntities = true;
			while (isDeletingEntities || isDrawingEntities) {}
			for (auto& Entity : managerEntity->getAllEntities())
			{
				for (auto& EntityCheaked : managerEntity->getAllEntities())
				{
					try
					{
						if(Entity != nullptr && EntityCheaked != nullptr){
							if (Entity->tag != EntityCheaked->tag && Entity->isColliding(EntityCheaked.get()))
							{
								switch (EntityCheaked->tag)
								{
								case 'P':
									std::cout << "Player hitted" << '\n';
									//garbageAdd(EntityCheaked);
									break;
								case 'E':
									if (!(std::dynamic_pointer_cast<Ennemy>(EntityCheaked)->getTagEnnemie() == 'P' && Entity->tag == 'B'))
									{
										garbageAdd(EntityCheaked);
									}
									else
									{
										//TODO ennemie panneau, logic renvoie de balle
									}
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
								case 'U':
									if (Entity->tag == 'P')
									{
										switch (std::dynamic_pointer_cast<PowerUp>(EntityCheaked)->getType())
										{
										case PowerType::GOLD:
											managerScore->addScore(100);
											break;
										case PowerType::SCORE_BOOST:
											managerScore->changeMultiplier(3);
											break;
										case PowerType::SHIELD:
											break;
										}
										garbageAdd(EntityCheaked);
									}
									break;
								default:
									throw std::runtime_error("WTF did i just hitted ?\nEntity tag: " + std::string(1, Entity->tag) + "\nEntityCheaked tag: " + std::string(1, EntityCheaked->tag));
									break;
								}
							}
						}
					}
					catch (const std::exception& e)
					{
						std::cout << e.what() << '\n';
					}
				}
			}
			if (managerEntity->getAllPlayers().size() != 0)
			{
				managerEntity->getPlayer()->update(deltaTime.asSeconds());
			}
			if (managerEntity->getAllEnnemies().size() != 0)
			{
				for (auto& ennemi : managerEntity->getAllEnnemies())
				{
					ennemi->update(deltaTime.asSeconds());
				}
			}
			isUsingEntities = false;
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
	while (isUsingEntities || isDrawingEntities) {}
	isDeletingEntities = true;
	for (auto& Entity : garbage)
	{
		managerEntity->deleteEntity(Entity);
	}
	garbage.clear();
	isDeletingEntities = false;
};

collisionsManager* collisionsManager::instance = nullptr;
collisionsManager* managerCollisions = collisionsManager::getInstance();