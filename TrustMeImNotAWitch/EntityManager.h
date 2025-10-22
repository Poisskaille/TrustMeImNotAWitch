#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "Projectiles.h"

class EntityManager
{
private:
	static EntityManager* instance;
	EntityManager() {}

	std::vector<std::shared_ptr<Entity>> allEntities;

	std::vector<std::shared_ptr<Entity>> allPlayers;
	std::vector<std::shared_ptr<Entity>> allEnnemies;

	std::vector<std::shared_ptr<Entity>> allprojectiles;


public:
	static EntityManager* getInstance();
	~EntityManager();
	void createProjectiles(sf::Vector2f _pos, sf::Texture& _text, std::string _direction);
	void createPlayer(sf::Vector2f _pos, sf::Texture& _textPlayer, sf::Texture& _textPlayerJumpEffect, sf::Texture& _textPlayerLandEffect, float _speed, int _hp);

	void deleteEntity(std::shared_ptr<Entity>& entity);

	std::vector<std::shared_ptr<Entity>> getAllPlayers() const;
	std::vector<std::shared_ptr<Entity>> getAllProjectiles() const;
	std::vector<std::shared_ptr<Entity>> getAllEnnemies() const;
	std::vector<std::shared_ptr<Entity>> getAllEntities() const;
};

extern EntityManager* entityManager;