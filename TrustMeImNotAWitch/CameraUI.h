#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "memory.h"
#include "UI.h"
#include <vector>

class CameraUI
{
public:

	CameraUI(sf::Vector2f pos);

	void Update(sf::Vector2f playerPos);
	void Draw(sf::RenderWindow& window);

	void UpdateUI(sf::Vector2f);

	sf::View getCam();

private:

	const float Y_OFFSET;

	sf::View cam;

	std::vector<std::shared_ptr<UI>> uiList;
};

