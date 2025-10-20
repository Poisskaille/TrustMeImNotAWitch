#include "Player.h"

Player::Player()
{
	playerShape.setPosition(sf::Vector2(0.f, 600.f));
	playerShape.setSize(sf::Vector2(5.f, 5.f));
	speed = 100.f;
	deltaTime = 0.f;

	playerState = State::GROUNDED;
}

Player::~Player()
{
}

void Player::Update(float dT)
{
	deltaTime = dT;
	HandleInput();
	

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(playerShape);
}

void Player::HandleInput()
{
	playerShape.move(sf::Vector2(speed * deltaTime, 0.f));
}
