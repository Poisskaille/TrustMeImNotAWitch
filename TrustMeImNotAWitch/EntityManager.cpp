#include "entityManager.h"

entityManager* entityManager::getInstance()
{
	if (instance == nullptr) { instance = new entityManager(); }
	return instance;
}

entityManager::~entityManager()
{
	allPlayers.clear();
	allprojectiles.clear();
	allEnnemies.clear();
	allEntities.clear();
}

void entityManager::createPlayer(sf::Texture& _textPlayer, textureManager& _texManager)
{
	std::shared_ptr<Player> p = std::make_shared<Player>(_textPlayer, _texManager);
	allPlayers.push_back(p);
	allEntities.push_back(p);
}

void entityManager::createProjectiles(sf::Texture& _text, sf::Vector2f _pos, sf::Vector2f _direction)
{
	std::shared_ptr<Projectiles> pr = std::make_shared<Projectiles>(_text, _pos, _direction);
	allprojectiles.push_back(pr);
	allEntities.push_back(pr);
}

void entityManager::deleteEntity(std::shared_ptr<Entity>& _entity)
{
	allEntities.erase(std::remove(allEntities.begin(), allEntities.end(), _entity), allEntities.end());

	switch (_entity->tag)
	{
	case 'P':
		for (auto& Entity : allPlayers)
		{
			if (Entity == _entity)
			{
				allPlayers.erase(std::remove(allPlayers.begin(), allPlayers.end(), Entity), allPlayers.end());
				break;
			}
		}
		break;
	case 'E':
		for (auto& Entity : allEnnemies)
		{
			if (Entity == _entity)
			{
				allEnnemies.erase(std::remove(allEnnemies.begin(), allEnnemies.end(), Entity), allEnnemies.end());
				break;
			}
		}
		break;
	case 'B':
		for (auto& Entity : allprojectiles)
		{
			if (Entity == _entity)
			{
				allprojectiles.erase(std::remove(allprojectiles.begin(), allprojectiles.end(), Entity), allprojectiles.end());
				break;
			}
		}
		break;
	default:
		break;
	}
}

std::vector<std::shared_ptr<Entity>> entityManager::getAllEntities() const { return allEntities; }

std::vector<std::shared_ptr<Entity>> entityManager::getAllPlayers() const { return allPlayers; }
std::vector<std::shared_ptr<Entity>> entityManager::getAllEnnemies() const { return allEnnemies; }

std::vector<std::shared_ptr<Entity>> entityManager::getAllProjectiles() const { return allprojectiles; }


entityManager* entityManager::instance = nullptr;
entityManager* managerEntity = entityManager::getInstance();