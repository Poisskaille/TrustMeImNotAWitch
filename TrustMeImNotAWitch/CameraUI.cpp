#include "CameraUI.h"

CameraUI::CameraUI(sf::Vector2f pos): Y_OFFSET(pos.y + 400)
{
	cam.setSize({ 800.f,400.f });
	cam.zoom(1.5f);
	cam.setCenter(sf::Vector2f(pos.x, Y_OFFSET));

	sf::RectangleShape test1;
	test1.setSize(sf::Vector2f(200.f, 100.f));
	test1.setFillColor(sf::Color::Magenta);

	uiList.push_back(std::make_shared<UI>(test1,"CACA", sf::Vector2f(cam.getSize())));
}

void CameraUI::Update(sf::Vector2f playerPos)
{
	sf::Vector2f viewCenter = cam.getCenter();
	viewCenter.x = playerPos.x + 400.f;

	float cameraTargetY = Y_OFFSET;

	if (playerPos.y < 200.f)
	{
		float delta = 200.f - playerPos.y;
		cameraTargetY -= delta;
	}

	viewCenter.y += (cameraTargetY - viewCenter.y);

	cam.setCenter(sf::Vector2(viewCenter));

	UpdateUI(cam.getCenter());
}

void CameraUI::Draw(sf::RenderWindow& window)
{
	if(uiList.size() != 0)
	{
		for(auto& _ui : uiList)
		{
			_ui->Draw(window);
		}
	}
}

void CameraUI::UpdateUI(sf::Vector2f vec2)
{
	if(uiList.size() != 0)
	{
		for(auto& _ui : uiList)
		{
			_ui->UpdatePosition(vec2);
		}
	}
}

sf::View CameraUI::getCam()
{
	return cam;
}

