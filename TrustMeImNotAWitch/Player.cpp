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

	speed = defaultSpeed;
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




	if (!isSliding) {
		slideRefresh += dT; // time since last slide
	}

	//SLIDE FEATURE
	if (playerState == State::SLIDING) {
		playerCollider.move(sf::Vector2f(speed * 2.f * deltaTime, 0.f)); // push forward
		slideTimer += dT;
		playerSprite.setPosition(sf::Vector2f(playerCollider.getPosition().x, playerCollider.getPosition().y-12));
		playerSprite.setScale(sf::Vector2f(3.f, 2.3f));

		//SLIDE CANCELLING
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			Jump();
			isSliding = false;
			playerCollider.setSize(sf::Vector2f(64.f, 96.f));
			playerCollider.setOrigin(sf::Vector2f(32.f, 32.f));
			playerCollider.move(sf::Vector2f(0.0f, -26.f));
			playerSprite.setScale(sf::Vector2f(3.f, 3.f));
			slideRefresh = 0.f; // reset the cooldown timer
			return;
			speed = defaultSpeed;
			
		}

		// End slide after duration
		if (slideTimer >= slideDuration) {
			isSliding = false;
			playerState = State::GROUNDED;
			playerCollider.setSize(sf::Vector2f(64.f, 96.f));
			playerCollider.setOrigin(sf::Vector2f(32.f, 32.f));
			playerCollider.move(sf::Vector2f(0.0f, -26.f));
			playerSprite.setPosition(sf::Vector2f(playerCollider.getPosition().x, playerCollider.getPosition().y));
			playerSprite.setScale(sf::Vector2f(3.f, 3.f));
			slideRefresh = 0.f; // reset the cooldown timer
			speed = defaultSpeed;
		}

		if (velocity.y > 300) {
			isSliding = false;
			playerCollider.setSize(sf::Vector2f(64.f, 96.f));
			playerCollider.setOrigin(sf::Vector2f(32.f, 32.f));
			playerCollider.move(sf::Vector2f(0.0f, -26.f));
			playerSprite.setPosition(sf::Vector2f(playerCollider.getPosition().x, playerCollider.getPosition().y));
			playerSprite.setScale(sf::Vector2f(3.f, 3.f));
			playerState = State::FALLING;
			slideRefresh = 0.f; // reset the cooldown timer
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
		else if (!againstWall)
			newAnim = playerAnimation::Run;
		else
			newAnim = playerAnimation::Idle;
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

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && playerState == State::GROUNDED && !isWalking) { Jump(); }
	if (!againstWall) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
			speed = walkingSpeed;
			isWalking = true;
		}
		else {
			speed = runningSpeed;
			isWalking = false;
		}
	}
	else {
		if (againstWall && isWalking) {
			isWalking = false;
		}
		speed = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState != State::GROUNDED && playerState == State::FALLING)
		velocity.y = 1000.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && playerState == State::GROUNDED && !isSliding && slideRefresh >= slideCooldown)
	{
		Slide(); // start the slide
		//playerCollider.move(sf::Vector2f(0.f, -0.5f));

	}


	//Debug
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace)) {
		//switch (playerState) {
		//	case State::GROUNDED:
		//		std::cout << "GROUNDED" << std::endl;
		//		break;
		//	case State::JUMPING:
		//		std::cout << "JUMPING" << std::endl;
		//		break;
		//	case State::SLIDING:
		//		std::cout << "SLIDING" << std::endl;
		//		break;
		//	case State::FALLING:
		//		std::cout << "JUMPING" << std::endl;
		//		break;
		//	default:
		//		std::cout << "tf is happening" << std::endl;
		//		break;
		//}
		std::cout << "velocity : " <<velocity.x << std::endl;
		std::cout << "speed : " << speed << std::endl;
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

	// Capture the collider’s bottom before resizing
	float bottomY = playerCollider.getGlobalBounds().position.y + playerCollider.getGlobalBounds().size.y;

	// Shrink collider
	playerCollider.setSize(sf::Vector2f(82.f, 48.f));
	playerCollider.setOrigin(sf::Vector2f(48.f, 12.f));

	// Adjust Y so bottom remains at the same place
	float newBottomY = playerCollider.getGlobalBounds().position.y + playerCollider.getGlobalBounds().size.y;
	float offset = bottomY - newBottomY;
	playerCollider.move(sf::Vector2f(0.f, offset));

	speed = boostSpeed;
}






//void Player::Collision(const std::vector<Tile>& tiles)
//{
//	sf::FloatRect playerBounds = playerCollider.getGlobalBounds();
//
//	for (auto& tile : tiles)
//	{
//		float overlapY = (playerCollider.getPosition().y + playerCollider.getSize().y) - tile.sprite.getPosition().y;
//
//		sf::FloatRect tileBounds = tile.sprite.getGlobalBounds();
//
//		if (playerBounds.findIntersection(tileBounds))
//		{
//			switch (tile.type) {
//			case '#':
//
//				if (velocity.y > 0 && overlapY > 0) {
//					playerCollider.setPosition(sf::Vector2f(playerCollider.getPosition().x, playerCollider.getPosition().y - 0.0001f));
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

	againstWall = false;
	for (auto& tile : tiles)
	{
		sf::FloatRect playerBounds = playerCollider.getGlobalBounds();
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
					float playerBottom = playerBounds.position.y + playerBounds.size.y;
					float tileTop = tileBounds.position.y;

					// Only block horizontally if the player is NOT standing above the tile
					if (playerBottom > tileTop + 5.f) // small margin to avoid false positives
					{
						// Horizontal collision: block movement in X
						if (playerCollider.getPosition().x < tileBounds.position.x)
							playerCollider.move(sf::Vector2f(-intersection.size.x + 2.f, 0.f)); // hit tile from left
						else
							playerCollider.move(sf::Vector2f(intersection.size.x - 2.f, 0.f));  // hit tile from right

						againstWall = true;
						speed = 0;
					}
				}

				else
				{
					// Vertical collision: block movement in Y
					if (playerCollider.getPosition().y < tileBounds.position.y)
					{
						// Land on top of tile
						playerCollider.move(sf::Vector2f(0.f, -intersection.size.y));
						velocity.y = 0.f;
						if (!isSliding)
							playerState = State::GROUNDED;
					}
					else
					{
						// Hit the bottom of tile (e.g., head bump)
						playerCollider.move(sf::Vector2f(0.f, intersection.size.y));
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



