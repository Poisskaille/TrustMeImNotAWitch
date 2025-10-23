#include "CameraUI.h"

CameraUI::CameraUI(sf::Vector2f pos): Y_OFFSET(pos.y + 400)
{
	cam.setSize({ 800.f,400.f });
	cam.zoom(1.5f);
	cam.setCenter(sf::Vector2f(pos.x, Y_OFFSET));

	InitUI();
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

	UIManagers::getInstance().UpdateCam(cam.getCenter());
}

void CameraUI::DrawUI(sf::RenderWindow& window)
{
	UIManagers::getInstance().DrawCam(window);
}

void CameraUI::InitUI()
{
	UIManagers::getInstance().CreateUI(UI_TYPE::IMAGE,UI_LIST::CAMERA,sf::Vector2f(cam.getCenter().x, (cam.getSize().y / 2) - 50), sf::Vector2f(100, 50), sf::Color::Blue, "Test",'s');
	//UIManagers::getInstance().CreateUI(UI_TYPE::BUTTON, UI_LIST::CAMERA, sf::Vector2f(cam.getCenter().x + 500, cam.getCenter().y - 600), sf::Vector2f(50, 50), sf::Color::Magenta, "B",'');
}

sf::View CameraUI::getCam()
{
	return cam;
}

