#pragma once
#include "Ennemy.h"

class torch : public Ennemy
{
private:

public:
	torch(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
	void update(float dT)override;
};

