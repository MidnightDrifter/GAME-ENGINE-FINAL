#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "Component.h"
#include <stdio.h>

//#include "Transform.h"
//#include "Sprite.h"
//#include "UpDown.h"
//#include "Controller.h"

//class Component;
//class UpDown;
//class Sprite;
//class Transform;
//class Controller;

#define NUMBER_OF_COMPONENTS 4

enum COMPONENT_TYPE
{
	COMPONENT_TYPE_TRANSFORM,
	COMPONENT_TYPE_SPRITE,
	COMPONENT_TYPE_CONTROLLER,
	COMPONENT_TYPE_UPDOWN
};



class GameObject
{
public:
	GameObject();
	GameObject(Component* i);
	GameObject(Component* i, int ID);
	GameObject(std::vector<Component*> * i);
	GameObject(std::vector<Component*> * i, int ID);
	virtual ~GameObject();


	void addComponent(Component* i);
	Component* getComponent(int type);

	void setComponentVector(std::vector <Component*> i);
	std::vector <Component*> * getComponentVector();

	Component* getUpDown();
	Component* getTransform();
	Component* getSprite();
	Component* getController();

	int getID();
	void setID(int i);

	void update();

	static void initializeCounter(int x);
	void incrementCounter();
	void decrementCounter();
	static void initializeCounter();
	int getCounter();


	/*UpDown* getUpDown(void);
	Transform* getTransform(void);
	Sprite* getSprite(void);
	Controller* getController(void);

	*/

	static GameObject* LoadObject(const char* filename);

private:
	std::vector<Component *> * components;
	int objectID;
	static int GameObject::IDcounter;
	//std::vector<Component*>::iterator t;
};




/*
class Component
{
public:
	Component();
	Component(int t, GameObject* g);
	Component(int t);
	Component(GameObject* g);
	virtual ~Component();

	void setType(int i);
	int getType();

	void setOwner(GameObject* i);
	GameObject * getOwner();


	//private:
protected:
	int type;
	GameObject * owner;
};
*/

#endif

