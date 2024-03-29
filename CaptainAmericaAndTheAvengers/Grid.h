#pragma once
#include "Cell.h"
#include "BaseObject.h"
#include "Constants.h"
#include <map>
class Grid
{
public:
	// Create a grid for a prefixed map.
	Grid();
	~Grid();

	// Edge size of a cell
	static const int CELL_SIZE = 200;

	// Total number of columns based on prefixed map width
	static const int NUM_COLUMNS = MAP_WIDTH / CELL_SIZE;

	// Total number of rows based on prefixed map height
	static const int NUM_ROWS = MAP_HEIGHT / CELL_SIZE;

	void CheckAndAddOversizedObject(BaseObject * object, D3DXVECTOR2 &objectPositionOnGrid, int id);
	void CheckAndAddOversizedObject(BaseObject * object, int x, int y, D3DXVECTOR2 &objectPositionOnGrid, int id);
	void add(int id, BaseObject* object);
	void add(int id, BaseObject* object, int x, int y);
	VECTOR2 calculateObjectPositionOnGrid(BaseObject* object);
	VECTOR2 calculateObjectPositionOnGrid(int x, int y);

	std::map<int, BaseObject*>* getAllObjects(int column, int row) { return cells[column][row]->getAllObjects(); }

	// Return a list of colliable objects of an object sitting in one cell. 
	// We scan 4 others adjacent cells as well.
	// Pass a cell position to the function to retrieve collidable objects in that cell and 4 adjacent cells.
	void getCollidableObjects(std::map<int, BaseObject*>* result, int column, int row);

private:
	Cell* cells[NUM_COLUMNS][NUM_ROWS];
};

