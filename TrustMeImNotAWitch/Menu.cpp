#include "Menu.h"

Menu::Menu()
{
	UIManagers::getInstance().createUI(UI_TYPE::BUTTON, UI_LIST::MENU, sf::Vector2f(800,800), sf::Vector2f(100,100),sf::Color::Cyan,"Play",'P');
}

bool Menu::runMain(sf::RenderWindow& window)
{

	std::shared_ptr<UIElements> elem = UIManagers::getInstance().getMenuUI('P');
	std::shared_ptr<UIButton> button = std::dynamic_pointer_cast<UIButton>(elem);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (button->onClick(window))
            return true;

        window.clear();
        UIManagers::getInstance().drawMenu(window);
        window.display();
    }
		
	return false;
}
