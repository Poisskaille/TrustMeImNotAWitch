#pragma once
#include "Entity.h"

class Ennemy : public Entity
{
private:
	char tagEnnemie;

public:
	Ennemy(const char& _tagEnnemie, const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
	~Ennemy() override {};

	char& getTagEnnemie();
};

