#include "UIManagers.h"

UIManagers& UIManagers::getInstance()
{
	static UIManagers instance;
	return instance;
}

void UIManagers::UpdateCam(const sf::Vector2f& pos)
{
	if (uiCamera.size() != 0)
	{
		for (auto& _ui : uiCamera)
		{
			_ui->UpdatePosition(pos);
		}
	}
}

void UIManagers::DrawCam(sf::RenderWindow& window)
{
	if (uiCamera.size() != 0)
	{
		for (auto& _ui : uiCamera)
		{
			_ui->Draw(window);
		}
	}
}

void UIManagers::CreateUI(UI_TYPE type, UI_LIST list, const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color, const std::string& str)
{
	switch(type)
	{
	case UI_TYPE::IMAGE:
		if(list == UI_LIST::CAMERA)
			uiCamera.push_back(std::make_shared<UIImage>(pos, size, color, str));
		else
			uiMenu.push_back(std::make_shared<UIImage>(pos, size, color, str));
		break;
	case UI_TYPE::BUTTON:
		if(list == UI_LIST::CAMERA)
		{ 
			std::cout << "Caca" << '\n';
			uiCamera.push_back(std::make_shared<UIButton>(pos, size, color, str)); }

		else
			uiMenu.push_back(std::make_shared<UIButton>(pos, size, color, str));
		break;
	}
}
