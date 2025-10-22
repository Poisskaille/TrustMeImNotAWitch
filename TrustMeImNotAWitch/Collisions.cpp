#include "Collisions.h"

Collisions* Collisions::getInstance()
{
	if (instance == nullptr) { instance = new Collisions(); }
	return instance;
}