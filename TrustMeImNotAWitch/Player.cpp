#include "Player.h"

Player::Player(const sf::Texture& _texture) : Entity('P', _texture, sf::Vector2f(0.f, 350.f), sf::Vector2f(3.f, 3.f)), cam(collider.getPosition())
{
	//sprite.setOrigin(sf::Vector2f(16,11));
	//collider.setOrigin(sprite.getOrigin());
	collider.setFillColor(sf::Color::Blue);
	//sprite.setPosition(sf::Vector2(0.f,400.f));

	speed = 200.f;
	jumpForce = -600.f;
	gravity = 1500.f;
	velocity = sf::Vector2f(0.f,0.f);

	speed = defaultSpeed;
	jumpForce = -600.f;
	gravity = 1500.f;
	velocity = sf::Vector2f(0.f, 0.f);

	playerState = State::GROUNDED;

	//

	ground.setPosition(sf::Vector2(0.f, 600.f));
	ground.setSize(sf::Vector2(1920.f, 100.f));
}

void Player::Update(const std::vector<Tile>& tile)
{
	deltaTime = _updateClock.restart();
	HandleInput();
	Collision(tile);
	cam.Update(collider.getPosition());

	//SLIDE FEATURE
	if (playerState == State::SLIDING) {
		collider.move(sf::Vector2f(speed * 2.f * deltaTime.asSeconds(), 0.f)); // push forward
		slideTimer += deltaTime.asSeconds();
		sprite.setPosition(sf::Vector2f(collider.getPosition().x, collider.getPosition().y - 32));

		//SLIDE CANCELLING
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			Jump();
			isSliding = false;
			collider.setSize(sf::Vector2f(64.f, 96.f)); // revert collider
			return;
			speed = defaultSpeed;
		}

		// End slide after duration
		if (slideTimer >= slideDuration) {
			isSliding = false;
			playerState = State::GROUNDED;
			collider.setSize(sf::Vector2f(64.f, 96.f));
			collider.setOrigin(sf::Vector2f(32.f, 32.f));
			collider.move(sf::Vector2f(0.0f, -34.f));
			sprite.setPosition(sf::Vector2f(collider.getPosition().x, collider.getPosition().y));
			speed = defaultSpeed;
		}

		if (velocity.y > 350) {
			isSliding = false;
			collider.setSize(sf::Vector2f(64.f, 96.f)); // revert collider
			playerState = State::FALLING;
			speed = defaultSpeed;
		}
	}


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
	managerText->update(deltaTime.asSeconds(), sprite);
#pragma endregion
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(ground);
	window.draw(collider);
	window.draw(sprite);
	window.setView(cam.getCam());

	cam.DrawUI(window);
}

void Player::HandleInput()
{
	collider.move(sf::Vector2(speed * deltaTime.asSeconds(), velocity.y * deltaTime.asSeconds()));
	velocity.y += gravity * deltaTime.asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && playerState == State::GROUNDED && !isWalking) { Jump(); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
		speed = walkingSpeed;
		isWalking = true;
	}
	else {
		speed = runningSpeed;
		isWalking = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState != State::GROUNDED && playerState == State::FALLING)
		velocity.y = 1000.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState == State::GROUNDED && !isSliding)
	{
		Slide(); // start the slide
		//collider.move(sf::Vector2f(0.f, -0.5f));

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

	sprite.setPosition(collider.getPosition());
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

	// Capture the collider’s bottom before resizing
	float bottomY = collider.getGlobalBounds().position.y + collider.getGlobalBounds().size.y;

	// Shrink collider
	collider.setSize(sf::Vector2f(64.f, 64.f));
	collider.setOrigin(sf::Vector2f(32.f, 32.f));

	// Adjust Y so bottom remains at the same place
	float newBottomY = collider.getGlobalBounds().position.y + collider.getGlobalBounds().size.y;
	float offset = bottomY - newBottomY;
	collider.move(sf::Vector2f(0.f, offset));

	speed = boostSpeed;
}

//void Player::Collision(const std::vector<Tile>& tiles)
//{
//	sf::FloatRect playerBounds = collider.getGlobalBounds();
//
//	for (auto& tile : tiles)
//	{
//		float overlapY = (collider.getPosition().y + collider.getSize().y) - tile.sprite.getPosition().y;
//
//		sf::FloatRect tileBounds = tile.sprite.getGlobalBounds();
//
//		if (playerBounds.findIntersection(tileBounds))
//		{
//			switch (tile.type) {
//			case '#':
//
//				if (velocity.y > 0 && overlapY > 0) {
//					collider.setPosition(sf::Vector2f(collider.getPosition().x, collider.getPosition().y - 0.0001f));
//					velocity.y = 0.f;
//
//					if (!isSliding) {
//						playerState = State::GROUNDED;
//					}
//				}
//				break;
//			default:
//				break;
//
//			}
//		}
//		
//	}
//}

void Player::Collision(const std::vector<Tile>& tiles)
{
	for (auto& tile : tiles)
	{
		sf::FloatRect playerBounds = collider.getGlobalBounds();
		sf::FloatRect tileBounds = tile.sprite.getGlobalBounds();

		auto intersectionOpt = playerBounds.findIntersection(tileBounds);

		if (intersectionOpt.has_value())
		{
			sf::FloatRect intersection = intersectionOpt.value();

			switch (tile.type)
			{
			case '#':
			{
				// Determine the axis with the smallest overlap
				if (intersection.size.x < intersection.size.y)
				{
					// Horizontal collision: block movement in X
					if (collider.getPosition().x < tileBounds.position.x)
						collider.move(sf::Vector2f(-intersection.size.x, 0.f)); // hit tile from left
					//else
					//	collider.move(intersection.width, 0.f); // hit tile from right

					// Stop horizontal velocity
					velocity.x = 0.f;
				}
				else
				{
					// Vertical collision: block movement in Y
					if (collider.getPosition().y < tileBounds.position.y)
					{
						// Land on top of tile
						collider.move(sf::Vector2f(0.f, -intersection.size.y));
						velocity.y = 0.f;
						if (!isSliding)
							playerState = State::GROUNDED;
					}
					else
					{
						// Hit the bottom of tile (e.g., head bump)
						collider.move(sf::Vector2f(0.f, intersection.size.y));
						velocity.y = 0.f;
					}
				}
				break;
			}
			default:
				break;
			}
		}
	}
}