#include "UIButton.h"

UIButton::UIButton(const sf::Vector2f& offset, const sf::Vector2f& size, const sf::Color& color) : OFFSET(offset), text(font)
{
	if (!font.openFromFile("assets/font/SpecialGothic-VariableFont_wdth,wght.ttf"))
		std::cout << "Error loading font" << '\n';
	shape.setSize(size);
	shape.setFillColor(color);
	shape.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
}

UIButton::UIButton(const sf::Vector2f& offset, const sf::Vector2f& size, const sf::Color& color, const std::string&) : OFFSET(offset), text(font), str(str)
{
	if (!font.openFromFile("assets/font/SpecialGothic-VariableFont_wdth,wght.ttf"))
		std::cout << "Error loading font" << '\n';
	shape.setSize(size);
	shape.setFillColor(color);
	shape.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));

	text.setString(str);
	text.setCharacterSize(50.f);

	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(sf::Vector2f(bounds.size.x / 2, bounds.size.y / 2 + 15));
}

void UIButton::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
	//window.draw(text);
	CheckMouse(window);
}

void UIButton::UpdatePosition(sf::Vector2f camPos)
{
	shape.setPosition(sf::Vector2f(camPos.x - OFFSET.x, camPos.y - OFFSET.y));
	//text.setPosition(shape.getPosition());
}

void UIButton::CheckMouse(sf::RenderWindow& window)
{
	sf::FloatRect shapeBounds = shape.getGlobalBounds();
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
	if (shapeBounds.contains(mousePosF) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		std::cout << "CLICK" << '\n';
}
