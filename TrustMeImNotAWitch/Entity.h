#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
private:
	//c pour moi ca				ok personne mysterieuse                   sympa ici
	sf::Vector2f ColliderSize = { 48.f,80.f };


protected:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::RectangleShape collider;

public:
	const char tag;
	Entity(const char& _tag, const sf::Texture& _texture, sf::Vector2f _pos, sf::Vector2f _size);
	virtual ~Entity() = default;

	//virtual void Update(bool colliding, Entity& other);
	virtual void update(float dT) =0;
	void Draw(sf::RenderWindow& window);
	bool isColliding(Entity* other);
	const sf::Vector2f& getPos() { return collider.getPosition(); };
};