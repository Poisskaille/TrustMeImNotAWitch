#pragma once
#include "Outils.h"

class Projectiles : public Entity
{
private:

public:
	Projectiles(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _direction);
	~Projectiles() override {};
};