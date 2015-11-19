#include "Sprite.h"
#include "ResourceManager.h"
#include <stdio.h>
#include <string>

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

void Sprite::serialize(FILE** fpp)
{/*
	char componentName[256];
	memset(componentName, 0, 256 * sizeof(char));
	fscanf_s(fp, "%255s\n", componentName, sizeof(componentName));
	*/

	char s[256];
	memset(s, 0, 256 * sizeof(char));
	fscanf_s(*fpp, "%255s\n", s, sizeof(s));
	this->setSprite(ResourceMgr.loadSurface(s));


}

void Sprite::update()
{

}
