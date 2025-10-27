#include "CameraUI.h"

CameraUI::CameraUI(sf::Vector2f pos) : Y_OFFSET(pos.y + 75)
{
	cam.setSize({ 800.f,400.f });
	cam.zoom(2.5f);
	cam.setCenter(sf::Vector2f(pos.x, Y_OFFSET));

	initUI();
}

void CameraUI::update(sf::Vector2f playerPos)
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

	UIManagers::getInstance().updateCam(cam.getCenter());
}

void CameraUI::drawUI(sf::RenderWindow& window)
{
	UIManagers::getInstance().drawCam(window);
}

void CameraUI::initUI()
{
	UIManagers::getInstance().createUI(UI_TYPE::IMAGE, UI_LIST::CAMERA, sf::Vector2f(cam.getCenter().x, (cam.getSize().y / 2) - 50), sf::Vector2f(256, 128), sf::Color::Blue, "Test", 's');
}

sf::View CameraUI::getCam()
{
	return cam;
}