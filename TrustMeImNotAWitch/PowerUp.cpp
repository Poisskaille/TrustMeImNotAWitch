#include "PowerUp.h"

PowerUp::PowerUp(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, PowerType pT): Entity('P', _texture, _pos, _size), type(pT)
{
}

PowerUp::~PowerUp()
{
	switch(type)
	{
	case PowerType::GOLD:
		managerScore->addScore(100);
		break;
	case PowerType::SCORE_BOOST:
		managerScore->changeMultiplier(3);
		break;
	case PowerType::SHIELD:
		break;
	}
}

void PowerUp::update(float dT){}
