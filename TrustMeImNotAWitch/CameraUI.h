#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "UIManagers.h"

class CameraUI
{
public:

	CameraUI(sf::Vector2f pos);

	void update(sf::Vector2f playerPos);
	void drawUI(sf::RenderWindow& window);

	void initUI();

	sf::View getCam();

private:
	float defaultView = 1.5f;

	const float Y_OFFSET;

	sf::View cam;
};

