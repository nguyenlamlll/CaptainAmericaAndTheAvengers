#include "stdafx.h"
#include "Graphics.h"
//#include "Metroid.h"
#include "Camera.h"
#include "ObjectManager.h"

Graphics::Graphics()
{
	direct3d = NULL;
	device3d = NULL;
	sprite = NULL;
	fullscreen = false;
	width = VIEWPORT_WIDTH;    // width & height are replaced in initialize()
	height = VIEWPORT_HEIGHT;
	backColor = GraphicsNS::BLACK;
}


Graphics::~Graphics()
{
	releaseAll();
}



void Graphics::releaseAll()
{
	SAFE_RELEASE(sprite);
	SAFE_RELEASE(device3d);
	SAFE_RELEASE(direct3d);
}


void Graphics::initialize(HWND hw, int w, int h, bool full)
{
	hwnd = hw;
	width = w;
	height = h;
	fullscreen = full;

	//initialize Direct3D
	direct3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (direct3d == NULL)
		throw(GameError(GameErrorNS::FATAL_ERROR, "Error initializing Direct3D"));

	initD3Dpp();        // init D3D presentation parameters
	if (fullscreen)      // if full-screen mode
	{
		if (isAdapterCompatible())   // is the adapter compatible
									 // set the refresh rate with a compatible one
			d3dpp.FullScreen_RefreshRateInHz = pMode.RefreshRate;
		else
			throw(GameError(GameErrorNS::FATAL_ERROR,
				"The graphics device does not support the specified resolution and/or format."));
	}

	// determine if graphics card supports harware texturing and lighting and vertex shaders
	D3DCAPS9 caps;
	DWORD behavior;
	result = direct3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
	// If device doesn't support HW T&L or doesn't support 1.1 vertex 
	// shaders in hardware, then switch to software vertex processing.
	if ((caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) == 0 ||
		caps.VertexShaderVersion < D3DVS_VERSION(1, 1))
		behavior = D3DCREATE_SOFTWARE_VERTEXPROCESSING;  // use software only processing
	else
		behavior = D3DCREATE_HARDWARE_VERTEXPROCESSING;  // use hardware only processing

														 //create Direct3D device
	result = direct3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		behavior,
		&d3dpp,
		&device3d);

	if (FAILED(result))
		throw(GameError(GameErrorNS::FATAL_ERROR, "Error creating Direct3D device"));

	result = D3DXCreateSprite(device3d, &sprite);
	if (FAILED(result))
		throw(GameError(GameErrorNS::FATAL_ERROR, "Error creating Direct3D sprite"));

	result = D3DXCreateLine(device3d, &line);
	if (FAILED(result))
		throw(GameError(GameErrorNS::FATAL_ERROR, "Error creating Direct3D line"));
	line->SetWidth(2.0f);
}

void Graphics::initD3Dpp()
{
	try {
		ZeroMemory(&d3dpp, sizeof(d3dpp));              // fill the structure with 0
														// fill in the parameters we need
		d3dpp.BackBufferWidth = width;
		d3dpp.BackBufferHeight = height;
		if (fullscreen)                                  // if fullscreen
			d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;  // 24 bit color
		else
			d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;   // use desktop setting
		d3dpp.BackBufferCount = 1;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.hDeviceWindow = hwnd;
		d3dpp.Windowed = (!fullscreen);
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	}
	catch (...)
	{
		throw(GameError(GameErrorNS::FATAL_ERROR,
			"Error initializing D3D presentation parameters"));
	}
}




HRESULT Graphics::loadTexture(const char *filename, COLOR_ARGB transcolor,
	UINT &width, UINT &height, LP_TEXTURE &texture)
{
	// The struct for reading file info
	D3DXIMAGE_INFO info;
	result = E_FAIL;

	try {
		if (filename == NULL)
		{
			texture = NULL;
			return D3DERR_INVALIDCALL;
		}
		// Get width and height from file
		result = D3DXGetImageInfoFromFile(filename, &info);
		if (result != D3D_OK)
			return result;
		if (width == 0)
			width = info.Width;
		if (height == 0)
			height = info.Height;

		// Create the new texture by loading from file
		result = D3DXCreateTextureFromFileEx(
			device3d,           //3D device
			filename,           //image filename
			width,         //texture width
			height,        //texture height
			1,                  //mip-map levels (1 for no chain)
			0,                  //usage
			D3DFMT_UNKNOWN,     //surface format (default)
			D3DPOOL_DEFAULT,    //memory class for the texture
			D3DX_DEFAULT,       //image filter
			D3DX_DEFAULT,       //mip filter
			transcolor,         //color key for transparency
			&info,              //bitmap file info (from loaded file)
			NULL,               //color palette
			&texture);         //destination texture

	}
	catch (...)
	{
		throw(GameError(GameErrorNS::FATAL_ERROR, "Error in Graphics::loadTexture"));
	}
	return result;
}

ID3DXFont * Graphics::loadDirectXFont(std::string fontName, int fontHeight, bool isItalic)
{
	ID3DXFont* font = nullptr;

	D3DXCreateFont(
		device3d,
		fontHeight,
		0,
		FW_NORMAL,
		1,
		isItalic,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY,
		FF_DONTCARE,
		fontName.c_str(),
		&font
	);

	return font;
}

void Graphics::drawText(ID3DXFont* font, std::string text, VECTOR2 position, DWORD format, D3DCOLOR color)
{
	RECT rect;
	SetRect(&rect, (int)position.x, (int)position.y, (int)position.x, (int)position.y);

	font->DrawText(NULL,        //pSprite

		text.c_str(),  //pString

		-1,          //Count

		&rect,  //pRect

		format, //Format single line

		color); //Color
}


HRESULT Graphics::showBackbuffer()
{
	result = E_FAIL;    // default to fail, replace on success
						// Display backbuffer to screen
	result = device3d->Present(NULL, NULL, NULL, NULL);
	return result;
}

//=============================================================================
// Checks the adapter to see if it is compatible with the BackBuffer height,
// width and refresh rate specified in d3dpp. Fills in the pMode structure with
// the format of the compatible mode, if found.
// Pre: d3dpp is initialized.
// Post: Returns true if compatible mode found and pMode structure is filled.
//       Returns false if no compatible mode found.
//=============================================================================
bool Graphics::isAdapterCompatible()
{
	UINT modes = direct3d->GetAdapterModeCount(D3DADAPTER_DEFAULT,
		d3dpp.BackBufferFormat);
	for (UINT i = 0; i < modes; i++)
	{
		result = direct3d->EnumAdapterModes(D3DADAPTER_DEFAULT,
			d3dpp.BackBufferFormat,
			i, &pMode);
		if (pMode.Height == d3dpp.BackBufferHeight &&
			pMode.Width == d3dpp.BackBufferWidth &&
			pMode.RefreshRate >= d3dpp.FullScreen_RefreshRateInHz)
			return true;
	}
	return false;
}


void Graphics::clear(COLOR_ARGB c)
{
	device3d->Clear(0, NULL, D3DCLEAR_TARGET, c, 1.0F, 0);
}


void Graphics::drawSprite(const SpriteData &spriteData, COLOR_ARGB color)
{
	if (spriteData.texture == NULL)      // if no texture
		return;

	D3DXMATRIX matTransformed;
	D3DXMATRIX matOld;


	//calculate scale position
	VECTOR3 center = VECTOR3(spriteData.width * spriteData.origin.x, spriteData.height * spriteData.origin.y, 0);

	VECTOR2 position(spriteData.position.x, spriteData.position.y);
	VECTOR2 scale(spriteData.scale.x, 1.0f);

	//calculate position when scale
	if (spriteData.flipHorizontal == true)
	{
		scale.x = spriteData.scale.x*-1;
		if (spriteData.origin.x == 0.5f)
		{
			position.x = spriteData.position.x;
		}
		if (spriteData.origin.x == 0)
		{
			position.x = spriteData.position.x + spriteData.width;
		}
		if (spriteData.origin.x == 1.0f)
		{
			position.x = spriteData.position.x - spriteData.width;
		}
		if (spriteData.origin.x != 0.5&&spriteData.origin.x != 0 && spriteData.origin.x != 1.0f)
		{
			position.x = spriteData.position.x + (spriteData.width - spriteData.origin.x*spriteData.width);
		}
	}

	D3DXMATRIX mt;
	D3DXVECTOR4 posViewport;

	D3DXMatrixIdentity(&mt);
	mt._22 = -1.0f;
	mt._41 = (float)(-1) * Camera::getInstance()->getBound().left;
	mt._42 = (float)Camera::getInstance()->getBound().top;

	D3DXVec3Transform(&posViewport, &VECTOR3(position.x, position.y, 0), &mt);

	sprite->GetTransform(&matOld);

	D3DXMatrixTransformation2D(
		&matTransformed,
		&VECTOR2(posViewport.x, posViewport.y),
		0.0f,
		&scale,
		&VECTOR2(posViewport.x, posViewport.y),
		D3DXToRadian(spriteData.rotate),
		0
	);

	//set matrix transformed
	sprite->SetTransform(&matTransformed);

	// Draw the sprite
	sprite->Draw(spriteData.texture, &spriteData.rect, &center, &VECTOR3(posViewport.x, posViewport.y, 0), color);

	// Magic... TO use only this sprite or you can know as to refesh to old
	sprite->SetTransform(&matOld);

	ObjectManager::getInstance()->setTotalObjectsPerFrame(ObjectManager::getInstance()->getTotalObjectsPerFrame() + 1);
}

void Graphics::drawSprite(bool isTransform, const SpriteData & spriteData, COLOR_ARGB color)
{
	if (isTransform)
	{
		this->drawSprite(spriteData, color);
	}
	else
	{
		if (spriteData.texture == NULL)      // if no texture
			return;

		D3DXMATRIX matTransformed;

		//calculate scale position
		VECTOR3 center = VECTOR3(spriteData.width * spriteData.origin.x, spriteData.height * spriteData.origin.y, 0);


		D3DXMatrixTransformation2D(
			&matTransformed,
			&spriteData.position,
			0.0f,
			&spriteData.scale,
			&spriteData.position,
			D3DXToRadian(spriteData.rotate),
			0
		);

		//set matrix transformed
		sprite->SetTransform(&matTransformed);

		// Draw the sprite
		sprite->Draw(spriteData.texture, &spriteData.rect, &center, &VECTOR3(spriteData.position.x, spriteData.position.y, 0), color);
	}
}

void Graphics::drawLine(const VECTOR3* vertices, int count, COLOR_ARGB color)
{
	// Transform Camera
	VECTOR2 trans = VECTOR2(Camera::getInstance()->getWidth()*0.5f - Camera::getInstance()->getPosition().x, Camera::getInstance()->getHeight()*0.5f - Camera::getInstance()->getPosition().y);
	D3DXMATRIX mt;
	D3DXMatrixTransformation2D(&mt, 0, 0, 0, 0, 0, &trans);

	line->Begin();
	line->DrawTransform(vertices, count, &mt, color);
	line->End();
}

HRESULT Graphics::getDeviceState()
{
	result = E_FAIL;    // default to fail, replace on success
	if (device3d == NULL)
		return  result;
	result = device3d->TestCooperativeLevel();
	return result;
}


HRESULT Graphics::reset()
{
	result = E_FAIL;    // default to fail, replace on success
	initD3Dpp();                        // init D3D presentation parameters
	sprite->OnLostDevice();
	result = device3d->Reset(&d3dpp);   // attempt to reset graphics device

	sprite->OnResetDevice();
	return result;
}

