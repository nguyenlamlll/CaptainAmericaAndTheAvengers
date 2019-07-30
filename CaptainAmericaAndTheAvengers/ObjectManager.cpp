#include "stdafx.h"
#include "ObjectManager.h"


ObjectManager* ObjectManager::instance = nullptr;
ObjectManager::ObjectManager()
{
	this->totalObjectsPerFrame = 0;
	this->timer = 0;

	this->listWallCanCollideCaptainAmerica = new map<int, BaseObject*>();
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
	grid->add(999, this->captainAmerica);
	//std::list<BaseObject*> objects;
	//grid->getCollidableObjects(objects, 13, 35);
	//grid->getAllObjects(13, 35);
}

void ObjectManager::update(float dt)
{
	if (listWallCanCollideCaptainAmerica)
	{
		for (auto i = listWallCanCollideCaptainAmerica->begin(); i != listWallCanCollideCaptainAmerica->end(); ++i)
		{
			BaseObject* object = (*i).second;
			object->update(dt);
		}
	}
}

void ObjectManager::draw()
{
	if (listWallCanCollideCaptainAmerica)
	{
		for (auto i = listWallCanCollideCaptainAmerica->begin(); i != listWallCanCollideCaptainAmerica->end(); ++i)
		{
			(*i).second->draw();
		}
	}
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
			y = MAP_HEIGHT - groundObjectList[i]["y"].GetFloat();
			height = groundObjectList[i]["height"].GetFloat();
			width = groundObjectList[i]["width"].GetFloat();

			bound.left = x;
			bound.top = y;
			bound.right = bound.left + width;
			bound.bottom = bound.top - height;
			ground->setBoundCollision(bound);

			ground->setActiveBound(bound);

			mapObjects.insert(std::pair<int, BaseObject*>(id, ground));

			grid->add(id, ground, x, y);
		}
#pragma endregion


#pragma region Load Enemies
		const Value& soldierObjectList = jSon["Soldier"];
		for (SizeType i = 0; i < soldierObjectList.Size(); i++)
		{
			Soldier* soldier = new Soldier(this->textureManager, this->graphics);
			id = soldierObjectList[i]["id"].GetInt();
			x = soldierObjectList[i]["x"].GetFloat();
			y = MAP_HEIGHT - soldierObjectList[i]["y"].GetFloat();
			soldier->setPosition(VECTOR2(x, y));

			soldier->setBoundCollision();

			bound.left = x;
			bound.top = y;
			bound.right = bound.left + width;
			bound.bottom = bound.top - height;
			soldier->setActiveBound(bound);

			mapObjects.insert(std::pair<int, BaseObject*>(id, soldier));

			grid->add(id, soldier, x, y);
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
		timer = 0;

		listWallCanCollideCaptainAmerica->clear();

		GameRect r = Camera::getInstance()->getBound();

		auto captainAmericaPositionOnGrid = grid->calculateObjectPositionOnGrid(this->captainAmerica);
		grid->getCollidableObjects(listWallCanCollideCaptainAmerica, captainAmericaPositionOnGrid.x, captainAmericaPositionOnGrid.y);

		auto it = listWallCanCollideCaptainAmerica->find(999);
		if (it != listWallCanCollideCaptainAmerica->end())
			listWallCanCollideCaptainAmerica->erase(it);
	}

	// Handle velocity...
}

void ObjectManager::onCheckCollision(float dt)
{

	captainAmerica->setListWallCanCollide(listWallCanCollideCaptainAmerica);
	for (auto x = listWallCanCollideCaptainAmerica->begin(); x != listWallCanCollideCaptainAmerica->end(); x++)
	{
		BaseObject* object = (*x).second;

		CollisionReturn data = CollisionReturn();
		if (Collision::getInstance()->willCollide(captainAmerica, object, dt, data))
		{
			captainAmerica->getListCollide()->push_back(data);
		}
	}
	// handle on listCollide
	captainAmerica->onCollision(dt);

}

void ObjectManager::onCheckCollision(BaseObject * obj, float frametime)
{
}
