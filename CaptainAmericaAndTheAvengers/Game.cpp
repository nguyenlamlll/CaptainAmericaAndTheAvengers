#include "stdafx.h"
#include "Game.h"
#include "ObjectManager.h"

Game* Game::instance = nullptr;
Game::Game()
{
	this->spriteManger = SpriteManager::getInstance();
	this->textureManager = new TextureManager();

	// new map component
	this->tileset = new TextureManager();
	this->mapInfo = new MapInfo();
	this->map = new Map();

	instance = this;
}


Game::~Game()
{
}

Game * Game::getInstance()
{
	if (instance == nullptr)
		instance = new Game();

	return instance;
}

void Game::initialize(HWND hwnd)
{

}

void Game::initialize(Graphics * graphics, Input * input)
{
	GameManager::initialize(graphics, input); // graphics was init inside

	if (!spriteManger->initialize(SOURCE_JSON))
	{
		throw GameError(GameErrorNS::FATAL_ERROR, "Can not  load json");
	}

	if (!textureManager->initialize(graphics, SOURCE_IMAGE))
	{
		throw GameError(GameErrorNS::FATAL_ERROR, "Can not load spite sheet");
	}

	if (!tileset->initialize(graphics, TILESET_IMAGE))
	{
		throw GameError(GameErrorNS::FATAL_ERROR, "Can not load tileset");
	}

	if (!mapInfo->initialize(MAP_BRINSTAR_JSON))
	{
		throw GameError(GameErrorNS::FATAL_ERROR, "Can not load map info");
	}

	if (!map->initialize(graphics, tileset, mapInfo))
	{
		throw GameError(GameErrorNS::FATAL_ERROR, "Can not initalize map brinstar");
	}

	camera = new Camera(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
	camera->setPosition(VECTOR2(CAM_POS_X, CAM_POS_Y));
	camera->setPosition(VECTOR2(600, 1200));
	fpsText = new Text("FPS: 0", eFont::body, 8, VECTOR2(VIEWPORT_WIDTH - 70, 5), GraphicsNS::WHITE, false, true);
	fpsText->initialize(graphics);
}

void Game::update(float dt)
{
	this->camera->update(dt);
}

void Game::handleInput(float dt)
{
	if (input->isKeyDown(VK_LEFT))
		Camera::getInstance()->setVelocity(VECTOR2(-150, 0));
	if (input->isKeyDown(VK_RIGHT))
		Camera::getInstance()->setVelocity(VECTOR2(150, 0));
	if (input->isKeyDown(VK_UP))
		Camera::getInstance()->setVelocity(VECTOR2(0, 150));
	if (input->isKeyDown(VK_DOWN))
		Camera::getInstance()->setVelocity(VECTOR2(0, -150));
}

void Game::collisions(float dt)
{
}

void Game::render()
{
	this->getGraphics()->spriteBegin();
	map->draw();
	this->getGraphics()->spriteEnd();

	fpsText->setText("FPS: " + std::to_string((int)this->fps));
	fpsText->draw();

	//opsText->setText("DPS: " + std::to_string(ObjectManager::getInstance()->getTotalObjectsPerFrame()));
	//opsText->draw();
}

void Game::releaseAll()
{
}

void Game::resetAll()
{
}

HWND Game::getCurrentHWND()
{
	return HWND();
}
