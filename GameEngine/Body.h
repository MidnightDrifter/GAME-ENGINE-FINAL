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

	Vector2D getCurrentPos() const;
	Vector2D getPreviousPos() const;
	Vector2D getVelocity() const;
	Vector2D getAcceleration() const;
	Vector2D getForce() const;
	float getMass() const;
	float getInverseMass() const;
	void setCurrentPos(Vector2D x);
	void setPreviousPos(Vector2D x);
	void setVelocity(Vector2D x);
	void setAcceleration(Vector2D x);
	void setForce(Vector2D x);
	void setMass(float x);
	void setCurrentPos(float x, float y);
	void setPreviousPos(float x, float y);
	void setVelocity(float x, float y);
	void setAcceleration(float x, float y);
	void setForce(float x, float y);
	void update();


private:
	Vector2D currentPos;
	Vector2D previousPos;
	Vector2D velocity;
	Vector2D acceleration;
	Vector2D force;
	float mass, inverseMass;
};

#endif