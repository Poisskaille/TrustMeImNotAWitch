#include "Player.h"

Player::Player(const sf::Texture& texture, textureManager& texManager)
	: playerSprite(texture), texManager(texManager)
{

	playerSprite.setOrigin(sf::Vector2f(16,16));
	playerCollider.setPosition(sf::Vector2(0.f, 400.f));
	playerCollider.setSize(sf::Vector2(32.f, 32.f));
	playerCollider.setOrigin(sf::Vector2f(16.f,16.f));
	playerCollider.setFillColor(sf::Color::Red);

	playerSprite.setPosition(sf::Vector2(0.f,400.f));

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
	window.draw(playerCollider);
	window.draw(playerSprite);
}

void Player::HandleInput()
{
	playerCollider.move(sf::Vector2(speed * deltaTime, velocity.y * deltaTime));
	velocity.y += gravity * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && playerState == State::GROUNDED) { Jump(); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		speed = 100.f;
	else
		speed = 200.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState != State::GROUNDED)
		velocity.y = 1000.f;

	playerSprite.setPosition(playerCollider.getPosition());
}

void Player::Jump()
{
	velocity.y = jumpForce;
	playerState = State::JUMPING;
}

void Player::Collision()
{
	if (playerCollider.getGlobalBounds().findIntersection(ground.getGlobalBounds()))
	{

		playerCollider.setPosition(sf::Vector2f(playerCollider.getPosition().x, playerCollider.getPosition().y - 0.0001f));
		velocity.y = 0.f;
		playerState = State::GROUNDED;
	}
}
