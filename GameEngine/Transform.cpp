#include "Transform.h"
#include <stdio.h>



Transform::Transform(int x, int y)
{
	type = COMPONENT_TYPE_TRANSFORM;
	posX = x;
	posY = y;
}


int Transform::getX()
{
	return posX;
}

int Transform::getY()
{
	return posY;

}

void Transform::setX(int x)
{
	posX = x;

}

void Transform::setY(int y)
{

	posY = y;
}

void Transform::addToX(int x)
{
	setX(x + getX());

}

void Transform::addToY(int y)
{
	setY(y + getY());

}
void Transform::subToX(int x)
{
	setX(getX()-x);

}
void Transform::subToY(int y)
{
	setY(getY()-y);

}


Transform::~Transform()
{
}


void Transform::serialize(FILE** fpp)
{
	float x = 0;
	float y = 0;
	fscanf_s(*fpp, "%f %f\n", x, y);
	this->setX(x);
	this->setY(y);
}