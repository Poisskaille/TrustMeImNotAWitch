#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
class CameraUI
{
public:

	CameraUI(sf::Vector2f pos);

	void Update(sf::Vector2f playerPos);

	sf::View getCam();

private:

	const float Y_OFFSET;
	sf::View cam;
};

