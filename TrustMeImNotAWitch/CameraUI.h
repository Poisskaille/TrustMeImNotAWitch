#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "UIManagers.h"

class CameraUI
{
public:

	CameraUI(sf::Vector2f pos);

	void Update(sf::Vector2f playerPos);
	void DrawUI(sf::RenderWindow& window);

	void InitUI();

	sf::View getCam();

private:

	const float Y_OFFSET;

	sf::View cam;
};

