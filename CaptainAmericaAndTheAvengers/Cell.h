#pragma once
#include <map>
#include "BaseObject.h"
class Cell
{
private: 
	std::map<int, BaseObject*>* listOfObjects;
public:
	Cell();
	~Cell();

	void add(int id, BaseObject* object);
	std::map<int, BaseObject*>* getAllObjects() { return listOfObjects; }
};

