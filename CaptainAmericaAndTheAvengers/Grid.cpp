#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
	// Clear the grid.
	for (int x = 0; x < NUM_COLUMNS; x++)
	{
		for (int y = 0; y < NUM_ROWS; y++)
		{
			cells[x][y] = NULL;
		}
	}
}


Grid::~Grid()
{
}

void Grid::add(BaseObject * object)
{
	int cellX = (int)(object->getPosition().x / Grid::CELL_SIZE);
	int cellY = (int)(object->getPosition().y / Grid::CELL_SIZE);

	cells[cellX][cellY]->add(object);
}
