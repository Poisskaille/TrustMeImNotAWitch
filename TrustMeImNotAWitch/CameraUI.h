#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "memory.h"
#include <vector>
#include "UIImage.h"

class CameraUI
{
public:

	CameraUI(sf::Vector2f pos);

	void Update(sf::Vector2f playerPos);
	void Draw(sf::RenderWindow& window);

	void UpdateUI();

	sf::View getCam();

private:

	const float Y_OFFSET;

	sf::View cam;

	std::vector<std::shared_ptr<UIElements>> uiList;
};

