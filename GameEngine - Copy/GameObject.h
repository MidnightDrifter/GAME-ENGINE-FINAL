#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "Component.h"
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
	GameObject(std::vector<Component*> * i);
	virtual ~GameObject();


	void addComponent(Component* i);
	Component* getComponent(int type);

	void setComponentVector(std::vector <Component*> i);
	std::vector <Component*> * getComponentVector();

	Component* getUpDown();
	Component* getTransform();
	Component* getSprite();
	Component* getController();

	void update();


	/*UpDown* getUpDown(void);
	Transform* getTransform(void);
	Sprite* getSprite(void);
	Controller* getController(void);

	*/


private:
	std::vector<Component *> * components;
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

