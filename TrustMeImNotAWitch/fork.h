#pragma once
#include "Ennemy.h"

class fork : public Ennemy
{
private:

public:
	fork(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
	void update()override;
};