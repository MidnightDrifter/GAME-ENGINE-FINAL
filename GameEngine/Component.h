#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H
//#include "GameObject.h"
//#include "Transform.h"
//#include "Sprite.h"
//#include "Controller.h"
//#include "UpDown.h"
#include <stdio.h>
#include "Event.h"

class GameObject;

class Component
{
public:
	Component();
	Component(int t, GameObject* g);
	Component(int t);
	Component(GameObject* g);
	virtual ~Component();
	virtual void update() = 0;
	virtual void serialize(FILE** fpp);
	void setType(int i);
	int getType();

	virtual void handleEvent(Event* t) {};

	void setOwner(GameObject* i);
		GameObject * getOwner();

	


//private:
protected:
		int type;
	GameObject * owner;
};

#endif
