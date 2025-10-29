#pragma once
#include "Ennemy.h"

class torches : public Ennemy
{
private:

public:
	torches(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
};

