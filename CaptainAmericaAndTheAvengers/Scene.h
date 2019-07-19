#pragma once

#include "Graphics.h"
#include "Input.h"

class Scene
{
protected:
	Graphics* graphics;
	Input* input;
public:
	Scene();
	~Scene();

	Scene(Graphics* graphics, Input* input);
	virtual void init();
	virtual void update();
	virtual void draw();
	virtual void run();
	virtual void release();
	void handleLostGraphicsDevice();
};

