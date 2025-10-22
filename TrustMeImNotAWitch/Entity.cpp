#include "Entity.h"


Entity::Entity(const char& _tag, const sf::Texture& texture, sf::Vector2f& _pos, sf::Vector2f& _size) : tag(_tag), sprite(texture)
{
	collider.setPosition(sf::Vector2f(_pos));
	collider.setSize(sf::Vector2f(_size));
}

void Entity::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

bool Entity::isColliding(Entity& other)
{
	return collider.getGlobalBounds().findIntersection(other.collider.getGlobalBounds()) ? true : false;
}