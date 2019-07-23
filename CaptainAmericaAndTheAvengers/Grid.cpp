#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
	// Clear the grid.
	for (int x = 0; x < NUM_COLUMNS; x++)
	{
		for (int y = 0; y < NUM_ROWS; y++)
		{
			cells[x][y] = new Cell();
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

void Grid::getCollidableObjects(std::list<BaseObject*>& result, int column, int row)
{
	// References: https://gameprogrammingpatterns.com/spatial-partition.html?fbclid=IwAR3KCo4gASEb1z0P3pgGv_Ttb7nQP_-58MCYzyvOlo6_ft3IjEuTXuozZWQ
	result.merge(cells[column][row]->getAllObjects());

	if (column > 0 && row > 0) 
	{
		result.merge(cells[column - 1][row - 1]->getAllObjects());
	}
	if (column > 0) 
	{
		result.merge(cells[column - 1][row]->getAllObjects());
	}
	if (row > 0)
	{
		result.merge(cells[column][row - 1]->getAllObjects());
	}
	if (column > 0 && row < NUM_ROWS - 1)
	{
		result.merge(cells[column - 1][row + 1]->getAllObjects());
	}
}
