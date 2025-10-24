#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
protected:
	sf::Sprite sprite;
	sf::RectangleShape collider;

public:
	const char tag;
	Entity(const char& _tag, const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
	virtual ~Entity() = default;

	//virtual void Update(bool colliding, Entity& other);
	void Draw(sf::RenderWindow& window);
	bool isColliding(Entity* other);

};