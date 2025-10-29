#pragma once
#include "Entity.h"

class Projectiles : public Entity
{
private:
	sf::Vector2f direction;
	char owner;
	float projectileSpeed;
	float _time;

public:
	Projectiles(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _direction, char _owner);
	~Projectiles() override {};

	void update()override;
	void switchOwner();
	void changeDirection();
	void moveProjectile();
	
	bool lifeSpan();
};