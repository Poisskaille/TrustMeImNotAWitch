#include "UIImage.h"

UIImage::UIImage(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color)
{
	shape.setPosition(pos);
	shape.setSize(size);
	shape.setFillColor(color);
}

void UIImage::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
	//window.draw(text);
}

void UIImage::UpdatePosition(sf::Vector2f camPos)
{
	shape.setPosition(camPos);
}
