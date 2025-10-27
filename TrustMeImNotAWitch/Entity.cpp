#include "Entity.h"

Entity::Entity(const char& _tag, const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size) : tag(_tag), sprite(_texture)
{
	sprite.setPosition(_pos);
	sprite.setScale(_size);
	collider.setPosition(_pos);
	collider.setSize(sf::Vector2f(32.f, 32.f));
}

void Entity::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

bool Entity::isColliding(Entity* other)
{
	return collider.getGlobalBounds().findIntersection(other->collider.getGlobalBounds()) ? true : false;
}