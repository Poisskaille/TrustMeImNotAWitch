#pragma once
#include "UIElements.h"
class UIButton : public UIElements
{
public:
	UIButton(const sf::Vector2f& pos, const sf::Vector2f& size,const std::string&, const char& c, sf::Texture& fT, sf::Texture& sT);

	void draw(sf::RenderWindow& window)override;
	void updatePosition(sf::Vector2f camPos)override;

	char getIndex()override;

	void updateText(const std::string&)override;

	bool onClick(sf::RenderWindow& window);

	void onHover(sf::RenderWindow& winwdow);

private:

	const sf::Vector2f OFFSET;
	sf::RectangleShape shape;

	sf::Text text;
	sf::Font font;
	std::string str;

	sf::Texture& normalTexture;
	sf::Texture& hoveredTexture;

	const char index;
};

