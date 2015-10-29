#include "Sprite.h"
#include "ResourceManager.h"

extern ResourceManager ResourceMgr;
Sprite::Sprite()
{
	type = COMPONENT_TYPE_SPRITE;
	image = NULL;
}
Sprite::Sprite(char* filename)
{
	type = COMPONENT_TYPE_SPRITE;
	image = ResourceMgr.loadSurface(filename);
}



Sprite::Sprite(std::string filename)
{
	type = COMPONENT_TYPE_SPRITE;
	image = ResourceMgr.loadSurface(filename);

}


Sprite::~Sprite()
{
	
}


void Sprite::setSprite(SDL_Surface* i)
{

	image = i;
}
SDL_Surface* Sprite::getSprite()
{
	if (image != NULL)

	{
		return image;
	}
	else
	{
		return NULL;
	}

}
