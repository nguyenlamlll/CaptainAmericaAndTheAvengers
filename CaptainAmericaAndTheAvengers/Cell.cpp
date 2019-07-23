#include "stdafx.h"
#include "Cell.h"


Cell::Cell()
{
}


Cell::~Cell()
{
	for (list<BaseObject*>::const_iterator it = listOfObjects.begin(); it != listOfObjects.end(); ++it)
	{
		delete *it;
	}
	listOfObjects.clear();
}

void Cell::add(BaseObject * object)
{
	listOfObjects.push_front(object);
}
