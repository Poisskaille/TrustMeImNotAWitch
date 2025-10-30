#include "Score.h"

Score* Score::getInstance()
{
	if (instance == nullptr) { instance = new Score(); }
	return instance;
}

void Score::highScore()
{
	std::fstream file("../assets/Score/high_score.txt");
	if(!file.is_open())
	{
		std::cout << "Generating score file " << '\n';
	}

	char currentChar;
	std::string currentWord = "";
	
	while(file.get(currentChar))
	{
		if(currentChar == ';')
		{
			scoreList.push_back(std::stoi(currentWord));
			currentWord.clear();
			continue;
		}

		currentWord += currentChar;
	}

	file.close();
	
	if(scoreList.size() != 0)
		std::sort(scoreList.begin(), scoreList.end(), std::greater<int>());

}

void Score::newScore()
{
	std::fstream nFile("../assets/Score/high_score.txt", std::ofstream::out | std::ofstream::trunc);

	scoreList.push_back(score);
	std::sort(scoreList.begin(), scoreList.end(), std::greater<int>());	

	if (scoreList.size() > 3)
		scoreList.erase(scoreList.end() - 1);

	for (int i = 0; i < scoreList.size(); i++)
	{
		nFile << scoreList[i] << ";" << '\n';
	}
}

void Score::addScore(int value)
{
	score += value * scoreMult;
	std::string newValue = std::to_string(score);
	UIManagers::getInstance().getCamUI('s')->updateText(newValue);
}

void Score::changeMultiplier(float value)
{
	scoreMult = value;
}

Score* Score::instance = nullptr;
Score* managerScore = Score::getInstance();
