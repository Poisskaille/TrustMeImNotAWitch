#include "Score.h"

void Score::AddScore(float value)
{
	score += value;
	std::string newValue = std::to_string(score);
	UIManagers::getInstance().getUI('s')->UpdateText(newValue);
}
