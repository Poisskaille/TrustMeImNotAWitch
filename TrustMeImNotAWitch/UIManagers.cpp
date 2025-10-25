#include "UIManagers.h"

UIManagers& UIManagers::getInstance()
{
	static UIManagers instance;
	return instance;
}

void UIManagers::updateCam(const sf::Vector2f& pos)
{
	if (uiCamera.size() != 0)
	{
		for (auto& _ui : uiCamera)
		{
			_ui->updatePosition(pos);
		}
	}
}

void UIManagers::drawCam(sf::RenderWindow& window)
{
	if (uiCamera.size() != 0)
	{
		for (auto& _ui : uiCamera)
		{
			_ui->draw(window);
		}
	}
}

void UIManagers::drawMenu(sf::RenderWindow& window)
{
	if (uiMenu.size() != 0)
	{
		for (auto& _ui : uiMenu)
		{
			_ui->draw(window);
		}
	}
}

void UIManagers::createUI(UI_TYPE type, UI_LIST list, const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color, const std::string& str, const char c)
{
	switch(type)
	{
	case UI_TYPE::IMAGE:
		if(list == UI_LIST::CAMERA)
			uiCamera.push_back(std::make_shared<UIImage>(pos, size, color, str,c));
		else
			uiMenu.push_back(std::make_shared<UIImage>(pos, size, color, str,c));
		break;
	case UI_TYPE::BUTTON:
		if(list == UI_LIST::CAMERA)
		{ 
			std::cout << "Caca" << '\n';
			uiCamera.push_back(std::make_shared<UIButton>(pos, size, color, str,c)); }

		else
			uiMenu.push_back(std::make_shared<UIButton>(pos, size, color, str,c));
		break;
	}
}

std::shared_ptr<UIElements> UIManagers::getCamUI(const char i)
{
	if (uiCamera.size() != 0)
	{
		for (auto& _ui : uiCamera)
		{
			if(_ui->getIndex() == i)
			{
				return _ui;
			}
		}
		return nullptr;
	}
	return nullptr;
}

std::shared_ptr<UIElements> UIManagers::getMenuUI(const char i)
{
	if (uiMenu.size() != 0)
	{
		for (auto& _ui : uiMenu)
		{
			if (_ui->getIndex() == i)
			{
				return _ui;
			}
		}
		return nullptr;
	}
	return nullptr;
}
