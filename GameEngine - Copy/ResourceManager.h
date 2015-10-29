#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <string>
#include "..\..\SDL\include\SDL.h"
#include <unordered_map>
#include "..\..\SDL\include\SDL_image.h"
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	SDL_Surface * loadSurface(std::string fileName);
	SDL_Surface* loadSurface(char* filename);

private:
	std::unordered_map<std::string, SDL_Surface *> mSurfaces;




};





#endif