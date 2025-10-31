#include "fork.h"

fork::fork(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size) : Ennemy('F', _texture, _pos, _size) {
	sprite.setScale({ 3.f,3.f });

}

void fork::update(float dT)
{
    managerText->updateEnemy(EnemyType::Fork, currentAnim, dT, sprite);
}
