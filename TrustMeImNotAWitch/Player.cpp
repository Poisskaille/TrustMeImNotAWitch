#include "Player.h"

Player::Player()
{
	playerShape.setPosition(sf::Vector2(0.f, 400.f));
	playerShape.setSize(sf::Vector2(15.f, 15.f));
	playerShape.setFillColor(sf::Color::Red);

	speed = 200.f;
	deltaTime = 0.f;
	jumpForce = -600.f;
	gravity = 1500.f;
	velocity = sf::Vector2f(0.f,0.f);

	playerState = State::GROUNDED;

	//

	ground.setPosition(sf::Vector2(0.f,600.f));
	ground.setSize(sf::Vector2(1920.f, 100.f));
}

Player::~Player()
{
}

void Player::Update(float dT)
{
	deltaTime = dT;
	HandleInput();
	Collision();
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(ground);
	window.draw(playerShape);
}

void Player::HandleInput()
{
	playerShape.move(sf::Vector2(speed * deltaTime, velocity.y * deltaTime));
	velocity.y += gravity * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && playerState == State::GROUNDED) { Jump(); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		speed = 100.f;
	else
		speed = 200.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState != State::GROUNDED)
		velocity.y = 1000.f;

	
}

void Player::Jump()
{
	velocity.y = jumpForce;
	playerState = State::JUMPING;
}

void Player::Collision()
{
	if (playerShape.getGlobalBounds().findIntersection(ground.getGlobalBounds()))
	{

		playerShape.setPosition(sf::Vector2f(playerShape.getPosition().x, playerShape.getPosition().y - 0.0001f));
		velocity.y = 0.f;
		playerState = State::GROUNDED;
	}
}
