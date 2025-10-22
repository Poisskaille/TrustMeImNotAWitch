#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <string>

class UIElements
{
public:
	UIElements();

	virtual ~UIElements() = default;

	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void UpdatePosition(sf::Vector2f camPos) = 0;

protected:
	sf::Vector2f position;
};

