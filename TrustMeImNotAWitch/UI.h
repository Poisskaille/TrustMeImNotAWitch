#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class UI
{
public:

	UI(sf::RectangleShape, std::string, sf::Vector2f);

	void Draw(sf::RenderWindow& window);
	void UpdatePosition(sf::Vector2f);


private:
	const sf::Vector2f position;
	std::string text;
	sf::RectangleShape shape;

};

