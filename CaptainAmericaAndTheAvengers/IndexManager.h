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

	const int captainAmericaAttack[2] = { 0, 1 };
	const int captainAmericaDash[3] = { 2, 3, 4 };
	const int captainAmericaDie[2] = { 5, 6 };
	const int captainAmericaJump[1] = { 7 };
	const int captainAmericaKick[1] = { 8 };
	const int captainAmericaLookUp[1] = { 9 };
	const int captainAmericaMove[4] = { 10, 11, 12, 13 };
	const int captainAmericaShieldlessAttack[2] = { 14,15 };
	const int captainAmericaSit[1] = { 16 };
	const int captainAmericaSitAttack[2] = { 17,18 };
	const int captainAmericaSpin[2] = { 19, 20 };
	const int captainAmericaStand[1] = { 21 };


	const int soldierStand = { 30 };
	const int soldierMove[3] = { 27, 28, 29 };
	const int soldierSit = { 31 };
	const int soldierDie = { 32 };
	const int soldierBullet = { 33 };
};

