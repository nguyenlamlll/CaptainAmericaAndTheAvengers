#pragma once
#include "Constants.h"
#include "MapInfo.h"
#include "TextureManager.h"
#include "Graphics.h"
class Map
{
private:
	MapInfo* info;
	TextureManager* texture;
	Graphics* graphics;

public:
	Map();
	~Map();

	bool initialize(Graphics* graphics, TextureManager* texture, MapInfo* info);

	void draw();
	void update(float dt);
	void collision();
};

