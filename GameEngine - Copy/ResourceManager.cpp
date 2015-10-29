#include "ResourceManager.h"

ResourceManager::ResourceManager()
{}

ResourceManager::~ResourceManager()
{
	for (auto i : mSurfaces)
	{
		SDL_FreeSurface((i.second));
	}

	mSurfaces.clear();
}



SDL_Surface * ResourceManager::loadSurface(char* fileName)
{
	SDL_Surface *pSurface = mSurfaces[fileName];

	if (pSurface != NULL)
	{
		return pSurface;
	}


	pSurface = IMG_Load(fileName);

	if (pSurface != NULL)
	{
		mSurfaces[fileName];
	}

	return pSurface;
}



SDL_Surface * ResourceManager::loadSurface(std::string fileName)
{
	SDL_Surface *pSurface = mSurfaces[fileName.c_str()];

	if(pSurface != NULL)
	{
		return pSurface;
	}


	pSurface = IMG_Load(fileName.c_str());

	if(pSurface!=NULL)
	{
		mSurfaces[fileName.c_str()];
	}

	return pSurface;
}