#pragma once
#include "Constants.h"
namespace Utilities 
{
	D3DXVECTOR2 TopLeftCoordinatesToBottomLeftCoordinates(int x, int y)
	{
		return D3DXVECTOR2(x, MAP_HEIGHT - y);
	}
}