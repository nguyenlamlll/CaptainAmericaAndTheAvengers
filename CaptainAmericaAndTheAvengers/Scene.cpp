#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
}

Scene::Scene(Graphics * graphics, Input * input)
{
	this->graphics = graphics;
	this->input = input;
}

void Scene::init()
{
}

void Scene::update()
{
}

void Scene::draw()
{
}

void Scene::run()
{

}
void Scene::release()
{
}
void Scene::handleLostGraphicsDevice()
{
	// test for and handle lost device
	HRESULT hr = graphics->getDeviceState();
	if (FAILED(hr))                  // if graphics device is not in a valid state
	{
		// if the device is lost and not available for reset
		if (hr == D3DERR_DEVICELOST)
		{
			Sleep(100);             // yield cpu time (100 mili-seconds)
			return;
		}
		// the device was lost but is now available for reset
		else if (hr == D3DERR_DEVICENOTRESET)
		{
			//del();
			hr = graphics->reset(); // attempt to reset graphics device
			if (FAILED(hr))          // if reset failed
				return;
			//resetAll();
		}
		else
			return;                 // other device error
	}
}


Scene::~Scene()
{
}
