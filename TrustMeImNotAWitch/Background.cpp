#include "Background.h"

Background::Background() {}

void Background::init()
{
	sky1.setSize(size);
	sky2.setSize(size);
	sky1.setTexture(&managerText->getTexture("skyBackgroundText"));
	sky1.setPosition({0, yOffset});
	sky2.setTexture(&managerText->getTexture("skyBackgroundText"));
	sky2.setPosition({-sky2.getSize().x, yOffset});

	firstTrees1.setSize(size);
	firstTrees2.setSize(size);
	firstTrees1.setTexture(&managerText->getTexture("firsTrees"));
	firstTrees1.setPosition({0, yOffset});
	firstTrees2.setTexture(&managerText->getTexture("firsTrees"));
	firstTrees2.setPosition({-firstTrees2.getSize().x, yOffset});

	secondTrees1.setSize(size);
	secondTrees2.setSize(size);
	secondTrees1.setTexture(&managerText->getTexture("secondTrees"));
	secondTrees1.setPosition({0, yOffset});
	secondTrees2.setTexture(&managerText->getTexture("secondTrees"));
	secondTrees2.setPosition({-secondTrees2.getSize().x, yOffset});

	leaves1.setSize(size);
	leaves2.setSize(size);
	leaves1.setTexture(&managerText->getTexture("leaves"));
	leaves1.setPosition({0, yOffset});
	leaves2.setTexture(&managerText->getTexture("leaves"));
	leaves2.setPosition({-leaves2.getSize().x, yOffset});

	floor1.setSize(size);
	floor2.setSize(size);
	floor1.setTexture(&managerText->getTexture("floor"));
	floor1.setPosition({0, yOffset});
	floor2.setTexture(&managerText->getTexture("floor"));
	floor2.setPosition({-floor2.getSize().x, yOffset});

	dirtFloor1.setSize(size);
	dirtFloor2.setSize(size);
	dirtFloor1.setTexture(&managerText->getTexture("dirtBackground"));
	dirtFloor1.setPosition({0, yOffset});
	dirtFloor2.setTexture(&managerText->getTexture("dirtBackground"));
	dirtFloor2.setPosition({-dirtFloor2.getSize().x, yOffset});

	background.push_back(sky1);
	background.push_back(sky2);
	background.push_back(secondTrees1);
	background.push_back(secondTrees2);
	background.push_back(firstTrees1);
	background.push_back(firstTrees2);
	background.push_back(leaves1);
	background.push_back(leaves2);
	background.push_back(floor1);
	background.push_back(floor2);
	background.push_back(dirtFloor1);
	background.push_back(dirtFloor2);
}

void Background::updateParalax()
{
	sf::Vector2f _centerScreen = sf::Vector2f(managerEntity->getPlayer()->cam.getCam().getCenter().x - size.x / 2.f, 0.f);
	float _sizeScreen = 1500.f;

	if (_paralaxClock.getElapsedTime().asMilliseconds() > 20)
	{
		background[2].move({ 1.f, 0.f });
		background[3].move({ 1.f, 0.f });
		_paralaxClock.restart();
	}

	for (auto& bg : background)
	{
		if (bg.getPosition().x <= _centerScreen.x - _sizeScreen)
		{
			bg.setPosition({ bg.getPosition().x + bg.getSize().x * 2, bg.getPosition().y });
		}
	}
}

void Background::draw(sf::RenderWindow& window)
{
	for (auto& bg : background)
	{
		window.draw(bg);
	}
}
