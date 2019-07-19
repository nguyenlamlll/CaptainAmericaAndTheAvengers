#pragma once
// Class used to manage Index Sprites in Texture

#define MAX_INDEX 311
class IndexManager
{
private:
	static IndexManager* instance;
	IndexManager();
	~IndexManager();

public:
	static IndexManager* getInstance();

	const int captainAmericaHit[4] = { 0, 1, 2, 3 };
	const int captainAmericaJump[3] = { 4, 5, 6 };
	const int captainAmericaKick[5] = { 7, 8, 9, 10, 11 };
	const int captainAmericaStart[1] = { 12 };
	const int captainAmericaMove[5] = { 12, 13, 14, 15, 16 };
	const int captainAmericaSitAttack[5] = { 17, 18, 19, 20, 21 };
	const int captainAmericaSpin[7] = { 22, 23, 24, 25, 26, 27, 28 };
};

