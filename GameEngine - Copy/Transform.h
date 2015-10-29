#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include "GameObject.h"
class Transform :
	public Component
{

	friend class Controller;

public:
	Transform(int x, int y);
	~Transform();
	
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void addToX(int x);
	void addToY(int y);
	void subToX(int x);
	void subToY(int y);

protected:
	int posX;
	int posY;

	//int posZ;
};

#endif