#pragma once
#include "UIManagers.h"
#include <fstream>
class Score
{
public:

	void highScore();
	void newScore();
	void addScore(int value);

private:

	int score = 0.f;
	std::vector<int> scoreList;
};

