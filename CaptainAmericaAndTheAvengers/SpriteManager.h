#pragma once
#include "Graphics.h"
#include "Constants.h"
#include <fstream>
#include <iostream>

#include "rapidjson-master\include\rapidjson\istreamwrapper.h"
#include "rapidjson-master\include\rapidjson\reader.h"
#include "rapidjson-master\include\rapidjson\document.h"
#include "rapidjson-master\include\rapidjson\filereadstream.h"
#include "rapidjson-master\include\rapidjson\writer.h"
#include "rapidjson-master\include\rapidjson\ostreamwrapper.h"

using namespace rapidjson;
using namespace std;

class SpriteManager
{
private:
	static SpriteManager* instance;
	//list of sprites data
	SpriteData* spritesData;
	//filename to read
	const char* filename;
public:
	static SpriteManager* getInstance();
	bool initialize(const char* filename);
	void releaseAll();
	const SpriteData* getSpritesData();
	SpriteManager(void);
	~SpriteManager(void);
};

