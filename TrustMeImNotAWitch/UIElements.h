#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <string>

class UIElements
{
public:
	UIElements();

	virtual ~UIElements() = default;

	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void updatePosition(sf::Vector2f camPos) = 0;

	virtual char getIndex() = 0;

	virtual void updateText(const std::string&) = 0;

protected:
	sf::Vector2f position;
	char index;
};

