#pragma once
#include "Ennemy.h"
#include "entityManager.h"
#include "textureManager.h"

class torch : public Ennemy
{
private:
	animationType currentType = animationType::Idle;
	sf::Clock shootingClock;
	int coolDown = 2000;

public:
	torch(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
	void update(float dT) override;
	void animTypeSetter(animationType type);
};

