#pragma once
#include "Outils.h"

class Score
{
public:

	void highScore();
	void newScore();
	void addScore(int value);

private:

	int score = 0;
	std::vector<int> scoreList;
};

