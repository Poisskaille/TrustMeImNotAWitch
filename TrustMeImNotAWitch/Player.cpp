#include "Player.h"

Player::Player(const sf::Texture& texture, textureManager& texManager)
	: player(texture), texManager(texManager)
{
	player.setPosition(sf::Vector2f(0.0f, 600.0f));
	player.setScale(sf::Vector2f(2.f, 2.f));
	speed = 100.f;
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
	window.draw(player);
}

void Player::HandleInput()
{
	player.move(sf::Vector2(speed * deltaTime, velocity.y * deltaTime));
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
	if (player.getGlobalBounds().findIntersection(ground.getGlobalBounds()))
	{

		player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y - 0.0001f));
		velocity.y = 0.f;
		playerState = State::GROUNDED;
	}
}
