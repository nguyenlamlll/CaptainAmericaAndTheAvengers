#pragma once
#include "GameManager.h"
#include "TextureManager.h"
#include "SpriteManager.h"
#include "Camera.h"
#include "Map.h"

class Game : public GameManager
{
private:
	static Game* instance;

	TextureManager *textureManager;
	SpriteManager *spriteManger;

	TextureManager *tileset;
	Map* map;

	Camera* camera;

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

