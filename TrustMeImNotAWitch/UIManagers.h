#pragma once
#include "UIImage.h"
#include <memory>
#include <vector>
#include "UIButton.h"

enum class UI_TYPE{IMAGE, BUTTON};
enum class UI_LIST{CAMERA, MENU};

class UIManagers
{
public:
	static UIManagers& getInstance();

	void updateCam(const sf::Vector2f& pos);
	void drawCam(sf::RenderWindow& window);
	void drawMenu(sf::RenderWindow& window);

	void createUI(UI_TYPE type, UI_LIST, const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color, const std::string&, const char);
	
	std::shared_ptr<UIElements> getCamUI(const char i);
	std::shared_ptr<UIElements> getMenuUI(const char i);

private:

	std::vector<std::shared_ptr<UIElements>> uiCamera;
	std::vector<std::shared_ptr<UIElements>> uiMenu;

};

