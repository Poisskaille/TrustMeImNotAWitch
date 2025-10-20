#include "Player.h"

Player::Player(const sf::Texture& texture, textureManager& texManager)
	: player(texture), texManager(texManager)
{
	player.setPosition(sf::Vector2f(0.0f, 600.0f));
	player.setScale(sf::Vector2f(2.f, 2.f));
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
