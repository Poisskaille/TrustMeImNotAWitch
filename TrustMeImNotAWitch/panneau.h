#pragma once
#include "Ennemy.h"

class panneau : public Ennemy
{
private:

public:
	panneau(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);

	void update()override;
};

