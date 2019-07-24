#include "stdafx.h"
#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = nullptr;
ObjectManager::ObjectManager()
{
	this->totalObjectsPerFrame = 0;
	this->timer = 0;

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

bool ObjectManager::loadMapObjects(const char * fileName)
{
	try 
	{
		ifstream ifs(fileName);
		IStreamWrapper isw(ifs);
		Document jSon;
		jSon.ParseStream(isw);
		float x, y, height, width;
		int id;
		GameRect bound;

#pragma region Load Grounds (Including grounds and walls)
		const Value& groundObjectList = jSon["Ground"];
		for (SizeType i = 0; i < groundObjectList.Size(); i++)
		{
			BaseObject* ground = new BaseObject(eID::GROUND);
			id = groundObjectList[i]["id"].GetInt();
			x = groundObjectList[i]["x"].GetFloat();
			y = groundObjectList[i]["y"].GetFloat();
			height = groundObjectList[i]["height"].GetFloat();
			width = groundObjectList[i]["width"].GetFloat();

			bound.left = x;
			bound.top = y;
			bound.right = bound.left + width;
			bound.bottom = bound.top - height;
			ground->setBoundCollision(bound);

			ground->setActiveBound(bound);

			mapObjects.insert(std::pair<int, BaseObject*>(id, ground));
		}
#pragma endregion


		return true;
	}
	catch (...) 
	{
	}
	return false;
}

#define TIME_RETRIEVE 0.65f
void ObjectManager::handleVelocity(float dt)
{
	// Update the objects on viewport after a short period of time.
	timer += dt;
	if (timer >= TIME_RETRIEVE)
	{
		
	}
}

void ObjectManager::onCheckCollision(float frametime)
{

}

void ObjectManager::onCheckCollision(BaseObject * obj, float frametime)
{
}
