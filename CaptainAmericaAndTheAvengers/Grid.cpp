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

void Grid::add(int id, BaseObject * object)
{
	auto objectPositionOnGrid = calculateObjectPositionOnGrid(object);

	cells[(int)objectPositionOnGrid.x][(int)objectPositionOnGrid.y]->add(id, object);
}

void Grid::add(int id, BaseObject * object, int x, int y)
{
	auto objectPositionOnGrid = calculateObjectPositionOnGrid(object, x, y);

	cells[(int)objectPositionOnGrid.x][(int)objectPositionOnGrid.y]->add(id, object);
}

VECTOR2 Grid::calculateObjectPositionOnGrid(BaseObject * object)
{
	int cellX = (int)(object->getPosition().x / Grid::CELL_SIZE);
	int cellY = (int)(object->getPosition().y / Grid::CELL_SIZE);
	return VECTOR2(cellX, cellY);
}

VECTOR2 Grid::calculateObjectPositionOnGrid(BaseObject * object, int x, int y)
{
	int cellX = (int)(x / Grid::CELL_SIZE);
	int cellY = (int)(y / Grid::CELL_SIZE);
	return VECTOR2(cellX, cellY);
}

void Grid::getCollidableObjects(std::map<int, BaseObject*>* result, int column, int row)
{
	// References: https://gameprogrammingpatterns.com/spatial-partition.html?fbclid=IwAR3KCo4gASEb1z0P3pgGv_Ttb7nQP_-58MCYzyvOlo6_ft3IjEuTXuozZWQ
	auto objects = cells[column][row]->getAllObjects();
	result->insert(objects->begin(), objects->end());

	if (column > 0 && row > 0) 
	{
		objects = cells[column - 1][row - 1]->getAllObjects();
		result->insert(objects->begin(), objects->end());
	}
	if (column > 0) 
	{
		objects = cells[column - 1][row]->getAllObjects();
		result->insert(objects->begin(), objects->end());
	}
	if (row > 0)
	{
		objects = cells[column][row - 1]->getAllObjects();
		result->insert(objects->begin(), objects->end());
	}
	if (column > 0 && row < NUM_ROWS - 1)
	{
		objects = cells[column - 1][row + 1]->getAllObjects();
		result->insert(objects->begin(), objects->end());
	}
}
