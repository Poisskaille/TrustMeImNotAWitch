#pragma once
#include "EntityManager.h"
class Barricade : public Ennemy
{
public:

	Barricade(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);

	void update(float dT)override{}

private:
};

