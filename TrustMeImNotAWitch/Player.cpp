#include "Player.h"

Player::Player(const sf::Texture& _texture) : Entity('P', _texture, sf::Vector2f(0.f, 350.f), sf::Vector2f(3.f, 3.f)), cam(collider.getPosition())
{
	sprite.setOrigin(sf::Vector2f(16, 11));
	collider.setOrigin(sprite.getOrigin());
	collider.setFillColor(sf::Color::Blue);
	sprite.setPosition(sf::Vector2(0.f, 400.f));

	speed = 200.f;
	gravity = 1500.f;
	velocity = sf::Vector2f(0.f, 0.f);

	jumpForce = -800.f;
	velocity = sf::Vector2f(0.f, 0.f);

	playerState = State::GROUNDED;
	deltaTime = 0.f;
	totalTime = 0.f;
	scoreTime = 0.f;

	topCollider.setSize({collider.getSize().x, 20});
	topCollider.setOrigin({collider.getSize().x / 2, collider.getSize().y / 2});

	rightCollider.setSize({20,collider.getSize().y});
	rightCollider.setOrigin({ collider.getSize().x / 2, collider.getSize().y / 2 });
}

void Player::update(float dT)
{
	deltaTime = dT;

	HandleInput();
	cam.update(collider.getPosition());
	managerMap->unloadMap(collider.getPosition());

	totalTime += deltaTime;
	scoreTime += deltaTime;

	if (scoreTime > 1.f)
	{
		scoreTime = 0.f;
		managerScore->addScore(10 + (speed / 10));
		if(totalTime > 5.f)
			addSpeed();
	}


	//std::cout << deltaTime.asSeconds() << '\n';


	if (!isSliding) {
		slideRefresh += deltaTime; // time since last slide
	}

	//SLIDE FEATURE
	if (playerState == State::SLIDING) {
		slideTimer += deltaTime;
		sprite.setPosition(sf::Vector2f(collider.getPosition().x + 16, collider.getPosition().y - 24));
		speed = boostSpeed;

		//SLIDE CANCELLING
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			Jump();
			isSliding = false;
			collider.setSize(defaultColliderSize); // revert collider
			return;
			speed = defaultSpeed;
		}

		// End slide after duration
		if (slideTimer >= slideDuration) {
			isSliding = false;
			playerState = State::GROUNDED;
			collider.setSize(defaultColliderSize);
			collider.move(sf::Vector2f(0.0f, -34.f));
			sprite.setPosition(sf::Vector2f(collider.getPosition().x, collider.getPosition().y));
			speed = defaultSpeed;
		}

		if (velocity.y > 350) {
			isSliding = false;
			collider.setSize(defaultColliderSize); // revert collider
			playerState = State::FALLING;
			speed = defaultSpeed;
		}
	}

	Collision();

	//ANIMATIONS & CHECK STATES
#pragma region ANIMATION_PLAYER_STATE
	playerAnimation newAnim = playerAnimation::Idle;

	// ✅ prioritize SLIDE above all else
	if (playerState == State::SLIDING) {
		newAnim = playerAnimation::Slide;
	}
	else if (playerState == State::JUMPING) {
		newAnim = playerAnimation::Jump;
	}
	if (velocity.y > 350 || playerState == State::FALLING) {
		playerState = State::FALLING;
		newAnim = playerAnimation::Fall;
	}
	else if (playerState == State::GROUNDED) {
		if (isWalking)
			newAnim = playerAnimation::Walk;
		//newAnim = playerAnimation::Idle;
		else
			newAnim = playerAnimation::Run;
	}


	// Change animation only if it�fs different
	if (newAnim != currentAnimation) {
		currentAnimation = newAnim;
		managerText->setplayerAnimation(currentAnimation, sprite);
	}

	// Always update the current animation
	managerText->updatePlayer(deltaTime, sprite);
#pragma endregion
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.setView(cam.getCam());
	cam.drawUI(window);
}

void Player::HandleInput()
{

	//std::cout << "velocity.x = " << velocity.x  << ", speed = " << speed << ", deltaTime.asSeconds() = " << deltaTime.asSeconds() << '\n';
	collider.move(sf::Vector2(velocity.x, velocity.y * deltaTime));
	velocity.x = speed * deltaTime;
	velocity.y += gravity * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && playerState == State::GROUNDED && !isWalking) { Jump(); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
		isWalking = true;
	}
	else {
		isWalking = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState != State::GROUNDED && playerState == State::FALLING)
		velocity.y = 1000.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState == State::GROUNDED && !isSliding && slideRefresh >= slideCooldown)
	{
		Slide(); // start the slide
		//collider.move(sf::Vector2f(0.f, -0.5f));

	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		shoot();

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

	sprite.setPosition(sf::Vector2f(collider.getPosition().x + 8, collider.getPosition().y + 8));
	topCollider.setPosition({ sprite.getPosition().x, sprite.getPosition().y + 20 });
	rightCollider.setPosition({ sprite.getPosition().x + 50, sprite.getPosition().y + 20 });
}

void Player::Jump()
{
	velocity.y = jumpForce;
	playerState = State::JUMPING;
}

void Player::Slide() {
	isSliding = true;
	slideTimer = 0.0f;
	slideRefresh = 0.0f;
	playerState = State::SLIDING;

	// Capture the collider’s bottom before resizing
	float bottomY = collider.getGlobalBounds().position.y + collider.getGlobalBounds().size.y;

	// Shrink collider
	collider.setSize(slideColliderSize);
	collider.setOrigin(sprite.getOrigin());

	//// Adjust Y so bottom remains at the same place
	float newBottomY = collider.getGlobalBounds().position.y + collider.getGlobalBounds().size.y;
	float offset = bottomY - newBottomY;
	collider.move(sf::Vector2f(0.f, offset));

	speed = boostSpeed;
}

void Player::Collision() {

	if (managerMap->checkCollision(collider.getGlobalBounds()))
	{
		collider.setPosition({ collider.getPosition().x, collider.getPosition().y - 0.0001f });
		velocity.y = 0;
		if (playerState != State::SLIDING)
			playerState = State::GROUNDED;
	}
	if (managerMap->checkCollision(rightCollider.getGlobalBounds()))
	{
		collider.setPosition({ collider.getPosition().x + 0.0001f, collider.getPosition().y });
		velocity.x = 0;
	}
	if (managerMap->checkCollision(topCollider.getGlobalBounds()))
	{
		collider.setPosition({ collider.getPosition().x, collider.getPosition().y + 0.0001f });
		velocity.y = 0;
	}
}

void Player::shoot()
{
	sf::Vector2f mousePositionFloat(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
	sf::Vector2f direction = mousePositionFloat - sf::Vector2f(collider.getPosition().x - cam.getCam().getCenter().x, collider.getPosition().y);
	direction = direction.normalized();

	//Creer le projectile ici (probleme peut pas inclure le manager d'entity ici (inclusion circulaire))
	if (_shootCooldown.getElapsedTime().asMilliseconds() > _coolDown)
	{
		managerEntity->createProjectiles({ collider.getPosition().x + 100, collider.getPosition().y }, direction, 'P');
	}
}

void Player::addSpeed()
{
	speed = defaultSpeed + (rand() % 10) + 5;
	walkingSpeed = speed;
	defaultSpeed = speed;

	int ispeed = speed;

	UIManagers::getInstance().getCamUI('v')->updateText(std::to_string(ispeed));
	totalTime = 0.f;
}
