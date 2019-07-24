#include "stdafx.h"
#include "Collision.h"

Collision* Collision::instance = nullptr;
Collision * Collision::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Collision();
	}
	return instance;
}

Collision::Collision()
{
}


Collision::~Collision()
{
}

bool Collision::isColliding(GameRect myRect, GameRect otherRect)
{
	if (myRect.right >= otherRect.left && 
		myRect.left <= otherRect.right &&
		myRect.bottom <= otherRect.top &&
		myRect.top >= otherRect.bottom)
	{
		return true;
	}
	return false;
}

bool Collision::willCollide(BaseObject * myObj, BaseObject * otherObj, float dt)
{
	float _dxEntry, _dyEntry, _dxExit, _dyExit;
	float _txEntry, _tyEntry, _txExit, _tyExit;
	GameRect   myRect = myObj->getBoundCollision();
	GameRect   otherRect = otherObj->getBoundCollision();
	CollisionReturn data;

	GameRect   broadphaseOtherRect = getSweptBroadphaseRect(otherObj, dt);	// là bound của object được mở rộng ra thêm một phần bằng với vận tốc (dự đoán trước bound)
	GameRect   broadphaseMyRect = getSweptBroadphaseRect(myObj, dt);	// là bound của object được mở rộng ra thêm một phần bằng với vận tốc (dự đoán trước bound)
	if (!isColliding(broadphaseMyRect, broadphaseOtherRect))				// kiểm tra tính chồng lắp của 2 hcn
	{
		return false;
	}

	//velocity of each frame
	VECTOR2 otherVeloc = VECTOR2(otherObj->getVelocity().x * dt, otherObj->getVelocity().y * dt);
	VECTOR2 myVelocity = VECTOR2(myObj->getVelocity().x * dt, myObj->getVelocity().y * dt);

	VECTOR2 velocity = myVelocity;

	if (otherVeloc != VECTOR2(0, 0))
	{
		if (myObj->getVelocity().y == -CAPTAIN_MIN_SPEED_Y)
			myVelocity.y = 0;

		velocity = myVelocity - otherVeloc;
	}

	// tìm khoảng cách giữa cạnh gần nhất, xa nhất 2 object dx, dy
	// dx
	if (velocity.x > 0.0f)
	{
		_dxEntry = otherRect.left - myRect.right;
		_dxExit = otherRect.right - myRect.left;
	}
	else
	{
		_dxEntry = otherRect.right - myRect.left;
		_dxExit = otherRect.left - myRect.right;
	}

	// dy
	if (velocity.y < 0.0f)
	{
		_dyEntry = otherRect.top - myRect.bottom;
		_dyExit = otherRect.bottom - myRect.top;
	}
	else
	{
		_dyEntry = otherRect.bottom - myRect.top;
		_dyExit = otherRect.top - myRect.bottom;
	}

	// tìm thời gian va chạm 
	if (velocity.x == 0)
	{
		// chia cho 0 ra vô cực
		_txEntry = -std::numeric_limits<float>::infinity();
		_txExit = std::numeric_limits<float>::infinity();
	}

	else
	{
		_txEntry = _dxEntry / velocity.x;
		_txExit = _dxExit / velocity.x;
	}

	if (velocity.y == 0)
	{
		_tyEntry = -std::numeric_limits<float>::infinity();
		_tyExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		_tyEntry = _dyEntry / velocity.y;
		_tyExit = _dyExit / velocity.y;
	}

	// thời gian va chạm
	// va chạm khi x và y CÙNG chạm => thời gian va chạm trễ nhất giữa x và y
	float entryTime = max(_txEntry, _tyEntry);
	// hết va chạm là 1 trong 2 x, y hết va chạm => thời gian sớm nhất để kết thúc va chạm
	float exitTime = min(_txExit, _tyExit);

	// object không va chạm khi:
	// nếu thời gian bắt đầu va chạm hơn thời gian kết thúc va chạm
	// thời gian va chạm x, y nhỏ hơn 0 (chạy qua luôn, 2 thằng đang đi xa ra nhau)
	// thời gian va chạm x, y lớn hơn 1 (còn xa quá chưa thể va chạm)
	if (entryTime > exitTime || _txEntry < 0.0f && _tyEntry < 0.0f || _txEntry > 1.0f || _tyEntry > 1.0f)
	{
		return false;
	}
	// nếu thời gian va chạm x lơn hơn y
	if (_txEntry > _tyEntry)
	{
		// xét x
		// khoảng cách gần nhất mà nhỏ hơn 0 nghĩa là thằng kia đang nằm bên trái object này => va chạm bên phải nó

		if (_dxEntry < 0.0f)
		{
			data.direction = CollideDirection::RIGHT;
		}
		else
		{

			data.direction = CollideDirection::LEFT;

		}
	}
	else
	{
		// xét y
		if (_dyEntry < 0.0f)
		{
			data.direction = CollideDirection::TOP;

		}
		else
		{
			data.direction = CollideDirection::BOTTOM;
		}
	}

	if (0 < entryTime&& entryTime < 1.0f)
	{
		data.entryTime = entryTime;
		data.object = otherObj;
		switch (data.direction)
		{
		case TOP:
			data.positionCollision = otherRect.top;
			break;
		case BOTTOM:
			data.positionCollision = otherRect.bottom;
			break;
		case LEFT:
			data.positionCollision = otherRect.left;
			break;
		case RIGHT:
			data.positionCollision = otherRect.right;
			break;
		}

		//switch (myEntity->getId())
		//{
		//case eID::SAMUS:
		//{
		//	Samus* samus = static_cast<Samus*>(myEntity);
		//	samus->getListCollide()->push_back(data);
		//	break;
		//}
		//case eID::BULLET:
		//{
		//	Bullet* bullet = static_cast<Bullet*>(myEntity);
		//	bullet->getListCollide()->push_back(data);
		//	break;
		//}
		//case eID::ROCKET:
		//{
		//	Rocket* rocket = static_cast<Rocket*>(myEntity);
		//	rocket->getListCollide()->push_back(data);
		//	break;
		//}
		//case eID::ZOMMER:
		//{
		//	Zommer* zommer = static_cast<Zommer*>(myEntity);
		//	zommer->getListCollide()->push_back(data);
		//	break;
		//}
		//case eID::RIPPER:
		//{
		//	Ripper* ripper = static_cast<Ripper*>(myEntity);
		//	ripper->getListCollide()->push_back(data);
		//	break;
		//}
		//case eID::SKREE:
		//{
		//	Skree* skree = static_cast<Skree*>(myEntity);
		//	skree->getListCollide()->push_back(data);
		//	break;
		//}
		//case eID::WAVER:
		//{
		//	Waver* waver = static_cast<Waver*>(myEntity);
		//	waver->getListCollide()->push_back(data);

		//	break;
		//}
		//case eID::BOSSKRAID:
		//{
		//	BossKraid* bossKraid = static_cast<BossKraid*>(myEntity);
		//	bossKraid->getListCollide()->push_back(data);

		//	break;
		//}
		//case eID::BOSSKRAID_ROCKET:
		//{
		//	BossKraidRocket* bossKraid = static_cast<BossKraidRocket*>(myEntity);
		//	bossKraid->getListCollide()->push_back(data);

		//	break;
		//}
		//case eID::CANON_BULLET:
		//{
		//	CanonBullet* canonBullet = static_cast<CanonBullet*>(myEntity);
		//	canonBullet->getListCollide()->push_back(data);

		//	break;
		//}
		//default:
		//	break;
		//}

		return true;
	}
	return false;
}

bool Collision::willCollide(BaseObject * myObj, BaseObject * otherObj, float dt, CollisionReturn& result)
{
	float _dxEntry, _dyEntry, _dxExit, _dyExit;
	float _txEntry, _tyEntry, _txExit, _tyExit;
	GameRect   myRect = myObj->getBoundCollision();
	GameRect   otherRect = otherObj->getBoundCollision();

	GameRect   broadphaseOtherRect = getSweptBroadphaseRect(otherObj, dt);	// là bound của object được mở rộng ra thêm một phần bằng với vận tốc (dự đoán trước bound)
	GameRect   broadphaseMyRect = getSweptBroadphaseRect(myObj, dt);	// là bound của object được mở rộng ra thêm một phần bằng với vận tốc (dự đoán trước bound)
	if (!isColliding(broadphaseMyRect, broadphaseOtherRect))				// kiểm tra tính chồng lắp của 2 hcn
	{
		return false;
	}

	//velocity of each frame
	VECTOR2 otherVeloc = VECTOR2(otherObj->getVelocity().x * dt, otherObj->getVelocity().y * dt);
	VECTOR2 myVelocity = VECTOR2(myObj->getVelocity().x * dt, myObj->getVelocity().y * dt);

	VECTOR2 velocity = myVelocity;

	if (otherVeloc != VECTOR2(0, 0))
	{
		if (myObj->getVelocity().y == -CAPTAIN_MIN_SPEED_Y)
			myVelocity.y = 0;

		velocity = myVelocity - otherVeloc;
	}

	// tìm khoảng cách giữa cạnh gần nhất, xa nhất 2 object dx, dy
	// dx
	if (velocity.x > 0.0f)
	{
		_dxEntry = otherRect.left - myRect.right;
		_dxExit = otherRect.right - myRect.left;
	}
	else
	{
		_dxEntry = otherRect.right - myRect.left;
		_dxExit = otherRect.left - myRect.right;
	}

	// dy
	if (velocity.y < 0.0f)
	{
		_dyEntry = otherRect.top - myRect.bottom;
		_dyExit = otherRect.bottom - myRect.top;
	}
	else
	{
		_dyEntry = otherRect.bottom - myRect.top;
		_dyExit = otherRect.top - myRect.bottom;
	}

	// tìm thời gian va chạm 
	if (velocity.x == 0)
	{
		// chia cho 0 ra vô cực
		_txEntry = -std::numeric_limits<float>::infinity();
		_txExit = std::numeric_limits<float>::infinity();
	}

	else
	{
		_txEntry = _dxEntry / velocity.x;
		_txExit = _dxExit / velocity.x;
	}

	if (velocity.y == 0)
	{
		_tyEntry = -std::numeric_limits<float>::infinity();
		_tyExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		_tyEntry = _dyEntry / velocity.y;
		_tyExit = _dyExit / velocity.y;
	}

	// thời gian va chạm
	// va chạm khi x và y CÙNG chạm => thời gian va chạm trễ nhất giữa x và y
	float entryTime = max(_txEntry, _tyEntry);
	// hết va chạm là 1 trong 2 x, y hết va chạm => thời gian sớm nhất để kết thúc va chạm
	float exitTime = min(_txExit, _tyExit);

	// object không va chạm khi:
	// nếu thời gian bắt đầu va chạm hơn thời gian kết thúc va chạm
	// thời gian va chạm x, y nhỏ hơn 0 (chạy qua luôn, 2 thằng đang đi xa ra nhau)
	// thời gian va chạm x, y lớn hơn 1 (còn xa quá chưa thể va chạm)
	if (entryTime > exitTime || _txEntry < 0.0f && _tyEntry < 0.0f || _txEntry > 1.0f || _tyEntry > 1.0f)
	{
		return false;
	}

	// nếu thời gian va chạm x lơn hơn y
	if (_txEntry > _tyEntry)
	{
		// xét x
		// khoảng cách gần nhất mà nhỏ hơn 0 nghĩa là thằng kia đang nằm bên trái object này => va chạm bên phải nó

		if (_dxEntry < 0.0f)
		{
			result.direction = CollideDirection::RIGHT;
		}
		else
		{

			result.direction = CollideDirection::LEFT;

		}
	}
	else
	{
		// xét y
		if (_dyEntry < 0.0f)
		{
			result.direction = CollideDirection::TOP;

		}
		else
		{
			result.direction = CollideDirection::BOTTOM;
		}
	}

	if (0 < entryTime&& entryTime < 1.0f)
	{
		result.entryTime = entryTime;
		result.object = otherObj;
		switch (result.direction)
		{
		case TOP:
			result.positionCollision = otherRect.top;
			break;
		case BOTTOM:
			result.positionCollision = otherRect.bottom;
			break;
		case LEFT:
			result.positionCollision = otherRect.left;
			break;
		case RIGHT:
			result.positionCollision = otherRect.right;
			break;
		}

		return true;
	}
	return false;
}

GameRect Collision::getSweptBroadphaseRect(BaseObject* obj, float frametime)
{
	VECTOR2 distance = VECTOR2(obj->getVelocity().x * frametime, obj->getVelocity().y * frametime);
	GameRect myRect = obj->getBoundCollision();

	GameRect rect;
	rect.top = distance.y > 0 ? myRect.top + distance.y : myRect.top;
	rect.bottom = distance.y > 0 ? myRect.bottom : myRect.bottom + distance.y;
	rect.left = distance.x > 0 ? myRect.left : myRect.left + distance.x;
	rect.right = distance.x > 0 ? myRect.right + distance.x : myRect.right;

	return rect;
}

void Collision::release()
{
	delete instance;
}
