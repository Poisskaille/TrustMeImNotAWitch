#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "Projectiles.h"

class EntityManager
{
private:
	EntityManager() {}

	std::vector<std::shared_ptr<Entity>> allEntities;

	std::vector<std::shared_ptr<Entity>> allPlayers;
	std::vector<std::shared_ptr<Entity>> allEnnemies;

	std::vector<std::shared_ptr<Entity>> allprojectiles;


public:
	static EntityManager* instance;
	static EntityManager* getInstance();
	~EntityManager();
	void createProjectiles(sf::Texture& _text, sf::Vector2f _pos, sf::Vector2f _direction);
	void createPlayer(sf::Texture& _textPlayer, textureManager& _texManager);

	void deleteEntity(std::shared_ptr<Entity>& entity);

	std::vector<std::shared_ptr<Entity>> getAllPlayers() const;
	std::vector<std::shared_ptr<Entity>> getAllProjectiles() const;
	std::vector<std::shared_ptr<Entity>> getAllEnnemies() const;
	std::vector<std::shared_ptr<Entity>> getAllEntities() const;
};