#pragma once
#include "Outils.h"
class UIButton : public UIElements
{
public:
	UIButton(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color, const std::string&, const char& c);

	void draw(sf::RenderWindow& window)override;
	void updatePosition(sf::Vector2f camPos)override;

	char getIndex()override;

	void updateText(const std::string&)override;

	bool onClick(sf::RenderWindow& window);

private:

	const sf::Vector2f OFFSET;
	sf::RectangleShape shape;

	sf::Text text;
	sf::Font font;
	std::string str;

	const char index;
};

