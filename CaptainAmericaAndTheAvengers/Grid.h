#pragma once
#include "Cell.h"
#include "BaseObject.h"
#include "Constants.h"
class Grid
{
public:
	Grid();
	~Grid();

	// Edge size of a cell
	static const int CELL_SIZE = 50;

	// Total number of cells
	static const int NUM_COLUMNS = MAP_WIDTH / CELL_SIZE;

	static const int NUM_ROWS = MAP_HEIGHT / CELL_SIZE;

	void add(BaseObject* object);

private:
	Cell* cells[NUM_COLUMNS][NUM_COLUMNS];
};

