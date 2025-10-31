#include "Projectiles.h"

Projectiles::Projectiles(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _direction, char _owner) : Entity('B', _texture, _pos, sf::Vector2f(2.f, 2.f)), direction(_direction), owner(_owner)
{
	projectileSpeed = 3500.f;
};

void Projectiles::update(float dT)
{
	// augmenter le time avec le deltaTime ici (mettre dT en argument d'un update globale)
	moveProjectile(dT);
}

// L'owner doit seulement etre P pour player ou E pour ennemi. Un projectile ne peut pas appartenir a une tile :)
void Projectiles::switchOwner()
{
	owner = (owner == 'P') ? 'E' : 'P';
	changeDirection();
}

void Projectiles::changeDirection()
{
	direction = -direction;
	if (owner == 'E')
	{
		direction.y = 0;
	}
	// Si c'est un ennemi qui renvoit le projectile, le renvoyé tout droit et pas dans le meme angle que le joueur
}

void Projectiles::moveProjectile(float dt)
{
	collider.move({ direction.x * projectileSpeed * dt, direction.y * projectileSpeed * dt });
}