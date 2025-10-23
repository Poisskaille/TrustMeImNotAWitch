#pragma once
#include <iostream>

class Collisions
{
private:
	Collisions() {}

	bool isPaused;
	bool isGameRunning;

public:
	static Collisions* instance;
	static Collisions* getInstance();
	//~Collisions();

	void checkCollisions();

	void setGameRunning(bool _isGameRunning);
	void setPaused(bool _isPaused);
};