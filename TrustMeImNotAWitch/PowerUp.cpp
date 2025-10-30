#include "PowerUp.h"

PowerUp::PowerUp(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, PowerType pT): Entity('U', _texture, _pos, _size), type(pT)
{
}

PowerUp::~PowerUp()
{
}

void PowerUp::update(float dT){}

PowerType PowerUp::getType()
{
	return type;
}
