#pragma once
#include <list>
#include "BaseObject.h"
class Cell
{
private: 
	std::list<BaseObject*> listOfObjects;
public:
	Cell();
	~Cell();

	void add(BaseObject* object);
	std::list<BaseObject*> getAllObjects() { return listOfObjects; }
};

