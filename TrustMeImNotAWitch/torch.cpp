#include "torch.h"

torch::torch(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size) : Ennemy('T', _texture, _pos, _size) 
{
	sprite.setScale({ 3.f,3.f });
}

void torch::update(float dT)
{
	if (shootingClock.getElapsedTime().asMilliseconds() > coolDown)
	{
		shootingClock.restart();
		managerEntity->createProjectiles({collider.getPosition().x - 50.f, collider.getPosition().y}, { -1.f, 0.f }, 'E');
	}

	managerText->updateEnemy(EnemyType::Torch, currentType, dT, sprite);
}

void torch::animTypeSetter(animationType type) {
	currentType = type;
}