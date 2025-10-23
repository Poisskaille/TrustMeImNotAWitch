#include "Collisions.h"

Collisions* Collisions::instance = nullptr;

Collisions* Collisions::getInstance()
{
	if (instance == nullptr) { instance = new Collisions(); }
	return instance;
}

void Collisions::setGameRunning(bool _isGameRunning) { isGameRunning = _isGameRunning; };

void Collisions::setPaused(bool _isPaused) { isPaused = _isPaused; };

void Collisions::checkCollisions()
{
	std::cout << "Collision check" << std::endl;
}