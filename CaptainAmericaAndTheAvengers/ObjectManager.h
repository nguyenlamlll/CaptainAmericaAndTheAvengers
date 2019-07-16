#pragma once
#include<fstream>
#include <list>
#include "rapidjson-master\include\rapidjson\istreamwrapper.h"
#include "rapidjson-master\include\rapidjson\reader.h"
#include "rapidjson-master\include\rapidjson\document.h"
#include "rapidjson-master\include\rapidjson\filereadstream.h"

#include "Graphics.h"
#include "Constants.h"

#include <map>

using namespace rapidjson;
using namespace std;

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
};

