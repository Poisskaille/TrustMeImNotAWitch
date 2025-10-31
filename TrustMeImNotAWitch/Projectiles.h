#pragma once
#include "Entity.h"
#include "collisionsManager.h"

class Projectiles : public Entity
{
private:
	sf::Vector2f direction;
	char owner;
	float projectileSpeed;

public:
	Projectiles(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _direction, char _owner);
	~Projectiles() override {};

	void update(float dT)override;
	void switchOwner();
	void changeDirection();
	void moveProjectile(float dt);

	char &getOwner() { return owner; }
};