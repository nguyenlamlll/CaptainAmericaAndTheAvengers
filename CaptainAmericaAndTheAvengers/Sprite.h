#pragma once
#include "SpriteManager.h"
#include "TextureManager.h"

class Sprite
{
public:
protected:
	Graphics *graphics;     // pointer to graphics
	TextureManager *textureManager; // pointer to texture manager
									// spriteData contains the data required to draw the image by Graphics::drawSprite()
	SpriteManager *spriteManager;
	SpriteData spriteData;  // SpriteData is defined in "graphics.h"
	HRESULT hr;             // standard return type


public:
	Sprite();
	~Sprite();
	////////////////////////////////////////
	//           Get functions            //
	////////////////////////////////////////

	// Get Sprite Manager
	virtual SpriteManager *getSpriteManger() { return spriteManager; }

	// Return reference to SpriteData structure.
	const virtual SpriteData& getSpriteInfo() { return spriteData; }

	// Return ~ position.
	virtual float getPositionX() { return spriteData.position.x; }
	virtual float getPositionY() { return spriteData.position.y; }
	virtual VECTOR2 getPosition() { return spriteData.position; }

	// Return ~ scale
	virtual VECTOR2 getScale() { return spriteData.scale; }
	virtual float getScaleX() { return spriteData.scale.x; }
	virtual float getScaleY() { return spriteData.scale.y; }

	// Return ~ origin
	virtual VECTOR2 getOrigin() { return spriteData.origin; }

	// Return width.
	virtual int   getWidth() { return spriteData.width; }
	// Return height.
	virtual int   getHeight() { return spriteData.height; }

	// Return rotation 
	virtual float getRotate() { return spriteData.rotate; }

	// Return RECT structure of Image.
	virtual RECT  getSpriteDataRect() { return spriteData.rect; }

	// Return flip
	virtual bool getFlipX() { return spriteData.flipHorizontal; }
	virtual bool getFlipY() { return spriteData.flipVertical; }


	////////////////////////////////////////
	//           Set functions            //
	////////////////////////////////////////

	// Set data for sprite
	virtual void setData(int index);

	// Set position
	virtual void setPositionX(float newX)
	{
		if (newX == this->spriteData.position.x)
			return;

		spriteData.position.x = newX;
	}

	virtual void setPositionY(float newY)
	{
		if (newY == this->spriteData.position.y)
			return;

		spriteData.position.y = newY;
	}

	virtual void setPosition(VECTOR2 position) { spriteData.position = position; }

	// Set scale.
	virtual void setScale(VECTOR2 scale) { spriteData.scale = scale; }
	virtual void setScaleX(float x)
	{
		if (x == this->spriteData.scale.x)
			return;

		spriteData.scale.x = x;
	}

	virtual void setScaleY(float y)
	{
		if (y == this->spriteData.scale.y)
			return;

		spriteData.scale.y = y;
	}

	// Set origin
	virtual void setOrigin(VECTOR2 origin)
	{
		if (this->spriteData.origin == origin)
			return;

		spriteData.origin = origin;
	}

	virtual void setRotate(float rotate)
	{
		if (rotate == this->spriteData.rotate)
			return;

		spriteData.rotate = rotate;
	}

	// set spriteData.width
	virtual void setSpriteWidth(int width)
	{
		if (width == this->spriteData.width)
			return;

		spriteData.width = width;
	}

	// set spriteData.height
	virtual void setSpriteHeigth(int heigth)
	{
		if (heigth == this->spriteData.height)
			return;

		spriteData.height = heigth;
	}

	// Set spriteData.rect to r.
	virtual void setSpriteDataRect(RECT r) { spriteData.rect = r; }

	// Set TextureManager
	virtual void setTextureManager(TextureManager *textureM)
	{
		textureManager = textureM;
	}

	// Set Flip
	virtual void setFlipX(bool flipX) { spriteData.flipHorizontal = flipX; }
	virtual void setFlipY(bool flipY) { spriteData.flipVertical = flipY; }


	////////////////////////////////////////
	//         Other functions            //
	////////////////////////////////////////

	// Initialize Image
	// Pre: *g = pointer to Graphics object
	//      width = width of Image in pixels  (0 = use full texture width)
	//      height = height of Image in pixels (0 = use full texture height)
	//      ncols = number of columns in texture (1 to n) (0 same as 1)
	//      *textureM = pointer to TextureManager object
	virtual bool initialize(Graphics *g, TextureManager *textureM, SpriteManager* spriteM);

	// Draw Image using color as filter. Default color is WHITE.
	virtual void draw(COLOR_ARGB color = GraphicsNS::WHITE);

	// draw not transform
	virtual void draw(bool isTransform, COLOR_ARGB color = GraphicsNS::WHITE);

	// Update the animation. frameTime is used to regulate the speed.
	virtual void update(float dt);
};

