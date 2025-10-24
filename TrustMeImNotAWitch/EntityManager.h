#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "Ennemy.h"
#include "Projectiles.h"

class entityManager
{
private:
	entityManager() {}
	static entityManager* instance;

	std::vector<std::shared_ptr<Entity>> allEntities;

	std::vector<std::shared_ptr<Entity>> allPlayers;
	std::vector<std::shared_ptr<Entity>> allEnnemies;

	std::vector<std::shared_ptr<Entity>> allprojectiles;


public:
	static entityManager* getInstance();
	~entityManager();
	void createProjectiles(sf::Texture& _text, sf::Vector2f _pos, sf::Vector2f _direction);
	void createPlayer(sf::Texture& _textPlayer, textureManager& _texManager);

	void deleteEntity(std::shared_ptr<Entity>& entity);

	std::shared_ptr<Player> getPlayer() const;

	std::vector<std::shared_ptr<Entity>> getAllPlayers() const;
	std::vector<std::shared_ptr<Entity>> getAllProjectiles() const;
	std::vector<std::shared_ptr<Entity>> getAllEnnemies() const;

	//Tags: P = player, E = ennemy(Ennemy special tags: F = fourches, T = torches, P = Panneau, 3 = 3D), B = projectile(Projectile special tags: P = player, E = ennemy)
	std::vector<std::shared_ptr<Entity>> getAllEntities() const;
};

extern entityManager* managerEntity;