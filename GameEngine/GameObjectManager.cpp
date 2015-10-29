#include "GameObjectManager.h"



GameObjectManager::GameObjectManager()
{
	//(this->objID) = 0;
	gameObjects = (new std::vector<GameObject*>);
}


GameObjectManager::~GameObjectManager()
{
	for (int i = 0; i < gameObjects->capacity(); i++)
	{
		if (gameObjects->at(i) != NULL)
		{
			delete gameObjects->at(i);
		}
	}
	delete gameObjects;
}


GameObject* GameObjectManager::createGameObject(std::vector<Component*>* c)
{
	GameObject* temp = new GameObject(c); //(this->objID));
	//(this->objID)++;

	gameObjects->push_back(temp);
	return temp;
}


GameObject* GameObjectManager::createGameObject(Component* c)
{
	GameObject* temp = new GameObject(c);//(this->objID));
	//(this->objID)++;
	
	gameObjects->push_back(temp);
	return temp;

}

GameObject* GameObjectManager::getGameObject(int i)
{
	for (int k = gameObjects->capacity(); k >= 0; k--)
	{
		if (gameObjects->at(k) != NULL)
		{
			if (gameObjects->at(k)->getID() == i)
			{
				return gameObjects->at(k);
			}
		}
	}

	return NULL;
}


void GameObjectManager::deleteGameObject(int ID)
{
	for (int k = gameObjects->capacity(); k >= 0; k--)
	{
		if (gameObjects->at(k) != NULL)
		{
			if (gameObjects->at(k)->getID() == ID)
			{
				delete (gameObjects->at(k));
			}
		}
	}
}


GameObject * GameObjectManager::createSerializedObject(const char* filename)
{
	GameObject* p = GameObject::LoadObject(filename);

	if (p)
	{
		this->gameObjects->push_back(p);
	}

	return p;
}

