#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H
//#include "GameObject.h"
//#include "Transform.h"
//#include "Sprite.h"
//#include "Controller.h"
//#include "UpDown.h"
#include <stdio.h>

class GameObject;

class Component
{
public:
	Component();
	Component(int t, GameObject* g);
	Component(int t);
	Component(GameObject* g);
	virtual ~Component();
	virtual void update();
	virtual void serialize(FILE** fpp);
	void setType(int i);
	int getType();

	void setOwner(GameObject* i);
		GameObject * getOwner();

	


//private:
protected:
		int type;
	GameObject * owner;
};

#endif
