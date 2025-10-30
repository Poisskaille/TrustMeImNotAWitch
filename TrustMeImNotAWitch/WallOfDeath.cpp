#include "WallOfDeath.h"

WallOfDeath::WallOfDeath(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size): Ennemy('W', _texture, _pos, _size)
{
	wallSpeed = 200.f;
}

void WallOfDeath::update(float dT)
{
	move(dT);
}

void WallOfDeath::move(float dT)
{
	collider.move({wallSpeed * dT,0});
	collider.setPosition({collider.getPosition().x, managerEntity->getPlayer()->getPos().y});

	if (managerEntity->getPlayer()->getPos().x - collider.getPosition().x > 500.f)
		wallSpeed += wallSpeed * dT;
	else
		wallSpeed = 200.f;
}
