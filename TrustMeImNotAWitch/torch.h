#pragma once
#include "Ennemy.h"
#include "entityManager.h"

class torch : public Ennemy
{
private:
	sf::Clock shootingClock;
	int coolDown = 2000;

public:
	torch(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
	void update(float dT) override;
};

