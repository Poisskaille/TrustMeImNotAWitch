#include "UI.h"

UI::UI(sf::RectangleShape rs, std::string str, sf::Vector2f pos) :shape(rs), text(str), position(pos)
{
}

void UI::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void UI::UpdatePosition(sf::Vector2f vec2)
{
	shape.setPosition(vec2);
}
