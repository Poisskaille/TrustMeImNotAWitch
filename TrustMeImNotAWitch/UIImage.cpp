#include "UIImage.h"
UIImage::UIImage(const sf::Vector2f& offset, const sf::Vector2f& size, const sf::Color& color, const std::string& str, const char& c)
	: OFFSET(offset), text(font), str(str), index(c)
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

void UIImage::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
	window.draw(text);
}

void UIImage::UpdatePosition(sf::Vector2f camPos)
{
	shape.setPosition(sf::Vector2f(camPos.x - OFFSET.x, camPos.y - OFFSET.y));
	text.setPosition(shape.getPosition());
}

char UIImage::getIndex()
{
	return index;
}

void UIImage::UpdateText(const std::string& newstr)
{
	text.setString(newstr);
}
