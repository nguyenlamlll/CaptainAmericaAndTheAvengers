#include "stdafx.h"
#include "SceneManager.h"
#include "OptionScene.h"
#include "PlayScene.h"
#include "Constants.h"
#include "EndScene.h"
//#include "Sound.h"

SceneManager* SceneManager::instance;

SceneManager * SceneManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new SceneManager();
	}
	return instance;
}

Scene * SceneManager::getScene(SceneType type)
{
	return (*sceneContainer->find(type)).second;
}
void SceneManager::goToScene(SceneType type)
{
	currentScene = (*sceneContainer->find(type)).second;
}
LRESULT SceneManager::messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);					//tell Windows to kill this program
		return 0;
	case WM_KEYDOWN: case WM_SYSKEYDOWN:    // key down
		input->keyDown(wParam);
		return 0;
	case WM_KEYUP: case WM_SYSKEYUP:        // key up
		input->keyUp(wParam);
		return 0;
	case WM_CHAR:                           // character entered
		input->keyIn(wParam);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);    // let Windows handle it
}
void SceneManager::insertScene(const char * name, Scene * Scene)
{

}

void SceneManager::run()
{
	this->currentScene->run();
	input->clear(InputNS::KEYS_PRESSED);
	if (input->isKeyDown(VK_RETURN))
	{
		this->goToScene(SceneType::PLAY);

		//Sound::getInstance()->stop(SOUND_TITLE);
		//Sound::getInstance()->play(SOUND_BACKGROUND, true);
	}
}

void SceneManager::init(HWND hwnd)
{
	this->handle = hwnd;
	input = new  Input();

	graphics = new Graphics();

	graphics->initialize(hwnd, VIEWPORT_WIDTH, VIEWPORT_HEIGHT, FULLSCREEN);

	input->initialize(hwnd, false);

	this->sceneContainer = new std::map<SceneType, Scene*>();
	OptionScene* optionS = new OptionScene(graphics, input);
	optionS->init();
	PlayScene* playS = new PlayScene(graphics, input);
	EndScene* endS = new EndScene(graphics, input);
	endS->init();

	currentScene = optionS;
	//sceneContainer->insert(std::pair<SceneType, Scene*>(SceneType::OPTION, optionS));
	//this->sceneContainer->insert(std::pair<SceneType, Scene*>(SceneType::OPTION, optionS));
	//this->sceneContainer->insert(std::pair<SceneType, Scene*>(SceneType::PLAY, playS));
	//this->sceneContainer->insert(std::pair<SceneType, Scene*>(SceneType::END, endS));

	//Sound::getInstance()->loadAllSound();
	//Sound::getInstance()->play(SOUND_TITLE, true);
}

void SceneManager::deleteAll()
{
	for (auto i = sceneContainer->begin(); i != sceneContainer->end(); ++i)
	{
		(*i).second->release();
		delete ((*i).second);
	}
	delete sceneContainer;
	graphics->releaseAll();
	ShowCursor(true);
	delete input;
	delete instance;
}

HWND SceneManager::getHWnd()
{
	return this->handle;
}

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{

}
