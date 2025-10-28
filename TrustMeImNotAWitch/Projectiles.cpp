#include "Projectiles.h"

Projectiles::Projectiles(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _direction, char _owner) : Entity('B', _texture, _pos, sf::Vector2f(32.f, 32.f)), direction(_direction), owner(_owner)
{
	_time = 0.f;
	projectileSpeed = 10.f;
};

void Projectiles::update()
{
	// augmenter le time avec le deltaTime ici (mettre dT en argument d'un update globale)
	moveProjectile();
}

// L'owner doit seulement etre P pour player ou E pour ennemi. Un projectile ne peut pas appartenir a une tile :)
void Projectiles::switchOwner()
{
	owner = (owner == 'P') ? 'E' : 'P';
	_time = 0.f;
	changeDirection();
}

void Projectiles::changeDirection()
{
	direction = -direction;
	if (owner == 'E')
		direction.y = 0;
	// Si c'est un ennemi qui renvoit le projectile, le renvoyé tout droit et pas dans le meme angle que le joueur
}

void Projectiles::moveProjectile()
{
	collider.move(direction);
}

bool Projectiles::lifeSpan()
{
	return (_time > 3);
}
