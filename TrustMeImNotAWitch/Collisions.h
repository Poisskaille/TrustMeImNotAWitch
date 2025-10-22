#pragma once
class Collisions
{
private:
	static Collisions* instance;
	Collisions(){};
public:
	static Collisions* getInstance();
	~Collisions();
};

extern Collisions* collisions;