#pragma once
#include "EntityManager.h"
class WallOfDeath : public Ennemy
{
public:

	WallOfDeath(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
	void update(float dT)override;

	void move(float);

private:

	float wallSpeed;
};

