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

void UIManagers::createButton(UI_LIST list, const sf::Vector2f& pos, const sf::Vector2f& size,const std::string& str, const char c, sf::Texture& text1, sf::Texture& text2)
{
	switch(list)
	{
	case UI_LIST::CAMERA:
		uiCamera.push_back(std::make_shared<UIButton>(pos, size,str, c, text1, text2));
		break;
	case UI_LIST::MENU:
		uiMenu.push_back(std::make_shared<UIButton>(pos, size, str, c, text1, text2));
		break;
	}
}

void UIManagers::createImage(UI_LIST list, const sf::Vector2f& pos, const sf::Vector2f& size, const std::string& str, const char c, sf::Texture& text)
{
	switch (list)
	{
	case UI_LIST::CAMERA:
		uiCamera.push_back(std::make_shared<UIImage>(pos, size, str, c,text));
		break;
	case UI_LIST::MENU:
		uiMenu.push_back(std::make_shared<UIImage>(pos, size, str, c,text));
		break;
	}
}

void UIManagers::clearCam()
{
	uiCamera.clear();
}

void UIManagers::clearMenu()
{
	uiMenu.clear();
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
