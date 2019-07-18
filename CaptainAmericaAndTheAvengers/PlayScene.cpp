#include "stdafx.h"
#include "PlayScene.h"


PlayScene::PlayScene()
{
}

PlayScene::PlayScene(Graphics * graphics, Input * input)
{
	game = new Game();
	game->initialize(graphics, input);
}

PlayScene::~PlayScene()
{
}

void PlayScene::init()
{
}

void PlayScene::update()
{
}

void PlayScene::draw()
{
}

void PlayScene::run()
{
	game->run();
}

void PlayScene::release()
{
	game->releaseAll();
}
