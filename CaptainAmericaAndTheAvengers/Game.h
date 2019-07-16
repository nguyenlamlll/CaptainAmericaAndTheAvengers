#pragma once
#include "GameManager.h"

#include "Camera.h"

class Game : public GameManager
{
private:
	static Game* instance;

	//TextureManager *textureManager;
	//SpriteManager *spriteManger;

	Camera *camera;

public:
	Game();
	~Game();

	static Game* getInstance();

	void initialize(HWND hwnd);
	void initialize(Graphics* graphics, Input* input);
	void update(float dt);      // must override pure virtual from Game
	void handleInput(float dt);
	void collisions(float dt);  // "
	void render();      // "
	void releaseAll();
	void resetAll();


	HWND getCurrentHWND();
};

