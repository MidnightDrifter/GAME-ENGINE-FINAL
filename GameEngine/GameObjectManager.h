#pragma once
#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "GameObject.h"
#include <vector>


#define STARTING_OBJECT_NUMBER 0


class GameObjectManager
{
	friend class PhysicsManager;
	friend class EventManager;
public:
	GameObjectManager();
	~GameObjectManager();

	GameObject* createGameObject(std::vector<Component*>* c);
	GameObject* createGameObject(Component* c);

	GameObject* getGameObject(int i);
	void deleteGameObject(int ID);

	GameObject* createSerializedObject(const char* filename);

	void pushGameObject(GameObject* g);

private:

	//static int objID;
	std::vector<GameObject*> * gameObjects;


};

#endif