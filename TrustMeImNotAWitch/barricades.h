#pragma once
#include "Entity.h"
#include "EntityManager.h"
class Barricades : public Ennemy
{
public:

	Barricades(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);

	void update(float dT)override{}

private:
};

