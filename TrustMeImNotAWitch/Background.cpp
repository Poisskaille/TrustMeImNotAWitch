#include "Background.h"

Background::Background() {}

void Background::init(sf::Texture & _texture)
{
	background1.setSize(size);
	background2.setSize(size);
	background1.setTexture(&_texture);
	background2.setTexture(&_texture);
	background2.setPosition({ 0 - background2.getSize().x, 0});
}

void Background::updateParalax()
{
	sf::Vector2f _centerScreen = sf::Vector2f(managerEntity->getPlayer()->cam.getCam().getCenter().x - size.x / 2.f, 0.f);
	float _sizeScreen = 1920.f;

	if (background1.getPosition().x <= _centerScreen.x - _sizeScreen)
	{
		background1.setPosition({ background1.getPosition().x + background1.getSize().x * 2, 0});
	}
	if (background2.getPosition().x <= _centerScreen.x - _sizeScreen)
	{
		background2.setPosition({ background2.getPosition().x + background2.getSize().x * 2, 0});
	}
}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(background1);
	window.draw(background2);
}
