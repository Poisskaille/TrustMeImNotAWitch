#pragma once
#include "Ennemy.h"
#include "textureManager.h"

class sign : public Ennemy
{
private:
	SignAnim currentAnim = SignAnim::Idle;
public:
	sign(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
	void update(float dT) override;
};

