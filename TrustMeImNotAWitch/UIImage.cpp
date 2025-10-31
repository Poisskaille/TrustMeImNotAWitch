#include "UIImage.h"
UIImage::UIImage(const sf::Vector2f& offset, const sf::Vector2f& size, const std::string& str, const char& c, sf::Texture& _texture)
	: OFFSET(offset), text(font), str(str), index(c)
{
	if (!font.openFromFile("../assets/font/Enchanted Land.otf"))
		std::cout << "Error loading font" << '\n';
	shape.setSize(size);
	shape.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));

	text.setString(str);
	text.setCharacterSize(50);

	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin({ bounds.position.x + bounds.size.x / 2.f,
		bounds.position.y + bounds.size.y / 2.f });

	texture = _texture;
	shape.setTexture(&texture);
	shape.setPosition(offset);
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
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin({ bounds.position.x + bounds.size.x / 2.f,
		bounds.position.y + bounds.size.y / 2.f });
}