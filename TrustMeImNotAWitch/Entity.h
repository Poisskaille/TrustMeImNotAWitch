#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
protected:
	sf::Sprite sprite;
	sf::RectangleShape collider;

public:
	const char tag;
	Entity(const char& tag, const sf::Texture& texture, sf::Vector2f& _pos, sf::Vector2f& _size);

	virtual void Update(float dT);
	void Draw(sf::RenderWindow& window);
	bool isColliding(Entity& other);
};