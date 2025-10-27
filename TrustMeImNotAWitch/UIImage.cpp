#include "UIImage.h"

UIImage::UIImage(const sf::Vector2f& offset, const sf::Vector2f& size, const sf::Color& color) : OFFSET(offset), text(font)
{
	if (!font.openFromFile("../assets/font/SpecialGothic-VariableFont_wdth,wght.ttf"))
		std::cout << "Error loading font" << '\n';
	shape.setSize(size);
	shape.setFillColor(color);
	shape.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
}

UIImage::UIImage(const sf::Vector2f& offset, const sf::Vector2f& size, const sf::Color& color, const std::string& str) : OFFSET(offset), text(font), str(str)
{
	if (!font.openFromFile("../assets/font/SpecialGothic-VariableFont_wdth,wght.ttf"))
		std::cout << "Error loading font" << '\n';
	shape.setSize(size);
	//shape.setFillColor(color);
	shape.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));

	text.setString(str);
	text.setCharacterSize(50.f);

	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(sf::Vector2f(bounds.size.x / 2, bounds.size.y / 2 + 15));

	// Temp

		// Temp
	if (!texture.loadFromFile("assets/Score/score_sign.png"))
		std::cout << "Erreur" << '\n';

	shape.setTexture(&texture);

}

void UIImage::draw(sf::RenderWindow& window)
{
	window.draw(shape);
	window.draw(text);
}

void UIImage::updatePosition(sf::Vector2f camPos)
{
	shape.setPosition(sf::Vector2f(camPos.x - OFFSET.x, camPos.y - OFFSET.y));
	text.setPosition(shape.getPosition());
}

char UIImage::getIndex()
{
	return index;
}

void UIImage::updateText(const std::string& newstr)
{
	text.setString(newstr);
}
