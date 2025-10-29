#pragma once
#include "Ennemy.h"

class sign : public Ennemy
{
private:

public:
	sign(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);

	void update()override;
};

