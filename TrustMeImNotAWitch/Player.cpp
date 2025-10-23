#include "Player.h"
#include "UIElements.h"

Player::Player(const sf::Texture& texture, textureManager& texManager)
	: playerSprite(texture), texManager(texManager), cam(playerCollider.getPosition())
{

	playerSprite.setOrigin(sf::Vector2f(16,11));
	playerSprite.setScale(sf::Vector2f(3.0f, 3.0f));
	playerCollider.setPosition(sf::Vector2(0.f, 350.0f));
	playerCollider.setSize(sf::Vector2(64.f, 96.f));
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
	cam.Update(playerCollider.getPosition());

	//SLIDE FEATURE
	if (playerState == State::SLIDING) {
		playerCollider.move(sf::Vector2f(speed * 2.f * deltaTime, 0.f)); // push forward
		slideTimer += dT;

		//SLIDE CANCELLING
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			Jump();
			isSliding = false;
			playerCollider.setSize(sf::Vector2f(64.f, 96.f)); // revert collider
			return;
		}

		// End slide after duration
		if (slideTimer >= slideDuration) {
			isSliding = false;
			playerState = State::GROUNDED;
			playerCollider.setSize(sf::Vector2f(64.f, 96.f));
			playerCollider.setOrigin(sf::Vector2f(32.f, 32.f));
		}
	}


	//ANIMATIONS & CHECK STATES
#pragma region ANIMATION_PLAYER_STATE
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
	if (velocity.y > 350) {
		playerState = State::FALLING;
			newAnim = playerAnimation::Fall;
	}
	else if (playerState == State::SLIDING) {
		newAnim = playerAnimation::Slide;
	}

	// Change animation only if it�fs different
	if (newAnim != currentAnimation) {
		currentAnimation = newAnim;
		texManager.setplayerAnimation(currentAnimation, playerSprite);
	}

	// Always update the current animation
	texManager.update(deltaTime, playerSprite);
#pragma endregion
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(ground);
	window.draw(playerCollider);
	window.draw(playerSprite);
	window.setView(cam.getCam());

	cam.DrawUI(window);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState == State::GROUNDED && !isSliding)
	{
		Slide(); // start the slide
	}


	//Debug
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace)) {
		switch (playerState) {
			case State::GROUNDED:
				std::cout << "GROUNDED" << std::endl;
				break;
			case State::JUMPING:
				std::cout << "JUMPING" << std::endl;
				break;
			case State::SLIDING:
				std::cout << "SLIDING" << std::endl;
				break;
			case State::FALLING:
				std::cout << "JUMPING" << std::endl;
				break;
			default:
				std::cout << "tf is happening" << std::endl;
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

void Player::Slide() {
	isSliding = true;
	slideTimer = 0.0f;
	playerState = State::SLIDING;

	// Shrink collider for slide posture
	playerCollider.setSize(sf::Vector2f(64.f, 64.f));
	playerCollider.setOrigin(sf::Vector2f(32.f, 32.f));
	velocity.x = speed * 1.2f;
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
				if (!isSliding) {
					playerState = State::GROUNDED;
				}
				break;
			default:
				break;

			}
		}
		
	}
}