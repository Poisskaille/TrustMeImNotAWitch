#include "sign.h"

sign::sign(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size) : Ennemy('B', _texture, _pos, _size) {
	sprite.setScale({ 3.f,3.f });
}

void sign::update(float dT)
{
	managerText->updateEnemy(EnemyType::Sign, currentAnim, dT, sprite);
}