#include "Projectiles.h"

Projectiles::Projectiles(const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _direction, char _owner) : Entity('B', _texture, _pos, sf::Vector2f(1.f, 1.f)), direction(_direction), owner(_owner)
{
	projectileSpeed = 3500.f;
	if(_owner != 'P')
		sprite.setScale({ -sprite.getScale().x, -sprite.getScale().y });
};

void Projectiles::update(float dT)
{
	// augmenter le time avec le deltaTime ici (mettre dT en argument d'un update globale)
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
	sprite.setScale({ -sprite.getScale().x, -sprite.getScale().y});
	if (owner == 'E')
	{
		direction.y = 0;
	}
	// Si c'est un ennemi qui renvoit le projectile, le renvoyé tout droit et pas dans le meme angle que le joueur
}

void Projectiles::moveProjectile(float dt)
{
	collider.move({ direction.x * projectileSpeed * dt, direction.y * projectileSpeed * dt });
	sprite.setPosition(collider.getPosition());
}