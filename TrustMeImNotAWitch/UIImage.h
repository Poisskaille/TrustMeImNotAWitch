#pragma once
#include "UIElements.h"

class UIImage: public UIElements
{
public:
	UIImage(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color, const std::string&, const char&);

	void Draw(sf::RenderWindow& window)override;
	void UpdatePosition(sf::Vector2f camPos)override;

	char getIndex()override;

	virtual void UpdateText(const std::string&) override;

private:

	const sf::Vector2f OFFSET;
	sf::RectangleShape shape;


	sf::Text text;
	sf::Font font;
	std::string str;

	const char index;

};

