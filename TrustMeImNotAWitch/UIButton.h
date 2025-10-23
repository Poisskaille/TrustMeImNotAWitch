#pragma once
#include "UIElements.h"
class UIButton : public UIElements
{
public:
	UIButton(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color, const std::string&, const char& c);

	void Draw(sf::RenderWindow& window)override;
	void UpdatePosition(sf::Vector2f camPos)override;

	char getIndex()override;

	void UpdateText(const std::string&)override;

	void CheckMouse(sf::RenderWindow& window);

private:

	const sf::Vector2f OFFSET;
	sf::RectangleShape shape;


	sf::Text text;
	sf::Font font;
	std::string str;

	const char index;
};

