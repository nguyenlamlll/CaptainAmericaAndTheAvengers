#pragma once

#include <Windows.h>
#include <map>
#include "gameError.h"
#include "constants.h"
//#include "Metroid.h"
#include "resource.h"
#include "Scene.h"

class SceneManager
{
private:
	std::map<SceneType, Scene*>* sceneContainer;

	Scene* currentScene;

	HWND handle;

	Input* input;

	bool pause;

	Graphics* graphics;

	static SceneManager* instance;
public:
	static SceneManager* getInstance();

	Scene* getScene(SceneType type);

	void goToScene(SceneType type);


	LRESULT messageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void insertScene(const char* name, Scene* Scene);

	void run();

	void init(HWND hwnd);

	void deleteAll();

	HWND getHWnd();

	SceneManager();
	~SceneManager();
};


