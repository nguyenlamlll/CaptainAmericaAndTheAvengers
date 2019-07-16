#include "stdafx.h"
#include "Game.h"
#include "ObjectManager.h"
Game* Game::instance = nullptr;
Game::Game()
{
	//this->spriteManger = SpriteManager::getInstance();
	//this->textureManager = new TextureManager();

	//// new map component
	//this->tileset = new TextureManager();
	//this->mapInfo = new MapInfo();
	//this->mapBrinstar = new Map();

	//instance = this;
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
}

void Game::update(float dt)
{
}

void Game::handleInput(float dt)
{
}

void Game::collisions(float dt)
{
}

void Game::render()
{
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
