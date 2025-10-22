#include "EntityManager.h"

EntityManager* EntityManager::getInstance()
{
	if (instance == nullptr) { instance = new EntityManager(); }
	return instance;
}

EntityManager::~EntityManager()
{
	allPlayers.clear();
	allprojectiles.clear();

	allEnnemies.clear();
	allEntities.clear();
}

void EntityManager::createPlayer(sf::Vector2f _pos, sf::Texture& _textPlayer, sf::Texture& _textPlayerJumpEffect, sf::Texture& _textPlayerLandEffect, float _speed, int _hp)
{
	std::shared_ptr<Player> p = std::make_shared<Player>(_pos, _textPlayer, _textPlayerJumpEffect, _textPlayerLandEffect, _speed, _hp);
	allPlayers.push_back(p);
	allEntities.push_back(p);
}

void EntityManager::createProjectiles(sf::Vector2f _pos, sf::Texture& _text, std::string _direction)
{
	std::shared_ptr<Projectiles> pr = std::make_shared<Projectiles>(_pos, _text, _direction);
	allprojectiles.push_back(pr);
	allEntities.push_back(pr);
}

void EntityManager::deleteEntity(std::shared_ptr<Entity>& _entity)
{
	/*switch (_entity)
	{
	default:
		break;
	}*/
}

std::vector<std::shared_ptr<Entity>> EntityManager::getAllEntities() const { return allEntities; }

std::vector<std::shared_ptr<Entity>> EntityManager::getAllPlayers() const { return allPlayers; }
std::vector<std::shared_ptr<Entity>> EntityManager::getAllEnnemies() const { return allEnnemies; }

std::vector<std::shared_ptr<Entity>> EntityManager::getAllProjectiles() const { return allprojectiles; }