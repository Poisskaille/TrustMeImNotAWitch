#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "fork.h"
#include "torch.h"
#include "sign.h"
#include "Projectiles.h"
#include "WallOfDeath.h"
#include "PowerUp.h"
#include "barricades.h"

class Player;
class Map;

class entityManager
{
private:
	entityManager() {}
	static entityManager* instance;

	std::vector<std::shared_ptr<Entity>> allEntities;

	std::vector<std::shared_ptr<Entity>> allPlayers;
	std::vector<std::shared_ptr<Entity>> allEnnemies;

	std::vector<std::shared_ptr<Entity>> allprojectiles;

	std::vector<std::shared_ptr<Entity>> allPowerUps;


public:
	static entityManager* getInstance();
	~entityManager();
	void createProjectiles(sf::Vector2f _pos, sf::Vector2f _direction,char);
	void createEnnemies(char _tagEnnemie, sf::Texture& _text, sf::Vector2f _pos, sf::Vector2f _size);
	void createPlayer(sf::Texture& _textPlayer);

	void createPowerUp(PowerType pT, sf::Texture& _text, sf::Vector2f _pos, sf::Vector2f _size);

	void deleteEntity(std::shared_ptr<Entity>& entity);

	std::shared_ptr<Player> getPlayer() const;

	std::vector<std::shared_ptr<Entity>> getAllPlayers() const;
	std::vector<std::shared_ptr<Entity>> getAllProjectiles() const;
	std::vector<std::shared_ptr<Entity>> getAllEnnemies() const;

	std::vector<std::shared_ptr<Entity>> getAllPowerUps()const;

	//Tags: P = player, E = ennemy(Ennemy special tags: F = fork, T = torch, P = Panneau, 3 = 3D), B = projectile(Projectile special tags: P = player, E = ennemy)
	std::vector<std::shared_ptr<Entity>> getAllEntities() const;
};

extern entityManager* managerEntity;