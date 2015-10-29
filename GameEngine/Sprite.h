#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "GameObject.h"
#include "..\..\SDL\include\SDL_image.h"
#include "..\..\SDL\include\SDL.h"
#include <string>
class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(std::string filename);
	Sprite(char* filename);
	~Sprite();

	void setSprite(SDL_Surface* i);
	SDL_Surface* getSprite();

private:
	SDL_Surface* image;
};

#endif