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
};

