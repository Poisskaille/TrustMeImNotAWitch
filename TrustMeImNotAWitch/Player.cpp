#include "Player.h"

Player::Player(const sf::Texture& _texture, textureManager& _texManager) : texManager(_texManager), Entity('P', _texture, sf::Vector2f(0.f, 400.f), sf::Vector2f(32.f, 32.f))
{

	sprite.setOrigin(sf::Vector2f(16,16));
	collider.setOrigin(sprite.getOrigin());
	collider.setFillColor(sf::Color::Red);

	sprite.setPosition(sf::Vector2(0.f,400.f));

	speed = 200.f;
	deltaTime = 0.f;
	jumpForce = -600.f;
	gravity = 1500.f;
	velocity = sf::Vector2f(0.f,0.f);

	playerState = State::GROUNDED;
}

Player::~Player()
{
}

//void Player::Update(float dT, Entity* other)
//{
//	deltaTime = dT;
//	HandleInput();
//	Collision(other);
//}

void Player::HandleInput()
{
	collider.move(sf::Vector2(speed * deltaTime, velocity.y * deltaTime));
	velocity.y += gravity * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && playerState == State::GROUNDED) { Jump(); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		speed = 100.f;
	else
		speed = 200.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState != State::GROUNDED)
		velocity.y = 1000.f;

	sprite.setPosition(collider.getPosition());
}

void Player::Jump()
{
	velocity.y = jumpForce;
	playerState = State::JUMPING;
}


//void Player::Collision(Entity* other)
//{
//	if (isColliding(*other))
//	{
//		switch (other->tag)
//		{
//		default:
//			break;
//		}
//		collider.setPosition(sf::Vector2f(collider.getPosition().x, collider.getPosition().y - 0.0001f));
//		velocity.y = 0.f;
//		playerState = State::GROUNDED;
//	}
//}