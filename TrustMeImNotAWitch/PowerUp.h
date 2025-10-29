#pragma once
#include "Entity.h"
#include "Score.h"

enum class PowerType{GOLD, SHIELD, SCORE_BOOST};

class PowerUp : public Entity
{
public:

	PowerUp(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size, PowerType);
	~PowerUp();
	void update(float dT)override;

private:

	PowerType type;
};

