#pragma once
#include "Ennemy.h"
#include "textureManager.h"
#include "EntityManager.h"

class sign : public Ennemy
{
private:
	animationType currentType = animationType::Idle;
	float animTimer = 0.f; // tracks animation time


public:
	sign(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
	void update(float dT) override;
	void animTypeSetter(animationType type);
	animationType animTypeGetter();
};

