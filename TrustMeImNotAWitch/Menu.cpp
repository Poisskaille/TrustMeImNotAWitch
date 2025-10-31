#include "Menu.h"

Menu::Menu()
{
	UIManagers::getInstance().createButton(UI_LIST::MENU, sf::Vector2f(800,600), sf::Vector2f(300,300),"Play",'P',managerText->getTexture("normalPlay"), managerText->getTexture("hoverPlay"));
    UIManagers::getInstance().createButton(UI_LIST::MENU, sf::Vector2f(800, 900), sf::Vector2f(300, 300), "Q", 'E', managerText->getTexture("normalExit"), managerText->getTexture("hoverExit"));

    UIManagers::getInstance().createImage(UI_LIST::MENU, sf::Vector2f(692, 540), { 128,128 }, "", 'c', managerText->getTexture("nottaHat"));

}

bool Menu::runMain(sf::RenderWindow& window)
{
    managerScore->highScore();
	std::shared_ptr<UIElements> elem1 = UIManagers::getInstance().getMenuUI('P');
	std::shared_ptr<UIButton> button1 = std::dynamic_pointer_cast<UIButton>(elem1);

    std::shared_ptr<UIElements> elem2 = UIManagers::getInstance().getMenuUI('E');
    std::shared_ptr<UIButton> button2 = std::dynamic_pointer_cast<UIButton>(elem2);

    sf::RectangleShape background;
    background.setSize({1920,1080});
    background.setTexture(&managerText->getTexture("menu"));

    sf::Font font;
    if (!font.openFromFile("../assets/font/Enchanted Land.otf"))
        std::cout << "Error loading font" << '\n';

    std::vector<int> scores = managerScore->getScore();
    std::vector<sf::Text> scoreTexts;

    sf::Vector2f startPos(1220.f, 100.f);
    float verticalSpacing = 100.f;

    for (size_t i = 0; i < 3; ++i) {
        if (i >= scores.size()) break;

        sf::Text scoreText(font);
        scoreText.setCharacterSize(90);
        scoreText.setString(std::to_string(scores[i]));
        scoreText.setPosition({ startPos.x, startPos.y + i * verticalSpacing });

        scoreTexts.push_back(scoreText);
    }


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (button1->onClick(window))
            return true;

        if (button2->onClick(window))
            return false;

        window.clear();
        window.draw(background);
        UIManagers::getInstance().drawMenu(window);
        for(auto& score : scoreTexts)
        {
            window.draw(score);
        }
        window.display();
    }
		
	return false;
}
