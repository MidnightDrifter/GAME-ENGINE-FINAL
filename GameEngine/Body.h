#ifndef BODY_H
#define BODY_H
#pragma once
#include "Component.h"
#include "Vector2D.h"
class Body :
	public Component
{
public:
	Body();
	Body(float a, float b, float x, float y, float i, float j, float l, float n, float e, float f, float m);
	~Body();
	void serialize(FILE** fpp);
	void Integrate(float gravity, float dTime);
private:
	Vector2D currentPos;
	Vector2D previousPos;
	Vector2D velocity;
	Vector2D acceleration;
	Vector2D force;
	float mass, inverseMass;
};

#endif