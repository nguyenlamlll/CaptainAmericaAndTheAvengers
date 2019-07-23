#include "stdafx.h"
#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = nullptr;
ObjectManager::ObjectManager()
{
	this->totalObjectsPerFrame = 0;
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

	grid = new Grid();
	grid->add(this->captainAmerica);
	//std::list<BaseObject*> objects;
	//grid->getCollidableObjects(objects, 13, 35);
	//grid->getAllObjects(13, 35);
}

void ObjectManager::update(float dt)
{
}

void ObjectManager::draw()
{
}
