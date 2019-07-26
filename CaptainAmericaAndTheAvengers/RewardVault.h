#pragma once
#include "BaseObject.h"
#include "Animation.h"


class RewardVault : public BaseObject
{
private:
	Animation *anim;

public:
	RewardVault();
	RewardVault(TextureManager* textureM, Graphics* graphics);
	~RewardVault();

	void update(float dt);
	void draw();

	void setActivity(bool flag);
	bool getActivity();
};

#pragma once
