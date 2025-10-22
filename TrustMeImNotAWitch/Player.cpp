#include "Player.h"

Player::Player(const sf::Texture& texture, textureManager& texManager)
	: playerSprite(texture), texManager(texManager)
{

	playerSprite.setOrigin(sf::Vector2f(16,24));
	playerSprite.setScale(sf::Vector2f(3.0f, 3.0f));
	playerCollider.setPosition(sf::Vector2(0.f, 400.f));
	playerCollider.setSize(sf::Vector2(64.f, 64.f));
	playerCollider.setOrigin(sf::Vector2f(32.f,32.f));
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

void Player::Update(float dT, const std::vector<Tile>& tile)
{
	deltaTime = dT;
	HandleInput();
	Collision(tile);

	//Change le state pour pouvoir changer les animations plus tard
	playerAnimation newAnim = playerAnimation::Idle;

	if (playerState == State::GROUNDED) {
		if (isWalking)
			newAnim = playerAnimation::Walk;
		else
			newAnim = playerAnimation::Run;
	}
	else if (playerState == State::JUMPING) {
		newAnim = playerAnimation::Jump;
	}

	// Change animation only if itÅfs different
	if (newAnim != currentAnimation) {
		currentAnimation = newAnim;
		texManager.setplayerAnimation(currentAnimation, playerSprite);
	}

	// Always update the current animation
	texManager.update(deltaTime, playerSprite);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
		speed = walkingSpeed;
		isWalking = true;
	}
	else {
		speed = runningSpeed;
		isWalking = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState != State::GROUNDED)
		velocity.y = 1000.f;

	//Debug
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace)) {
		switch (playerState) {
			case State::GROUNDED:
				std::cout << "GROUNDED" << std::endl;
				break;
			case State::JUMPING:
				std::cout << "JUMPING" << std::endl;
				break;
		}
	}

	playerSprite.setPosition(playerCollider.getPosition());
}

void Player::Jump()
{
	velocity.y = jumpForce;
	playerState = State::JUMPING;
}

void Player::Collision(const std::vector<Tile>& tiles)
{
	sf::FloatRect playerBounds = playerCollider.getGlobalBounds();

	for (auto& tile : tiles)
	{
		sf::FloatRect tileBounds = tile.sprite.getGlobalBounds();

		if (playerBounds.findIntersection(tileBounds))
		{
			switch (tile.type) {
			case '#':
				playerCollider.setPosition(sf::Vector2f(playerCollider.getPosition().x, playerCollider.getPosition().y - 0.0001f));
				velocity.y = 0.f;
				playerState = State::GROUNDED;
				break;
			default:
				break;

			}
		}
		
	}
}