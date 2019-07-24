#pragma once
#include "Cell.h"
#include "BaseObject.h"
#include "Constants.h"
#include <list>
class Grid
{
public:
	// Create a grid for a prefixed map.
	Grid();
	~Grid();

	// Edge size of a cell
	static const int CELL_SIZE = 50;

	// Total number of columns based on prefixed map width
	static const int NUM_COLUMNS = MAP_WIDTH / CELL_SIZE;

	// Total number of rows based on prefixed map height
	static const int NUM_ROWS = MAP_HEIGHT / CELL_SIZE;

	void add(BaseObject* object);

	std::list<BaseObject*> getAllObjects(int column, int row) { return cells[column][row]->getAllObjects(); }

	// Return a list of colliable objects of an object sitting in one cell. 
	// We scan 4 others adjacent cells as well.
	// Pass a cell position to the function to retrieve collidable objects in that cell and 4 adjacent cells.
	void getCollidableObjects(std::list<BaseObject*>& result, int column, int row);

private:
	Cell* cells[NUM_COLUMNS][NUM_ROWS];
};
