#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "fourches.h"
#include "torches.h"
#include "panneau.h"
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
	void createEnnemies(char _tagEnnemie, sf::Texture& _text, sf::Vector2f _pos, sf::Vector2f _size);
	void createPlayer(sf::Texture& _textPlayer);

	void deleteEntity(std::shared_ptr<Entity>& entity);

	std::shared_ptr<Player> getPlayer() const;

	std::vector<std::shared_ptr<Entity>> getAllPlayers() const;
	std::vector<std::shared_ptr<Entity>> getAllProjectiles() const;
	std::vector<std::shared_ptr<Entity>> getAllEnnemies() const;

	//Tags: P = player, E = ennemy(Ennemy special tags: F = fourches, T = torches, B = Panneau, 3 = 3D), p = projectile(Projectile special tags: U = player, E = ennemy)
	std::vector<std::shared_ptr<Entity>> getAllEntities() const;
};

extern entityManager* managerEntity;