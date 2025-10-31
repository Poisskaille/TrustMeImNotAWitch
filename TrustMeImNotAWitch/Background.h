#pragma once
#include <SFML/Graphics.hpp>
#include "collisionsManager.h"

class Background
{
private:
	std::vector<sf::RectangleShape> background;

	sf::RectangleShape sky1;
	sf::RectangleShape sky2;

	sf::RectangleShape firstTrees1;
	sf::RectangleShape firstTrees2;

	sf::RectangleShape secondTrees1;
	sf::RectangleShape secondTrees2;

	sf::RectangleShape leaves1;
	sf::RectangleShape leaves2;

	sf::RectangleShape floor1;
	sf::RectangleShape floor2;

	sf::RectangleShape dirtFloor1;
	sf::RectangleShape dirtFloor2;

	sf::Vector2f size = {1500, 1000.f};

	sf::Clock _paralaxClock;

	float yOffset = -315.f;
public:
	Background();

	void init();

	void updateParalax();
	void draw(sf::RenderWindow& window);
};

