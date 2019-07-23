#pragma once
#include <fstream>
#include <list>
#include "rapidjson-master\include\rapidjson\istreamwrapper.h"
#include "rapidjson-master\include\rapidjson\reader.h"
#include "rapidjson-master\include\rapidjson\document.h"
#include "rapidjson-master\include\rapidjson\filereadstream.h"

#include "Graphics.h"
#include "Constants.h"

#include "CaptainAmerica.h"

#include "Grid.h"

#include <map>

using namespace rapidjson;
using namespace std;

class ObjectManager
{
private:
	static ObjectManager* instance;

	TextureManager* textureManager;
	Graphics* graphics;

	Grid* grid;

	CaptainAmerica* captainAmerica;

	int totalObjectsPerFrame;

public:
	ObjectManager();
	~ObjectManager();

	static ObjectManager* getInstance();
	void init(TextureManager* textureM, Graphics* graphics, CaptainAmerica* captainAmerica);

	void update(float dt);
	void draw();

	int getTotalObjectsPerFrame() { return totalObjectsPerFrame; }
	void setTotalObjectsPerFrame(int value) { totalObjectsPerFrame = value; }
};

