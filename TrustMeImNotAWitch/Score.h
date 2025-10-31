#pragma once
#include "UIManagers.h"
#include <fstream>

class Score
{
public:
	static Score* getInstance();

	void highScore();
	void newScore();
	void addScore(int value);

	void changeMultiplier(float value);

	std::vector<int> getScore();

private:

	int score = 0;
	std::vector<int> scoreList;

	float scoreMult = 1;

	static Score* instance;
};

extern Score* managerScore;

