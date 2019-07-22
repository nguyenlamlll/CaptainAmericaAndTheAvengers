#include "stdafx.h"
#include "Cell.h"


Cell::Cell()
{
}


Cell::~Cell()
{
}

void Cell::add(BaseObject * object)
{
	listOfObjects.push_front(object);
}
