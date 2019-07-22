#include "stdafx.h"
#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = nullptr;
ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

ObjectManager * ObjectManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ObjectManager();
	}
	return instance;
}

void ObjectManager::init(TextureManager * textureM, Graphics * graphics, CaptainAmerica * captainAmerica)
{
	this->textureManager = textureM;
	this->graphics = graphics;
	this->captainAmerica = captainAmerica;
}

void ObjectManager::update(float dt)
{
}

void ObjectManager::draw()
{
}
