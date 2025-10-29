#include "Ennemy.h"

Ennemy::Ennemy(const char& _tagEnnemie, const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size) : tagEnnemie(_tagEnnemie), Entity('E', _texture, _pos, _size) {}

void Ennemy::update(float dT)
{
}

char& Ennemy::getTagEnnemie() { return tagEnnemie; }