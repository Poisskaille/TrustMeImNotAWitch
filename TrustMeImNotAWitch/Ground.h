#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Ground : public Entity
{
private:

public:
	Ground(const sf::Texture& _texture);
};