#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include "GameObject.h"
#include <stdio.h>

class Transform :
	public Component
{

	friend class Controller;

public:
	Transform() : posX(0), posY(0) {}
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
	void serialize(FILE** fpp);
protected:
	int posX;
	int posY;

	//int posZ;
};

#endif