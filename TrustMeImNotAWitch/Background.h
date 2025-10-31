#pragma once
#include <SFML/Graphics.hpp>
#include "collisionsManager.h"

class Background
{
private:
	sf::RectangleShape background1;
	sf::RectangleShape background2;

	sf::Texture texture;

	sf::Vector2f size = { 1920.f, 1080.f };
public:
	Background();

	void init(sf::Texture & _texture);

	void updateParalax();
	void draw(sf::RenderWindow& window);
};

